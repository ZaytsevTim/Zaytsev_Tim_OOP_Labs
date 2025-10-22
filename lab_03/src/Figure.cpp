#include "../include/Figure.h"

double Figure::VectorsArea(double x1, double y1, double x2, double y2, double x4, double y4) const {
    double V1_x = x2 - x1;
    double V1_y = y2 - y1;
    double V2_x = x4 - x1;
    double V2_y = y4 - y1;
    
    double vectornoe = V1_x * V2_y - V1_y * V2_x;
    return std::abs(vectornoe);
}

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

// Оператор ввода - ДОЛЖЕН БЫТЬ РЕАЛИЗОВАН
std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}

Figure::Figure(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4): x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}

Figure::operator double() const {
    return area();
}



void Figure::print(std::ostream& os) const {
    os << "Координаты вершин фигуры: ";
    os << "A(" << x1 << ", " << y1 << "), ";
    os << "B(" << x2 << ", " << y2 << "), ";
    os << "C(" << x3 << ", " << y3 << "), ";
    os << "D(" << x4 << ", " << y4 << ").";
}

void Figure::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        x1 = other.x1;
        y1 = other.y1;
        x2 = other.x2;
        y2 = other.y2;
        x3 = other.x3;
        y3 = other.y3;
        x4 = other.x4;
        y4 = other.y4;
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        x1 = std::move(other.x1);
        y1 = std::move(other.y1);
        x2 = std::move(other.x2);
        y2 = std::move(other.y2);
        x3 = std::move(other.x3);
        y3 = std::move(other.y3);
        x4 = std::move(other.x4);
        y4 = std::move(other.y4);
    }
    return *this;
}
Figure::~Figure() {}