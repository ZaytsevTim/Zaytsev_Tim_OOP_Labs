#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <algorithm>

#ifndef TWELVE_H
#define TWELVE_H

class Twelve
{
    public : 
        Twelve();
        Twelve(const size_t & n, unsigned char t = 0);
        Twelve(const std::initializer_list< unsigned char> &t);
        Twelve(const std::string &t);

        Twelve(const Twelve& other);
        Twelve(Twelve&& other) noexcept;  
        virtual ~Twelve() noexcept;  

        Twelve plus(const Twelve& other) const;
        Twelve minus(const Twelve& other) const;
        Twelve copy() const;

        bool   equals(const Twelve& other) const;
        bool   bigger(const Twelve& other) const;
        bool   smaller(const Twelve& other) const;
        std::ostream&   print(std::ostream& os);

        int get_decimal() const{
            int result = 0;
            for (int i = 0; i < _size; i++){
                if (isdigit(_number[i])){
                    result = result * 12 + (_number[i] - '0');
                }
                else{
                    result = result * 12 + (_number[i] - 'A' + 10);
                }
            }
            return result;
        }

    private:
          size_t _size;
          unsigned char *_number;    
};

#endif