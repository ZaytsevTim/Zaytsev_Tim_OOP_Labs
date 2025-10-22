#include "Figure.h"

class Square : public Figure {
public:
    Square(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0, double x3 = 0, double y3 = 0, double x4 = 0, double y4 = 0);
    
    std::pair<double, double> center() const override;
    double area() const override;
    double perimeter() const;
    bool operator==(const Figure& other) const override;
};
