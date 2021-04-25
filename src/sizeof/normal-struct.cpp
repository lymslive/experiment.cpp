#include <iostream>
#include <stdio.h>

// 从大到小或从小到大，sizeof = 16
struct SNumberUp
{
    char c;
    short s;
    int i;
    double d;
};

struct SNumberDown
{
    double d;
    int i;
    short s;
    char c;
};

// 4*3 = 12
struct SNumberMix
{
    char c;
    int i;
    short s;
};

// 8*3 = 24
struct SNumberMixD
{
    char c;
    double d;
    short s;
};

// sizeof = 18, 只压缩尾部
struct __attribute__((__packed__)) SNumberPack
{
    char c;
    double d;
    short s;
};

// sizeof = 11
#pragma pack(1)
struct SNumberPack1
{
    char c;
    double d;
    short s;
};
#pragma pack()

int main(int argc, char* argv[])
{
    std::cout << "sizeof(SNumberUp) = " << sizeof(SNumberUp) << std::endl;
    std::cout << "sizeof(SNumberDown) = " << sizeof(SNumberDown) << std::endl;
    std::cout << "sizeof(SNumberMix) = " << sizeof(SNumberMix) << std::endl;
    std::cout << "sizeof(SNumberMixD) = " << sizeof(SNumberMixD) << std::endl;

    // cout 这样打印地址偏移失效
    std::cout << "cout address SNumberMixD: "
	<< &SNumberMixD::c << " "
	<< &SNumberMixD::d << " "
	<< &SNumberMixD::s << " "
	<< std::endl;

    printf("printf address SNumberMixD: %d %d %d\n", &SNumberMixD::c, &SNumberMixD::d, &SNumberMixD::s);

    std::cout << "sizeof(SNumberPack) = " << sizeof(SNumberPack) << std::endl;

    std::cout << "sizeof(SNumberPack1) = " << sizeof(SNumberPack1) << std::endl;
}

/*
sizeof(SNumberUp) = 16
sizeof(SNumberDown) = 16
sizeof(SNumberMix) = 12
sizeof(SNumberMixD) = 24
cout address SNumberMixD: 1 1 1
printf address SNumberMixD: 0 8 16
sizeof(SNumberPack) = 18
sizeof(SNumberPack1) = 11
*/

/* 参考
 * https://zhuanlan.zhihu.com/p/26122273 C/C++中结构体字节对齐规则
 */
