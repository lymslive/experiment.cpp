#include <iostream>

// 实验：普通方法继承重载

class CBase
{
public:
    void Init()
    {
	std::cout << "CBase::Init() called" << std::endl;
    }

    void Process()
    {
	std::cout << "CBase::Process() Enter" << std::endl;
	Step1();
	Step2();
	std::cout << "CBase::Process() Exit" << std::endl;
    }

    void Step1()
    {
	std::cout << "CBase::Step1() called" << std::endl;
    }
    void Step2()
    {
	std::cout << "CBase::Step2() called" << std::endl;
    }
};

class CDerived : public CBase
{
public:
    void Step1()
    {
	std::cout << "CDerived::Step1() called" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    CBase base;
    CDerived derived;

    std::cout << "base.Init()" << std::endl;
    base.Init();
    std::cout << std::endl;

    std::cout << "derived.Init()" << std::endl;
    derived.Init();
    std::cout << std::endl;

    std::cout << "base.Process()" << std::endl;
    base.Process();
    std::cout << std::endl;

    std::cout << "derived.Process()" << std::endl;
    derived.Process();
    std::cout << std::endl;

    std::cout << "derived.Step1()" << std::endl;
    derived.Step1();
    std::cout << std::endl;

    CBase* pbd = &derived;
    std::cout << "pbd->Step1()" << std::endl;
    pbd->Step1();
    std::cout << std::endl;
}

/*
base.Init()
CBase::Init() called

derived.Init()
CBase::Init() called

base.Process()
CBase::Process() Enter
CBase::Step1() called
CBase::Step2() called
CBase::Process() Exit

derived.Process()
CBase::Process() Enter
CBase::Step1() called
CBase::Step2() called
CBase::Process() Exit

derived.Step1()
CDerived::Step1() called

pbd->Step1()
CBase::Step1() called
*/

/*
 * 子类调用 Process ，进入了父类的命名空间，在其内调用的 Step 方法仍是父类的，
 * 没法调用子类的，虚函数才能处理这种多态行为
 */
