#pragma once
#include "Point.h"

template<class T>
class Figure {
public:
    virtual ~Figure() = default;
    virtual Point<T> geom_center() const = 0;
    virtual double area() const = 0;
    virtual void print() const = 0;
    
    explicit operator double() const {
        return area();
    }
};