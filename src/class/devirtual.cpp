#include <iostream>

// 实验：继承体系有虚函数的析构关系

// 普通继承
class CBase
{
public:
    ~CBase()
    {
	std::cout << "~CBase() called" << std::endl;
    }
};

class CDerived : public CBase
{
public:
    ~CDerived()
    {
	std::cout << "~CDerived() called" << std::endl;
    }
};

// 有虚函数的继承
class CBaseV
{
public:
    virtual ~CBaseV()
    {
	std::cout << "~CBaseV() called" << std::endl;
    }
};

class CDerivedV : public CBaseV
{
public:
    virtual ~CDerivedV()
    {
	std::cout << "~CDerivedV() called" << std::endl;
    }
};

// 子类不声明虚函数
class CDerivedVI : public CBaseV
{
public:
    ~CDerivedVI()
    {
	std::cout << "~CDerivedVI() called" << std::endl;
    }
};

// 父类不声明虚函数，但子类声明
class CDerivedVII : public CBase
{
public:
    virtual ~CDerivedVII()
    {
	std::cout << "~CDerivedVII() called" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    {
	CBase* pBase = new CBase;
	CBase* pBDerive = new CDerived;
	CDerived* pDerive = new CDerived;

	delete pBase;
	delete pBDerive;
	delete pDerive;
    }
    std::cout << std::endl;

    {
	CBaseV* pBase = new CBaseV;
	CBaseV* pBDerive = new CDerivedV;
	CDerivedV* pDerive = new CDerivedV;

	delete pBase;
	delete pBDerive;
	delete pDerive;
    }
    std::cout << std::endl;

    // 也正常，子类自动成为虚函数
    {
	CBaseV* pBDerive = new CDerivedVI;
	delete pBDerive;
    }
    std::cout << std::endl;

    // 不正常，只能析构父类
    {
	CBase* pBDerive = new CDerivedVII;
	delete pBDerive;
    }
    std::cout << std::endl;

    // 也正常，按常规先析构自己再析构父类
    {
	CDerivedVII* pDerive = new CDerivedVII;
	delete pDerive;
    }
    std::cout << std::endl;
}
