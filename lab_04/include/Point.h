#pragma once
#include <iostream>
#include <concepts>
#include <type_traits>
#include <memory>


template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
private:
    T x_, y_;
public:
    Point(T x = 0, T y = 0) : x_(x), y_(y) {}
    T x() const { return x_; }
    T y() const { return y_; }

    bool operator==(const Point& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x_ << ", " << point.y_ << ")";
        return os;
    }
};