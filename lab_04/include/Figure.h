#pragma once
#include "Point.h"

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;
    virtual Point<T> geom_center() const = 0;
    virtual void print() const = 0;
    virtual double area() const = 0; 

    virtual bool operator==(const Figure& other) const = 0;
};
