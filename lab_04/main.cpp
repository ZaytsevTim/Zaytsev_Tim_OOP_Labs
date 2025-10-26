#include <iostream>
#include <memory>
#include "include/Point.h"
#include "include/Figure.h"
#include "include/Square.h"
#include "include/Triangle.h"
#include "include/Rectangle.h"
#include "include/Array.h"
#include "src/foo.cpp"

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    int a;
    do {
        std::cout << "1. Добавить квадрат\n";
        std::cout << "2. Добавить треугольник\n";
        std::cout << "3. Добавить прямоугольник\n";
        std::cout << "4. Вывесть все фигуры (с площадями и центрами)\n";
        std::cout << "5. Общая площадь\n";
        std::cout << "6. Удалить фигуру\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> a;

        switch (a) {
            case 1:
                figures.push_back(input_square());
                break;
            case 2:
                figures.push_back(input_triangle());
                break;
            case 3: 
                figures.push_back(input_rectangle());
                break;
            case 4:
                print_all(figures);
                break;
            case 5:
                std::cout << "Суммарная площадь: " << total_area(figures) << "\n";
                break;
            case 6: 
            {
                size_t i;
                std::cout << "Введите индекс: ";
                std::cin >> i;
                if (i < figures.size()) {
                    figures.remove(i);
                    std::cout << "Фиугра удалена!\n";
                } else {
                    std::cout << "Неверный индекс\n";
                }
                break;
            }
        }
    } while (a != 0);

    return 0;
}