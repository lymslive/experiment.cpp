#include <iostream>

struct SEmpty
{
};

struct Normal
{
    int begin;
    int end;
};

struct Eafront
{
    char padding[0];
    int begin;
    int end;
};

struct Eamid
{
    int begin;
    char padding[0];
    int end;
};

struct Eaend
{
    int begin;
    int end;
    char padding[0];
};

int main(int argc, char* argv[])
{
    SEmpty arrEm[0];
    char arrChr[0];
    int arrInt[0];

    std::cout << "array with 0 elements: " << std::endl;
    std::cout << "sizeof(arrEm) = " << sizeof(arrEm) << std::endl;
    std::cout << "sizeof(arrChr) = " << sizeof(arrChr) << std::endl;
    std::cout << "sizeof(arrInt) = " << sizeof(arrInt) << std::endl;

    std::cout << std::endl;

    std::cout << "struct with zeor length array: " << std::endl;
    std::cout << "sizeof(Normal) = " << sizeof(Normal) << std::endl;
    std::cout << "sizeof(Eafront) = " << sizeof(Eafront) << std::endl;
    std::cout << "sizeof(Eamid) = " << sizeof(Eamid) << std::endl;
    std::cout << "sizeof(Eaend) = " << sizeof(Eaend) << std::endl;
}

/*
array with 0 elements:
sizeof(arrEm) = 0
sizeof(arrChr) = 0
sizeof(arrInt) = 0

struct with zeor length array
sizeof(Normal) = 8
sizeof(Eafront) = 8
sizeof(Eamid) = 8
sizeof(Eaend) = 8
*/
