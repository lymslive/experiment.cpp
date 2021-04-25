#include <iostream>

// 实验：对象析构顺序

class CBase
{
public:
    ~CBase()
    {
	std::cout << "~CBase() called" << std::endl;
    }
};

// 继承
// 先析构子类部分，再析构父类部分
class CDerived : public CBase
{
public:
    ~CDerived()
    {
	std::cout << "~CDerived() called" << std::endl;
    }
};

// 组合
// 先析构自身部分，再析构成员对象部分
class CComposite
{
public:
    ~CComposite()
    {
	std::cout << "~CComposite() called" << std::endl;
    }
private:
    CBase m_base;
};

// 组合，成员对象本身有父类
// 先析构自身部分，再析构成员对象部分及其父类
class CCompositeSub
{
public:
    ~CCompositeSub()
    {
	std::cout << "~CCompositeSub() called" << std::endl;
    }
private:
    CDerived m_derived;
};

// 另一个类
class CBaseA
{
public:
    ~CBaseA()
    {
	std::cout << "~CBaseA() called" << std::endl;
    }
};

// 既有成员对象也有父类
// 先析构自身，再析构成员，再析构父类
class CCompositeDer : public CBase
{
    public:
	~CCompositeDer()
	{
	    std::cout << "~CCompositeDer() called" << std::endl;
	}
    private:
	CBaseA m_baseA;
};

// 多个成员对象
// 先析构自身，然后各成员对象按声明的相反顺序析构
class CCompositeMore
{
public:
    ~CCompositeMore()
    {
	std::cout << "~CCompositeMore() called" << std::endl;
    }
private:
    CBase m_base;
    CBaseA m_baseA;
};

int main(int argc, char* argv[])
{

    // 作用域内多个栈对象离开该作用域时，按声明相反次序析构
    {
	std::cout << "CBase base; then CBaseA baseA: " << std::endl;
	CBase base;
	CBaseA baseA;
    }
    std::cout << std::endl;

    {
	std::cout << "CDerived derived: " << std::endl;
	CDerived derived;
    }
    std::cout << std::endl;

    {
	std::cout << "CComposite composite: " << std::endl;
	CComposite composite;
    }
    std::cout << std::endl;

    {
	std::cout << "CCompositeSub compositeSub: " << std::endl;
	CCompositeSub compositeSub;
    }
    std::cout << std::endl;

    {
	std::cout << "CCompositeDer compositeDer: " << std::endl;
	CCompositeDer compositeDer;
    }
    std::cout << std::endl;

    {
	std::cout << "CCompositeMore compositeMore: " << std::endl;
	CCompositeMore compositeMore;
    }
    std::cout << std::endl;

}

/* output:
CBase base; then CBaseA baseA:
~CBaseA() called
~CBase() called

CDerived derived:
~CDerived() called
~CBase() called

CComposite composite:
~CComposite() called
~CBase() called

CCompositeSub compositeSub:
~CCompositeSub() called
~CDerived() called
~CBase() called

CCompositeDer compositeDer:
~CCompositeDer() called
~CBaseA() called
~CBase() called

CCompositeMore compositeMore:
~CCompositeMore() called
~CBaseA() called
~CBase() called
*/

// 析构顺序正好与构造顺序相反
