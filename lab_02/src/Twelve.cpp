#include "../include/Twelve.h"

Twelve::Twelve() : _size(1)
{
    _number = new unsigned char[1];
    _number[0] = '0';
}

Twelve::Twelve(const size_t &n, unsigned char t)
{
    if (n == 0){
        throw std::invalid_argument("Размер должен быть положительным!");
    }
    
    if (!(t == '0' || t == '1' || t == '2' || t == '3' || t == '4' || t == '5' || t == '6' || t == '7' || t == '8' || t == '9' || t == 'A' || t == 'B' || t == 'a' || t == 'b')) {
        throw std::invalid_argument("Не явл. числом в 12-ричной СС!");
    }

    _number = new unsigned char[n];
    for (size_t i=0; i < n; i++){
        _number[i] = t;
    }
    _size = n;
}

Twelve::Twelve(const std::initializer_list<unsigned char> &t) : _size(t.size())
{
    if (_size == 0){
        throw std::invalid_argument("Размер должен быть положительным!");
    }
    _number = new unsigned char[t.size()];
    size_t i{0};


    for (auto &c : t){
        if (!(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == 'A' || c == 'B' || c == 'a' || c == 'b')) {
            throw std::invalid_argument("Не явл. числом в 12-ричной СС!");
        }
        _number[i++] = c;
    }
}

Twelve::Twelve(const std::string &t)
{
    _number = new unsigned char[t.size()];
    _size  = t.size();

    for(size_t i{0}; i < _size; ++i){
        unsigned char c = t[i];
        if (!(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == 'A' || c == 'B' || c == 'a' || c == 'b')) {
            delete[] _number;
            throw std::invalid_argument("Не явл. числом в 12-ричной СС!");
        }
         _number[i] = c;
    }
}

Twelve::Twelve(const Twelve& other) : _size(other._size) {
    _number = new unsigned char[_size];
    for (size_t i = 0; i < _size; i++) {
        _number[i] = other._number[i];
    }
}

Twelve::Twelve(Twelve&& other) noexcept : _size(other._size), _number(other._number) {
    other._size = 0;
    other._number = nullptr;
}

std::ostream &Twelve::print(std::ostream &os)
{
    for (size_t i = 0; i < _size; ++i)
        os << _number[i];
    return os;
}


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
Twelve Twelve::plus(const Twelve& other) const{
    int a = other.get_decimal();
    int b = (*this).get_decimal();
    return Twelve(to_twelve(a+b));
}

Twelve Twelve::copy() const{
    std::string str;
    for (size_t i = 0; i < _size; i++) {
        str += _number[i];
    }
    return Twelve(str);
}

Twelve Twelve::minus(const Twelve& other) const{
    int a = (*this).get_decimal();
    int b = other.get_decimal();
    if (b > a) {
        throw std::underflow_error("Разость будет отрицательной, но по условию мы рассм. только беззнаковые числа");
    }
    return Twelve(to_twelve(abs(a-b)));
}

bool Twelve::equals(const Twelve& other) const{
    if (_size != other._size) return false;
        for (size_t i = 0; i < _size; i++) {
            if (_number[i] != other._number[i]) return false;
        }
    return true;
}

bool Twelve::bigger(const Twelve& other) const{
    return (*this).get_decimal() > other.get_decimal();
}

bool Twelve::smaller(const Twelve& other) const{
    return (*this).get_decimal() < other.get_decimal();
}

// Twelve& plus_assign(const Twelve& other){
//     std::string new_num = to_twelve((*this).get_decimal() + other.get_decimal());
//     (*this)._size = new_num.size();
//     for (int i=0; i <= (*this)._size ; i++){
//         (*this)._number[i] = new_num[i];
//     }
//     return *this;
// }

// Twelve& minus_assign(const Twelve& other){
//     std::string new_num = to_twelve((*this).get_decimal() - other.get_decimal());
//     (*this)._size = new_num.size();
//     for (int i=0; i <= (*this)._size ; i++){
//         (*this)._number[i] = new_num[i];
//     }
//     return *this;
 // }

Twelve::~Twelve() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _number;
        _number = nullptr;
    }
}
