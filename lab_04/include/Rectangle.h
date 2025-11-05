#pragma once
#include "Figure.h"

template<Scalar T>
class Rectangle : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center_;
    T width_, height_;
public:
    Rectangle(T x, T y, T width, T height);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);   

    Point<T> geom_center() const override;
    double area() const override;
    void print() const override;
    bool operator==(const Figure<T>& other) const override;
    explicit operator double() const {
        return area();
    }
};

template<Scalar T>
Rectangle<T>::Rectangle(T x, T y, T a, T b): center_(std::make_unique<Point<T>>(x, y)), width_(a), height_(b) {}

template<Scalar T>
Rectangle<T>::Rectangle(const Rectangle& other): center_(std::make_unique<Point<T>>(*other.center_)), width_(other.width_), height_(other.height_) {}

template<Scalar T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle& other) {
    if (this != &other) {
        center_ = std::make_unique<Point<T>>(*other.center_);
        width_ = other.width_;
        height_ = other.height_;
    }
    return *this;
}

template<Scalar T>
Point<T> Rectangle<T>::geom_center() const {
    return *center_;
}

template<Scalar T>
double Rectangle<T>::area() const {
    return static_cast<double>(width_ * height_);
}

template<Scalar T>
void Rectangle<T>::print() const {
    T half_w = width_ / 2;
    T half_h = height_ / 2;

    std::cout << "Выводим вершины прямоугольника:\n";

    std::cout << Point<T>(center_->x() - half_w, center_->y() - half_h) << "\n";
    std::cout << Point<T>(center_->x() + half_w, center_->y() - half_h) << "\n";
    std::cout << Point<T>(center_->x() + half_w, center_->y() + half_h) << "\n";
    std::cout << Point<T>(center_->x() - half_w, center_->y() + half_h) << "\n";
}

template<Scalar T>
bool Rectangle<T>::operator==(const Figure<T>& other) const {
    const Rectangle* other_r = dynamic_cast<const Rectangle*>(&other);
    if (!other_r) return false;
    return center_->x() == other_r->center_->x() && center_->y() == other_r->center_->y() && width_ == other_r->width_ && height_ == other_r->height_;;
}