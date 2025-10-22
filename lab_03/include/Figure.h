#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#ifndef TWELVE_H
#define TWELVE_H

class Figure
{
    public : 
        Figure(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0, double x3 = 0, double y3 = 0, double x4 = 0, double y4 = 0);

        virtual ~Figure() noexcept;  

        friend std::istream& operator>>(std::istream& is, Figure& p);    
        friend std::ostream& operator<<(std::ostream& os, const Figure& p);

        virtual std::pair<double, double> center() const = 0;
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual bool operator==(const Figure& other) const = 0;

        virtual Figure& operator=(const Figure& other);
        virtual Figure& operator=(Figure&& other) noexcept;

        virtual void print(std::ostream& os) const;
        virtual void read(std::istream& is);

        double VectorsArea(double x1, double y1, double x2, double y2, double x4, double y4) const;       

         virtual operator double() const;
    protected:
          double x1{0.0}, y1{0.0}, x2{0.0}, y2{0.0}, x3{0.0}, y3{0.0}, x4{0.0}, y4{0.0};   
    
};

#endif