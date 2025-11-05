#include <iostream>
#include <memory>
#include "include/Point.h"
#include "include/Figure.h"
#include "include/Square.h"
#include "include/Triangle.h"
#include "include/Rectangle.h"
#include "include/Array.h"
#include "include/foo.h"

int main() {
    Array<std::shared_ptr<Square<double>>> squares;
    Array<std::shared_ptr<Figure<double>>> figures;
    
    int a;
    do {
        std::cout << "---------------- ПО БАЗЕ ----------------\n";
        std::cout << "1. Добавить квадрат в массив базового типа\n";
        std::cout << "2. Добавить треугольник в массив базового типа\n";
        std::cout << "3. Добавить прямоугольник в массив базового типа \n";
        std::cout << "4. Вывести все фигуры (с площадями и центрами) из массива базового типа\n";
        std::cout << "5. Общая площадь из массива базового типа\n";
        std::cout << "6. Удалить фигуру из массива базового типа\n";
        std::cout << "------------А ТЕПЕРЬ ДЛЯ КВАДРАТОВ ---------------\n";
        std::cout << "7. Добавить квадрат в массив КВАДРАТОВ\n";
        std::cout << "8. Вывести все КВАДРАТЫ (с площадями и центрами) из массива КВАДРАТОВ\n";
        std::cout << "9. Общая площадь КВАДРАТОВ\n";
        std::cout << "10. Удалить КВАДРАТ(\n";
        std::cout << "0. Выходим\n";
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
            case 7:
                squares.push_back(input_square_for_squares());
                break;
            case 8:
                print_all(squares);
                break;
            case 9:
                std::cout << "Суммарная площадь: " << total_area(squares) << "\n";
                break;
            case 10: 
            {
                size_t i;
                std::cout << "Введите индекс квадрата: ";
                std::cin >> i;
                if (i < squares.size()) {
                    squares.remove(i);
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