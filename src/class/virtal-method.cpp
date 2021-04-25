#include <iostream>

// 实验：虚方法继承多态

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

    virtual void Step1()
    {
	std::cout << "CBase::Step1() called" << std::endl;
    }
    virtual void Step2()
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
CDerived::Step1() called
CBase::Step2() called
CBase::Process() Exit

derived.Step1()
CDerived::Step1() called

pbd->Step1()
CDerived::Step1() called
*/

