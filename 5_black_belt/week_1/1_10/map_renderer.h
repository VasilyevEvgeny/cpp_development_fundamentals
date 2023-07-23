#pragma once

#include "json.h"
#include "svg.h"
#include "sphere.h"
#include "descriptions.h"

namespace SvgMap {
    struct Stop {
        std::string name;
        Svg::Point position;
    };

    struct Bus {
        std::string name;
        std::vector<std::shared_ptr<Stop>> stops;
        std::vector<std::shared_ptr<Stop>> endpoints;
        Svg::Color color = Svg::NoneColor;
    };
}

class MapRenderer {
public:
    MapRenderer(const Descriptions::StopsDict& stops_dict,
        const Descriptions::BusesDict& buses_dict,
        const Json::Dict& render_settings_json);

    std::string Render() const;

private:
    struct RenderSettings {
        double width;
        double height;
        double padding;
        double stop_radius;
        double line_width;
        uint32_t stop_label_font_size;
        Svg::Point stop_label_offset;
        Svg::Color underlayer_color;
        double underlayer_width;
        std::vector<Svg::Color> color_palette;
        uint32_t bus_label_font_size;
        Svg::Point bus_label_offset;
        std::vector<std::string> layers;
    };

    static RenderSettings MakeRenderSettings(const Json::Dict& json);
    static Svg::Color ConvertJsonColorToSvg(const Json::Node&);

    struct MinMaxGeoCoords {
        double min_lat;
        double min_lon;
        double max_lat;
        double max_lon;
    };
    
    MinMaxGeoCoords GetMinMaxGeoCoords(const Descriptions::StopsDict& stops_dict) const;
    double GetZoomCoef(MinMaxGeoCoords geo_coords) const;

    void RenderBusLines(Svg::Document& svg) const;
    void RenderBusLabels(Svg::Document& svg) const;
    void RenderStopPoints(Svg::Document& svg) const;
    void RenderStopLabels(Svg::Document& svg) const;

    std::map<std::string, std::shared_ptr<SvgMap::Stop>> stops_;
    std::map<std::string, std::shared_ptr<SvgMap::Bus>> buses_;
    RenderSettings render_settings_;

    static const std::unordered_map<std::string, void (MapRenderer::*)(Svg::Document&) const> LAYER_ACTIONS;
};
