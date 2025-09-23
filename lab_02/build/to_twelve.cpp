#include <string>
#include <algorithm>

std::string to_twelve(const int x){
    std::string str;
    int N = x;
    while (N){
        if (N % 12 > 9){
            str += ((N % 12) - 10 + 'A');
        }
        else{
            str += ((N % 12) + '0');
        }
        N /= 12;
    }
    std::reverse(str.begin(), str.end());
    return str;
} 
