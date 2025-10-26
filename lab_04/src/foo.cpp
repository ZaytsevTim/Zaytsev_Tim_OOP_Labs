#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Array.h"
#include "../include/Square.h"
#include "../include/Triangle.h"
#include "../include/Rectangle.h"


template<class T>
void print_all(const Array<std::shared_ptr<Figure<T>>>& figures) {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Фигура номер: " << i + 1 << ":\n";
        std::cout << "Центр: " << figures[i]->geom_center() << "\n";
        figures[i]->print();
        std::cout << "Площадь: " << figures[i]->area() << "\n\n";
    }
}

template<class T>
double total_area(const Array<std::shared_ptr<Figure<T>>>& figures) {
    double total = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        total += figures[i]->area();
    }
    return total;
}

inline std::shared_ptr<Figure<double>> input_square() {
    double x, y, side;

    std::cout << "Введите центр квадрата (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите сторону: ";
    std::cin >> side;
    return std::make_shared<Square<double>>(x, y, side);
}

inline std::shared_ptr<Figure<double>> input_triangle() {
    double x, y, base, height;

    std::cout << "Введите центр треугольника (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите основание: ";
    std::cin >> base;
    std::cout << "Введите высоту: ";
    std::cin >> height;
    return std::make_shared<Triangle<double>>(x, y, base, height);
}

inline std::shared_ptr<Figure<double>> input_rectangle() {
    double x, y, width, height;

    std::cout << "Введите центр прямоугольника (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите ширину: ";
    std::cin >> width;
    std::cout << "Введите высоту: ";
    std::cin >> height;
    return std::make_shared<Rectangle<double>>(x, y, width, height);
}