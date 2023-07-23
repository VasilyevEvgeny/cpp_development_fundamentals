#include <sstream>
#include <cstdint>
#include <variant>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <optional>

namespace Svg {

    struct Point {
        double x{0};
        double y{0};
    };

    struct Rgb {
        std::uint8_t red;
        std::uint8_t green;
        std::uint8_t blue;
    };

    struct Rgba {
        std::uint8_t red;
        std::uint8_t green;
        std::uint8_t blue;
        double alpha;
    };

    using Color = std::variant<std::monostate, Rgb, Rgba, std::string>;
    const Color NoneColor{};

    void RenderColor(std::ostream& out, std::monostate);
    void RenderColor(std::ostream& out, const Rgb& rgb);
    void RenderColor(std::ostream& out, const Rgba& rgb);
    void RenderColor(std::ostream& out, const std::string& name);
    void RenderColor(std::ostream& out, const Color& color);

    class Shape {
    public:
        virtual void Render(std::ostream& out) const = 0;
        virtual ~Shape() = default;
    };

    template <typename Owner>
    class ShapeProperties {
    public:
        Owner& SetFillColor(const Color& fill);
        Owner& SetStrokeColor(const Color& stroke);
        Owner& SetStrokeWidth(double stroke_width);
        Owner& SetStrokeLineCap(const std::string& stroke_linecap);
        Owner& SetStrokeLineJoin(const std::string& stroke_linejoin);
        Owner& SetOuterMargin(double outer_margin);

        Owner& AsOwner();

        void RenderProperties(std::ostream& out) const;

    private:
        Color fill_{NoneColor};
        Color stroke_{NoneColor};
        double stroke_width_{1.0};
        std::optional<std::string> stroke_linecap_;
        std::optional<std::string> stroke_linejoin_;
    };

    template <typename Owner>
    Owner& ShapeProperties<Owner>::SetFillColor(const Color& fill) {
        fill_ = fill;
        return AsOwner();
    }

    template <typename Owner>
    Owner& ShapeProperties<Owner>::SetStrokeColor(const Color& stroke) {
        stroke_ = stroke;
        return AsOwner();
    }

    template <typename Owner>
    Owner& ShapeProperties<Owner>::SetStrokeWidth(double stroke_width) {
        stroke_width_ = stroke_width;
        return AsOwner();
    }

    template <typename Owner>
    Owner& ShapeProperties<Owner>::SetStrokeLineCap(const std::string& stroke_linecap) {
        stroke_linecap_ = stroke_linecap;
        return AsOwner();
    }

    template <typename Owner>
    Owner& ShapeProperties<Owner>::SetStrokeLineJoin(const std::string& stroke_linejoin) {
        stroke_linejoin_ = stroke_linejoin;
        return AsOwner();
    }

    template <typename Owner>
    Owner& ShapeProperties<Owner>::AsOwner() {
        return static_cast<Owner&>(*this);
    }

    template <typename Owner>
    void ShapeProperties<Owner>::RenderProperties(std::ostream& out) const {
        out << "fill" << "=" << "\"";
        RenderColor(out, fill_);
        out << "\"";

        out << " " << "stroke" << "=" << "\"";
        RenderColor(out, stroke_);
        out << "\"";

        out << " " << "stroke-width" << "=" << "\"" << stroke_width_ << "\"";

        if (stroke_linecap_) {
            out << " " << "stroke-linecap" << "=" << "\"" << stroke_linecap_.value() << "\"";
        }

        if (stroke_linejoin_) {
            out << " " << "stroke-linejoin" << "=" << "\"" << stroke_linejoin_.value() << "\"";
        }
    }

    class Rectangle : public Shape, public ShapeProperties<Rectangle> {
    public:
        Rectangle& SetBasePoint(Point p);
        Rectangle& SetWidth(double w);
        Rectangle& SetHeight(double h);

        void Render(std::ostream& out) const;
    private:
        Point base_point_{0.0, 0.0};
        double w_{1.0};
        double h_{1.0};
    };

    class Circle : public Shape, public ShapeProperties<Circle> {
    public:
        Circle& SetCenter(Point center);
        Circle& SetRadius(double r);

        void Render(std::ostream& out) const;
    private:
        Point center_{0.0, 0.0};
        double r_{1.0};
    };

    class Polyline : public Shape, public ShapeProperties<Polyline> {
    public:
        Polyline& AddPoint(Point point);
        void Render(std::ostream& out) const;
    private:
        std::vector<Point> points_;
    };

    class Text : public Shape, public ShapeProperties<Text> {
    public:
        Text& SetPoint(Point coordinates);
        Text& SetOffset(Point offset);
        Text& SetFontSize(uint32_t font_size);
        Text& SetFontFamily(const std::string& font_family);
        Text& SetFontWeight(const std::string& font_weight);
        Text& SetData(const std::string& data);

        void Render(std::ostream& out) const;
    private:
        Point coordinates_;
        Point offset_;
        uint32_t font_size_;
        std::optional<std::string> font_family_;
        std::optional<std::string> font_weight_;
        std::string data_;
    };

    class Document {
    public:
        explicit Document() {}

        template <typename ShapeType>
        void Add(ShapeType shape);

        void Render(std::ostream& out) const;
        std::string ToString() const;
    private:
        std::vector<std::unique_ptr<Shape>> shapes_;
    };

    template <typename ShapeType>
    void Document::Add(ShapeType shape) {
        shapes_.push_back(std::make_unique<ShapeType>(std::move(shape)));
    }

} // namespace Svg

namespace Svg {

void RenderColor(std::ostream& out, std::monostate) {
  out << "none";
}

void RenderColor(std::ostream& out, const Rgb& rgb) {
  out << "rgb(" << static_cast<int>(rgb.red)
      << "," << static_cast<int>(rgb.green)
      << "," << static_cast<int>(rgb.blue) << ")";
}

void RenderColor(std::ostream& out, const Rgba& rgba) {
  out << "rgba(" << static_cast<int>(rgba.red)
      << "," << static_cast<int>(rgba.green)
      << "," << static_cast<int>(rgba.blue)
      << "," << rgba.alpha << ")";
}

void RenderColor(std::ostream& out, const std::string& name) {
  out << name;
}

void RenderColor(std::ostream& out, const Color& color) {
  std::visit([&out](const auto& c) { RenderColor(out, c); }, color);
}

Rectangle& Rectangle::SetBasePoint(Point p) {
  base_point_ = p;
  return *this;
}

Rectangle& Rectangle::SetWidth(double w) {
  w_ = w;
  return *this;
}

Rectangle& Rectangle::SetHeight(double h) {
  h_ = h;
  return *this;
}

void Rectangle::Render(std::ostream& out) const {
  out << "<rect";

  out << " " << "x" << "=" << "\"" << base_point_.x << "\"";
  out << " " << "y" << "=" << "\"" << base_point_.y << "\"";
  out << " " << "width" << "=" << "\"" << w_ << "\"";
  out << " " << "height" << "=" << "\"" << h_ << "\"";

  out << " ";
  ShapeProperties::RenderProperties(out);
  out << " />";
}

Circle& Circle::SetCenter(Point center) {
  center_ = center;
  return *this;
}

Circle& Circle::SetRadius(double r) {
  r_ = r;
  return *this;
}

void Circle::Render(std::ostream& out) const {
  out << "<circle ";

  ShapeProperties::RenderProperties(out);

  out << " " << "cx" << "=" << "\"" << center_.x << "\"";
  out << " " << "cy" << "=" << "\"" << center_.y << "\"";
  out << " " << "r" << "=" << "\"" << r_ << "\"";

  out << "/>";
}

Polyline& Polyline::AddPoint(Point point) {
  points_.push_back(point);
  return *this;
}

void Polyline::Render(std::ostream& out) const {
  out << "<polyline ";

  ShapeProperties::RenderProperties(out);

  out << " " << "points" << "=" << "\"";

  bool first = true;
  for (const auto& point : points_) {
    if (first) {
      first = false;
    } else {
      out << " ";
    }

    out << point.x << "," << point.y;
  }

  out << "\"";

  out << "/>";
}

Text& Text::SetPoint(Point coordinates) {
  coordinates_ = coordinates;
  return *this;
}

Text& Text::SetOffset(Point offset) {
  offset_ = offset;
  return *this;
}

Text& Text::SetFontSize(uint32_t font_size) {
  font_size_ = font_size;
  return *this;
}

Text& Text::SetFontFamily(const std::string& font_family) {
  font_family_ = font_family;
  return *this;
}

Text& Text::SetFontWeight(const std::string& font_weight) {
  font_weight_ = font_weight;
  return *this;
}

Text& Text::SetData(const std::string& data) {
  data_ = data;
  return *this;
}

void Text::Render(std::ostream& out) const {
  out << "<text ";

  ShapeProperties::RenderProperties(out);

  out << " " << "x" << "=" << "\"" << coordinates_.x << "\"";
  out << " " << "y" << "=" << "\"" << coordinates_.y << "\"";

  out << " " << "dx" << "=" << "\"" << offset_.x << "\"";
  out << " " << "dy" << "=" << "\"" << offset_.y << "\"";

  out << " " << "font-size" << "=" << "\"" << font_size_ << "\"";

  if (font_family_) {
    out << " " << "font-family" << "=\"" << font_family_.value() << "\"";
  }

  if (font_weight_) {
    out << " " << "font-weight" << "=\"" << font_weight_.value() << "\"";
  }

  out << ">";
  out << data_;
  out << "</text>";
}

void Document::Render(std::ostream& out) const {
  out << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>";
  out << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">";

  for (const auto& shape : shapes_) {
    shape->Render(out);
  }

  out << "</svg>";
}

std::string Document::ToString() const {
  std::ostringstream out;
  Render(out);
  return out.str();
}

} // namespace Svg
