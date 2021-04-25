#include <iostream>
#include <stdio.h>

// union ��Сȡ��������Ա
union UNumberUp
{
    char c;
    short s;
    int i;
    double d;
};

union UNumberDown
{
    double d;
    int i;
    short s;
    char c;
};

union UNumberMix
{
    char c;
    double d;
    int i;
    short s;
};

// union Ҳ������Ա����
union UNumberExtra
{
    char c[9];
    double d;
    int i;
    short s;
};

// ���� union ����ֽ���
union UByteOrder
{
    short value;
    char byte[2];
};

int main(int argc, char* argv[])
{
    std::cout << "sizeof(UNumberUp) = " << sizeof(UNumberUp) << std::endl;
    std::cout << "sizeof(UNumberDown) = " << sizeof(UNumberDown) << std::endl;
    std::cout << "sizeof(UNumberMix) = " << sizeof(UNumberMix) << std::endl;
    std::cout << "sizeof(UNumberExtra) = " << sizeof(UNumberExtra) << std::endl;

    UByteOrder test;
    test.value = 0x0001;
    if (test.byte[0] == 0x00 && test.byte[1] == 0x01)
    {
	std::cout << "big endian" << std::endl;
    }
    else if (test.byte[0] == 0x01 && test.byte[1] == 0x00)
    {
	std::cout << "little endian" << std::endl;
    }
    else
    {
	std::cout << "unkown endian" << std::endl;
    }
}

/*
sizeof(UNumberUp) = 8
sizeof(UNumberDown) = 8
sizeof(UNumberMix) = 8
sizeof(UNumberExtra) = 16
little endian
*/
