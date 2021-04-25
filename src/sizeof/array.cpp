#include <iostream>

class CEmpty
{
};

void f(int arr[])
{
    // ª·”– warnning
    std::cout << "sizeof(arr) in function call: " << sizeof(arr) << std::endl;
}

int main(int argc, char* argv[])
{
    CEmpty arrEm[5];
    int arrInt[5];

    std::cout << "sizeof(arrEm) = " << sizeof(arrEm) << std::endl;
    std::cout << "sizeof(arrInt) = " << sizeof(arrInt) << std::endl;

    int arr[] = {1, 2, 3, 4};
    std::cout << "sizeof(arr) = " << sizeof(arr) << std::endl;
    std::cout << "sizeof(arr)/sizeof(arr[0]) = " << sizeof(arr)/sizeof(arr[0]) << std::endl;

    f(arr);
}

/*
sizeof(arrEm) = 5
sizeof(arrInt) = 20
sizeof(arr) = 16
sizeof(arr)/sizeof(arr[0]) = 4
sizeof(arr) in function call: 8
*/
