#include "../include/Square.h"
#include <cmath>

Square::Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4): Figure(x1, y1, x2, y2, x3, y3, x4, y4) {}

std::pair<double, double> Square::center() const {
    double center_x = (x1 + x2 + x3 + x4) / 4.0;
    double center_y = (y1 + y2 + y3 + y4) / 4.0;
    return {center_x, center_y};
}

double Square::area() const {
    double side = std::sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    
    return side * side;
}

double Square::perimeter() const {
    double side = std::sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return 4 * side;
}

bool Square::operator==(const Figure& other) const {
    const Square* s = dynamic_cast<const Square*>(&other);
    if (!s) return false;
    return std::abs(static_cast<double>(*this) - static_cast<double>(*s)) < 1e-9;
}