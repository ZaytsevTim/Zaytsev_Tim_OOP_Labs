#include "../include/Trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4): Figure(x1, y1, x2, y2, x3, y3, x4, y4) {}


double Trapezoid::perimeter() const {
    double side1 = std::sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    double side2 = std::sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
    double side3 = std::sqrt((x4-x3)*(x4-x3) + (y4-y3)*(y4-y3));
    double side4 = std::sqrt((x1-x4)*(x1-x4) + (y1-y4)*(y1-y4));
    return side1 + side2 + side3 + side4;
}

std::pair<double, double> Trapezoid::center() const {
    double center_x = (x1 + x2 + x3 + x4) / 4.0;
    double center_y = (y1 + y2 + y3 + y4) / 4.0;
    return {center_x, center_y};
}

double Trapezoid::area() const {
    double area1 = VectorsArea(x1, y1, x2, y2, x3, y3)/2;
    double area2 = VectorsArea(x1, y1, x3, y3, x4, y4)/2;   
    return area1 + area2;
}


bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* t = dynamic_cast<const Trapezoid*>(&other);
    if (!t) return false;
    return std::abs(static_cast<double>(*this) - static_cast<double>(*t)) < 1e-9 && std::abs(perimeter() - t->perimeter()) < 1e-9;
    
}