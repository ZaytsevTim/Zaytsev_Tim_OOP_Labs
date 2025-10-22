#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0, double x3 = 0, double y3 = 0, double x4 = 0, double y4 = 0);
    
    std::pair<double, double> center() const override;
    double perimeter() const;
    double area() const override;
    bool operator==(const Figure& other) const override;
};
