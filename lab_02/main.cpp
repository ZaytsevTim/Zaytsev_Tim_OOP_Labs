#include <iostream>
#include "include/Twelve.h"

int main(){
    std::string str;
    std::string str2;
    unsigned char t;
    size_t sz;
    std::cout << "Введите число в 12-ной СС:\n";
    std::cin >> str;
    std::cout << "Введите цифру в 12-ной СС и количество её повторений:\n";
    std::cin >> sz >> t;
    
    try{
        Twelve first_num(str);
        Twelve second_num(sz, t);

        std::cout << "Числа успешно созданы!" << std::endl;
        std::cout << "Демонстрация ариф. операций:" << std::endl;

        std::cout << "Сумма: ";
        (first_num.plus(second_num)).print(std::cout) << std::endl;

        try{
            std::cout << "Разность: ";
            (first_num.minus(second_num)).print(std::cout) << std::endl;
        }
        catch (const std::underflow_error& e){
            std::cout << "Ошибка при вычитании: " << e.what() << std::endl;    
        }

        std::cout << "Копирование (cоздадим копию первого числа): ";
        (first_num.copy()).print(std::cout) << std::endl;

        std::cout << "Демонстрация операций сравнения:" << std::endl;

        std::cout << "Первое > Второе ?: "  <<(first_num.bigger(second_num)) << std::endl;
        std::cout << "Первое == Второе ?: " <<(first_num.equals(second_num)) << std::endl;
        std::cout << "Первое < Второе ?: " <<(first_num.smaller(second_num)) << std::endl;

    }
    catch (const std::invalid_argument& e){
        std::cout << "Ошибка при создании чисел: " << e.what() << std::endl;
    }
    
    
    // std::cout << "Плюс равно: " << std::endl;
    // first_num += second_num;
    // first_num.print(std::cout) << std::endl;

    // std::cout << "Минус равно 5: " << std::endl;
    // first_num -= Twelve('5');
    // first_num.print(std::cout) << std::endl;
    // return 0;
}