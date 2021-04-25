#include <iostream>

int main(int argc, char* argv[])
{
    int i = 0;
    // sizeof 写法，类型必须有括号
    std::cout << "sizeof(i) = " << sizeof(i)<< std::endl;
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof i = " << sizeof i << std::endl;

    // 无符号类型不影响大小
    std::cout << "sizeof(unsigned int) = " << sizeof(unsigned int) << std::endl;

    // 整型
    std::cout << "sizeof(bool) = " << sizeof(bool) << std::endl;
    std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
    std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
    std::cout << "sizeof(long) = " << sizeof(long) << std::endl;
    std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;

    // 浮点型
    std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
    std::cout << "sizeof(double) = " << sizeof(double) << std::endl;
    std::cout << "sizeof(long double) = " << sizeof(long double) << std::endl;

    // 指针型
    int *pi = nullptr;
    double *pd = nullptr;
    std::cout << "sizeof(pi) = " << sizeof(pi) << std::endl;
    std::cout << "sizeof(pd) = " << sizeof(pd) << std::endl;
    std::cout << "sizeof(void*) = " << sizeof(void*) << std::endl;
}

/* output in gitbash g++, 64bit win10
 * g++.exe (x86_64-posix-seh, Built by strawberryperl.com project) 7.1.0
sizeof(i) = 4
sizeof(int) = 4
sizeof i = 4
sizeof(unsigned int) = 4
sizeof(bool) = 1
sizeof(char) = 1
sizeof(short) = 2
sizeof(long) = 4
sizeof(long long) = 8
sizeof(float) = 4
sizeof(double) = 8
sizeof(long double) = 16
sizeof(pi) = 8
sizeof(pd) = 8
sizeof(void*) = 8
*/

/* output in gitbash g++, qt mingw_32
 * g++.exe (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 5.3.0
sizeof(i) = 4
sizeof(int) = 4
sizeof i = 4
sizeof(unsigned int) = 4
sizeof(bool) = 1
sizeof(char) = 1
sizeof(short) = 2
sizeof(long) = 4
sizeof(long long) = 8
sizeof(float) = 4
sizeof(double) = 8
sizeof(long double) = 12
sizeof(pi) = 4
sizeof(pd) = 4
sizeof(void*) = 4
*/

/* win10 wsl g++
 * g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
sizeof(i) = 4
sizeof(int) = 4
sizeof i = 4
sizeof(unsigned int) = 4
sizeof(bool) = 1
sizeof(char) = 1
sizeof(short) = 2
sizeof(long) = 8
sizeof(long long) = 8
sizeof(float) = 4
sizeof(double) = 8
sizeof(long double) = 16
sizeof(pi) = 8
sizeof(pd) = 8
sizeof(void*) = 8
 */

/*
 * sizeof 是操作符，可作用于变量或类型，但类型需加括号。
 */
