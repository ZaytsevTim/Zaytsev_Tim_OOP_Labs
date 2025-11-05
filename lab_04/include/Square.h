#pragma once
#include "Figure.h"

template<Scalar T>
class Square : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center_;
    T side_;
public:
    Square(T x, T y, T side);
    Point<T> geom_center() const override;
    bool operator==(const Figure<T>& other) const override;
    void print() const override;

    double area() const override;
    Square(const Square& other);
    Square& operator=(const Square& other);  
    explicit operator double() const {
        return area();
    }

};

    template<Scalar T>
    Square<T>::Square(T x, T y, T a): center_(std::make_unique<Point<T>>(x, y)), side_(a) {}

    template<Scalar T>
    Square<T>::Square(const Square& other): center_(std::make_unique<Point<T>>(*other.center_)), side_(other.side_) {}

    template<Scalar T>
    Square<T>& Square<T>::operator=(const Square& other) {
        if (this != &other) {
            center_ = std::make_unique<Point<T>>(*other.center_);
            side_ = other.side_;
        }
        return *this;
    }

    template<Scalar T>
    Point<T> Square<T>::geom_center() const {
        return *center_;
    }

    template<Scalar T>
    double Square<T>::area() const {
        return static_cast<double>(side_ * side_);
    }

template<Scalar T>
bool Square<T>::operator==(const Figure<T>& other) const {
    const Square* other_square = dynamic_cast<const Square*>(&other);
    if (!other_square) return false;
    return center_->x() == other_square->center_->x() && center_->y() == other_square->center_->y() && side_ == other_square->side_;
}
    template<Scalar T>
    void Square<T>::print() const {
        std::cout << "Выводим вершины квадрата:\n";

        T half = side_ / 2;

        std::cout << Point<T>(center_->x() - half, center_->y() - half) << "\n"; 
        std::cout << Point<T>(center_->x() + half, center_->y() - half) << "\n";  
        std::cout << Point<T>(center_->x() + half, center_->y() + half) << "\n";  
        std::cout << Point<T>(center_->x() - half, center_->y() + half) << "\n"; 
    }   