#include <iostream>
#include <vector>
#include <memory>
#include "include/Figure.h"
#include "include/Rectangle.h"
#include "include/Square.h"
#include "include/Trapezoid.h"

int main(){

    std::vector<std::unique_ptr<Figure>> figures;
    
    int choice = -1;
    while (choice != 0){
        std::cout << "1. Добавить прямоугольник\n";
        std::cout << "2. Добавить квадрат\n";
        std::cout << "3. Добавить трапецию\n";
        std::cout << "4. Вывести все фигуры\n";
        std::cout << "5. Удалить фигуру по индексу\n";
        std::cout << "6. Вычислить общую площадь\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";

        std::cin >> choice;
        switch (choice) {
                case 1: {
                    auto rect = std::make_unique<Rectangle>();
                    std::cout << "Введите координаты прямоугольника (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    std::cin >> *rect;  
                    figures.push_back(std::move(rect));
                    std::cout << "Прямоугольник добавлен!\n";
                    break;
                }
                case 2: {
                    auto square = std::make_unique<Square>();
                    std::cout << "Введите координаты квадрата (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    std::cin >> *square;  
                    figures.push_back(std::move(square));
                    std::cout << "Квадрат добавлен!\n";
                    break;
                }
                case 3: {
                    auto trapezoid = std::make_unique<Trapezoid>();
                    std::cout << "Введите координаты трапеции (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    std::cin >> *trapezoid; 
                    figures.push_back(std::move(trapezoid));
                    std::cout << "Трапеция добавлена!\n";
                    break;
                }
                case 4: {
                    if (figures.empty()) {
                        std::cout << "Массив пуст!\n";
                        break;
                    }
                    std::cout << "Выводим все фигуры, их центры и площадь\n"; 
                    for (size_t i = 0; i < figures.size(); i++){
                        std::cout << "Фигура номер:" << i << "\n" << *figures[i] << "\n";
                        std::pair<double,double> centre = figures[i]->center();
                        std::cout << "Центр: Q(" << centre.first << ", "<< centre.second << ")\n";
                        std::cout << "Площадь: " << static_cast<double>(*figures[i]) <<"\n";
                    }  
                    break;             
                }
                case 5: {
                    if (figures.empty()) {
                        std::cout << "Массив пуст!\n";
                        break;
                    }
                    
                    std::cout << "Введите индекс фигуры для удаления (0-" << figures.size()-1 << "): ";
                    size_t index;
                    std::cin >> index;
                    
                    if (index < figures.size()) {
                        figures.erase(figures.begin() + index);
                        std::cout << "Фигура удалена!\n";
                    } else {
                        std::cout << "Неверный индекс!\n";
                    }
                    break;
                }
                case 6: {
                    double sum =  0;
                    for (size_t i = 0; i < figures.size(); i++){
                        sum += static_cast<double>(*figures[i]);
                    }
                    std::cin >> sum;
                }

        }
    }
}