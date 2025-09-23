#include "../include/num_to_32bit.h"

std::string num_to_32bit(unsigned int num){
    std::string result = "";
    int len=0;
    while (num > 0){
        if (num % 2 == 1){
           result = "1" + result; 
           len++;
        }
        else{
            result = "0" + result;
            len++;
        }
        num /= 2;
    }
    std::string zeros(32 - len, '0');
    result = zeros + result;
    return result;
}
