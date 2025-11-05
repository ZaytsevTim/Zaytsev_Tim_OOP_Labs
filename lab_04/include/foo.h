#pragma once
#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Array.h"
#include "../include/Square.h"
#include "../include/Triangle.h"
#include "../include/Rectangle.h"

template<class ArrayType>
void print_all(const ArrayType& figures) {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Фигура номер: " << i + 1 << ":\n";

        auto&& item = figures[i];

        std::cout << "Центр: " << item->geom_center() << "\n";
        item->print();
        std::cout << "Площадь: " << item->area() << "\n\n";
    }
}

template<class ArrayType>
double total_area(const ArrayType& figures) {
    double total = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        auto&& item = figures[i];
        total += item->area();
    }
    return total;
}

std::shared_ptr<Figure<double>> input_square() {
    double x, y, side;

    std::cout << "Введите центр квадрата (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите сторону: ";
    std::cin >> side;
    return std::make_shared<Square<double>>(x, y, side);
}

std::shared_ptr<Figure<double>> input_triangle() {
    double x, y, base, height;

    std::cout << "Введите центр треугольника (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите основание: ";
    std::cin >> base;
    std::cout << "Введите высоту: ";
    std::cin >> height;
    return std::make_shared<Triangle<double>>(x, y, base, height);
}

std::shared_ptr<Figure<double>> input_rectangle() {
    double x, y, width, height;

    std::cout << "Введите центр прямоугольника (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите ширину: ";
    std::cin >> width;
    std::cout << "Введите высоту: ";
    std::cin >> height;
    return std::make_shared<Rectangle<double>>(x, y, width, height);
}

std::shared_ptr<Square<double>> input_square_for_squares() {
    double x, y, side;
    std::cout << "Введите центр квадрата (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите сторону: ";
    std::cin >> side;
    return std::make_shared<Square<double>>(x, y, side);
}