#include <iostream>

class CEmpty
{
};

struct SEmpty
{
};

class VEmpty
{
public:
    VEmpty(){}
    virtual ~VEmpty() {}
};

class DVEmpty : public VEmpty
{
public:
    DVEmpty(){}
    virtual ~DVEmpty() {}
};

class DCEmpty : public CEmpty
{
public:
    DCEmpty() {}
};

class VEmptyOne : public VEmpty
{
public:
    VEmptyOne(){}
    virtual ~VEmptyOne() {}

    virtual void method() {}
};


class VEmptyTwo : public VEmpty
{
public:
    VEmptyTwo(){}
    virtual ~VEmptyTwo() {}

    virtual void method() {}
    virtual void more() {}
};

class MEmpty : public CEmpty
{
public:
    MEmpty() {}
    int method(int) {}
    int more(int) {}
};

class CStatic
{
public:
    static int value;
};
int CStatic::value = 0;

int main(int argc, char* argv[])
{
    std::cout << "sizeof(CEmpty)" << sizeof(CEmpty) << std::endl; // 空类大小
    std::cout << "sizeof(SEmpty)" << sizeof(SEmpty) << std::endl; // struct 是否与 class 有区别
    std::cout << "sizeof(VEmpty)" << sizeof(VEmpty) << std::endl; // 存在虚函数的空类

    std::cout << "sizeof(DVEmpty)" << sizeof(DVEmpty) << std::endl; // 空类继承是否有影响
    std::cout << "sizeof(DCEmpty)" << sizeof(DCEmpty) << std::endl;

    std::cout << "sizeof(VEmptyOne)" << sizeof(VEmptyOne) << std::endl; // 多个虚函数是否有影响
    std::cout << "sizeof(VEmptyTwo)" << sizeof(VEmptyTwo) << std::endl;

    std::cout << "sizeof(MEmpty)" << sizeof(MEmpty) << std::endl; // 普通方法又是否影响大小
    std::cout << "sizeof(CStatic)" << sizeof(CStatic) << std::endl; // 静态成员又是否影响大小
}

/* output
sizeof(CEmpty)1
sizeof(SEmpty)1
sizeof(VEmpty)8
sizeof(DVEmpty)8
sizeof(DCEmpty)1
sizeof(VEmptyOne)8
sizeof(VEmptyTwo)8
sizeof(MEmpty)1
sizeof(CStatic)1
*/
