#pragma once
#include "Figure.h"

template<class T>
class Triangle : public Figure<T> {
private:
    Point<T> center_;
    T base_, height_;
public:
    Triangle(T x, T y, T base, T height);
    Point<T> geom_center() const override;
    double area() const override;
    void print() const override;
};

template<class T>
Triangle<T>::Triangle(T x, T y, T base, T height): center_(x, y), base_(base), height_(height) {}

template<class T>
Point<T> Triangle<T>::geom_center() const {
    return center_;
}

template<class T>
double Triangle<T>::area() const {
    return static_cast<double>(base_ * height_ / 2);
}

template<class T>
void Triangle<T>::print() const {
    std::cout << "Выводим вершинв треугольника:\n";
    
    std::cout << Point<T>(center_.x() - base_/2, center_.y() - height_/3) << "\n";
    std::cout << Point<T>(center_.x() + base_/2, center_.y() - height_/3) << "\n";
    std::cout << Point<T>(center_.x(), center_.y() + 2*height_/3) << "\n";
}