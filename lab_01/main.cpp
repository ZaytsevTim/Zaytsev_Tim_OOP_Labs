#include <iostream>
#include "include/num_to_32bit.h"

int main(){
    unsigned int num;
    std::cout << "enter your number:";
    std::cin >> num;

    std::cout << "result: " << num_to_32bit(num) << std::endl;
    
    return 0;
}