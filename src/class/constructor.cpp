#include <iostream>

// 实验：对象构造顺序

class CBase
{
public:
    CBase()
    {
	std::cout << "CBase() called" << std::endl;
    }
};

// 继承
// 先构造父类，再构造子类
class CDerived : public CBase
{
public:
    CDerived()
    {
	std::cout << "CDerived() called" << std::endl;
    }
};

// 组合
// 先构造成员，再构造本身
class CComposite
{
public:
    CComposite()
    {
	std::cout << "CComposite() called" << std::endl;
    }
private:
    CBase m_base;
};

// 组合，成员对象本身有父类
// 先构造成员（如有父类先构造其父类），再构造本身
class CCompositeSub
{
public:
    CCompositeSub()
    {
	std::cout << "CCompositeSub() called" << std::endl;
    }
private:
    CDerived m_derived;
};

// 另一个类
class CBaseA
{
public:
    CBaseA()
    {
	std::cout << "CBaseA() called" << std::endl;
    }
};

// 既有成员对象也有父类
// 先构造父类，再构造成员，再构造自身
class CCompositeDer : public CBase
{
    public:
	CCompositeDer()
	{
	    std::cout << "CCompositeDer() called" << std::endl;
	}
    private:
	CBaseA m_baseA;
};

// 多个成员对象
class CCompositeMore
{
public:
    CCompositeMore()
    {
	std::cout << "CCompositeMore() called" << std::endl;
    }
private:
    CBase m_base;
    CBaseA m_baseA;
};

// 显式指定成员对象初始化
// 成员构造顺序按声明顺序，而非构造函数的初始化列表
class CCompositeInit
{
public:
    CCompositeInit() : m_baseA(), m_base()
    {
	std::cout << "CCompositeInit() called" << std::endl;
    }
private:
    CBase m_base;
    CBaseA m_baseA;
};

int main(int argc, char* argv[])
{

    std::cout << "CBase base: " << std::endl;
    CBase base;
    std::cout << std::endl;

    std::cout << "CDerived derived: " << std::endl;
    CDerived derived;
    std::cout << std::endl;

    std::cout << "CComposite composite: " << std::endl;
    CComposite composite;
    std::cout << std::endl;

    std::cout << "CCompositeSub compositeSub: " << std::endl;
    CCompositeSub compositeSub;
    std::cout << std::endl;

    std::cout << "CCompositeDer compositeDer: " << std::endl;
    CCompositeDer compositeDer;
    std::cout << std::endl;

    std::cout << "CCompositeMore compositeMore: " << std::endl;
    CCompositeMore compositeMore;
    std::cout << std::endl;

    std::cout << "CCompositeInit compositeInit: " << std::endl;
    CCompositeInit compositeInit;
    std::cout << std::endl;

}

/* output:
CBase base:
CBase() called

CDerived derived:
CBase() called
CDerived() called

CComposite composite:
CBase() called
CComposite() called

CCompositeSub compositeSub:
CBase() called
CDerived() called
CCompositeSub() called

CCompositeDer compositeDer:
CBase() called
CBaseA() called
CCompositeDer() called

CCompositeMore compositeMore:
CBase() called
CBaseA() called
CCompositeMore() called

CCompositeInit compositeInit:
CBase() called
CBaseA() called
CCompositeInit() called
*/
