#pragma once
#include "Figure.h"

template<Scalar T>
class Triangle : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center_;
    T base_, height_;
public:
    Triangle(T x, T y, T base, T height);
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
    
    Point<T> geom_center() const override;
    double area() const override;
    void print() const override;
    bool operator==(const Figure<T>& other) const override;
    explicit operator double() const {
        return area();
    }
};

template<Scalar T>
Triangle<T>::Triangle(T x, T y, T base, T height): center_(std::make_unique<Point<T>>(x, y)), base_(base), height_(height) {}

template<Scalar T>
Triangle<T>::Triangle(const Triangle& other): center_(std::make_unique<Point<T>>(*other.center_)), base_(other.base_), height_(other.height_) {}


template<Scalar T>
Triangle<T>& Triangle<T>::operator=(const Triangle& other) {
    if (this != &other) {
        center_ = std::make_unique<Point<T>>(*other.center_);
        base_ = other.base_;
        height_ = other.height_;
    }
    return *this;
}

template<Scalar T>
Point<T> Triangle<T>::geom_center() const {
    return *center_;
}

template<Scalar T>
double Triangle<T>::area() const {
    return static_cast<double>(base_ * height_ / 2);
}

template<Scalar T>
void Triangle<T>::print() const {
    std::cout << "Выводим вершинв треугольника:\n";
    
    std::cout << Point<T>(center_->x() - base_/2, center_->y() - height_/3) << "\n";
    std::cout << Point<T>(center_->x() + base_/2, center_->y() - height_/3) << "\n";
    std::cout << Point<T>(center_->x(), center_->y() + 2*height_/3) << "\n";
}

template<Scalar T>
bool Triangle<T>::operator==(const Figure<T>& other) const {
    const Triangle* other_triangle = dynamic_cast<const Triangle*>(&other);
    if (!other_triangle) return false;
    return center_->x() == other_triangle->center_->x() && center_->y() == other_triangle->center_->y() && base_ == other_triangle->base_ && height_ == other_triangle->height_;
}