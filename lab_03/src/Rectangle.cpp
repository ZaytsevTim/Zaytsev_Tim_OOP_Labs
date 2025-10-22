#include "../include/Rectangle.h"
#include <cmath>

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4): Figure(x1, y1, x2, y2, x3, y3, x4, y4) {}

double Rectangle::perimeter() const {
    double side1 = std::sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    double side2 = std::sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
    return 2 * (side1 + side2);
}

std::pair<double, double> Rectangle::center() const {
    double center_x = (x1 + x2 + x3 + x4) / 4.0;
    double center_y = (y1 + y2 + y3 + y4) / 4.0;
    return {center_x, center_y};
}
double Rectangle::area() const{
    return VectorsArea(x1, y1, x2, y2, x4, y4);
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* r = dynamic_cast<const Rectangle*>(&other);
    if (!r) return false;
    double p1 = perimeter();
    double p2 = r->perimeter();

    double s1 = static_cast<double>(*this);
    double s2 = static_cast<double>(*r);
    
    return (std::abs(p1 - p2) < 1e-9) && (std::abs(s1 - s2) < 1e-9);
}
