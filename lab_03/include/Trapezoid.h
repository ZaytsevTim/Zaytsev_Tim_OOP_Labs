#include "Figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0, double x3 = 0, double y3 = 0, double x4 = 0, double y4 = 0);
    
    std::pair<double, double> center() const override;
    double area() const override;
    bool operator==(const Figure& other) const override;
    double perimeter() const;
};
