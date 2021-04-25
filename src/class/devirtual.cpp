#include <iostream>

// ʵ�飺�̳���ϵ���麯����������ϵ

// ��ͨ�̳�
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

// ���麯���ļ̳�
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

// ���಻�����麯��
class CDerivedVI : public CBaseV
{
public:
    ~CDerivedVI()
    {
	std::cout << "~CDerivedVI() called" << std::endl;
    }
};

// ���಻�����麯��������������
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

    // Ҳ�����������Զ���Ϊ�麯��
    {
	CBaseV* pBDerive = new CDerivedVI;
	delete pBDerive;
    }
    std::cout << std::endl;

    // ��������ֻ����������
    {
	CBase* pBDerive = new CDerivedVII;
	delete pBDerive;
    }
    std::cout << std::endl;

    // Ҳ�������������������Լ�����������
    {
	CDerivedVII* pDerive = new CDerivedVII;
	delete pDerive;
    }
    std::cout << std::endl;
}
