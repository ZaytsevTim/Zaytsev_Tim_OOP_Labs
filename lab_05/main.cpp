#include "include/MemoryResource.hpp"
#include "include/PmrList.hpp"
#include <iostream>
#include <string>

struct MyStruct {
    int x;
    double y;
    std::string s;
};

int main() {
    FixedBlockMemoryResource mem(2048);

    {
        PmrList<int> L(&mem);
        L.push_back(805);
        L.push_back(806);
        L.push_front(801);
        L.push_back(807);

        for (int v : L) std::cout << v << " ";
        std::cout << "\n";
    }

    {
        PmrList<MyStruct> L2(&mem);
        L2.push_back({8, 3, ">"});
        L2.push_back({806, 801, "MAI"});

        for (auto& v : L2)
            std::cout << v.x << " " << v.y << " " << v.s << "\n";
    }

    return 0;
}