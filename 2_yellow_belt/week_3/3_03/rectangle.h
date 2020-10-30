// https://www.coursera.org/learn/c-plus-plus-yellow/programming/GoiOm/napisat-obiavlieniie-klassa

#ifndef INC_2_YELLOW_BELT_RECTANGLE_H
#define INC_2_YELLOW_BELT_RECTANGLE_H

class Rectangle {

public:
    Rectangle(int width, int height);

    int GetArea() const;
    int GetPerimeter() const;

    int GetWidth() const;
    int GetHeight() const;

private:
    int width_, height_;

};

#endif //INC_2_YELLOW_BELT_RECTANGLE_H
