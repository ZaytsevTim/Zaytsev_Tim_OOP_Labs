#pragma once
#include "Figure.h"

template<class T>
class Square : public Figure<T> {
private:
    Point<T> center_;
    T side_;
public:
    Square(T x, T y, T side);
    Point<T> geom_center() const override;
    double area() const override;
    void print() const override;
};

template<class T>
Square<T>::Square(T x, T y, T a): center_(x, y), side_(a) {}

template<class T>
Point<T> Square<T>::geom_center() const {
    return center_;
}

template<class T>
double Square<T>::area() const {
    return static_cast<double>(side_ * side_);
}

template<class T>
void Square<T>::print() const {
    std::cout << "Выводим вершины квадрата:\n";

    std::cout << Point<T>(center_.x() - side_ / 2, center_.y() - side_ / 2) << "\n";
    std::cout << Point<T>(center_.x() + side_ / 2, center_.y() - side_ / 2) << "\n";
    std::cout << Point<T>(center_.x() + side_ / 2, center_.y() + side_ / 2) << "\n";
    std::cout << Point<T>(center_.x() - side_ / 2, center_.y() + side_ / 2) << "\n";
}