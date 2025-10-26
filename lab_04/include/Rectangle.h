#pragma once
#include "Figure.h"

template<class T>
class Rectangle : public Figure<T> {
private:
    Point<T> center_;
    T width_, height_;
public:
    Rectangle(T x, T y, T width, T height);
    Point<T> geom_center() const override;
    double area() const override;
    void print() const override;
};

template<class T>
Rectangle<T>::Rectangle(T x, T y, T a, T b): center_(x, y), width_(a), height_(b) {}

template<class T>
Point<T> Rectangle<T>::geom_center() const {
    return center_;
}

template<class T>
double Rectangle<T>::area() const {
    return static_cast<double>(width_ * height_);
}

template<class T>
void Rectangle<T>::print() const {
    T half_w = width_ / 2;
    T half_h = height_ / 2;

    std::cout << "Выводим вершины прямоугольника:\n";

    std::cout << Point<T>(center_.x() - half_w, center_.y() - half_h) << "\n";
    std::cout << Point<T>(center_.x() + half_w, center_.y() - half_h) << "\n";
    std::cout << Point<T>(center_.x() + half_w, center_.y() + half_h) << "\n";
    std::cout << Point<T>(center_.x() - half_w, center_.y() + half_h) << "\n";
}