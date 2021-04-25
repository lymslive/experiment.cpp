#include <iostream>

// ʵ�飺��������˳��

class CBase
{
public:
    ~CBase()
    {
	std::cout << "~CBase() called" << std::endl;
    }
};

// �̳�
// ���������ಿ�֣����������ಿ��
class CDerived : public CBase
{
public:
    ~CDerived()
    {
	std::cout << "~CDerived() called" << std::endl;
    }
};

// ���
// �����������֣���������Ա���󲿷�
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

// ��ϣ���Ա�������и���
// �����������֣���������Ա���󲿷ּ��丸��
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

// ��һ����
class CBaseA
{
public:
    ~CBaseA()
    {
	std::cout << "~CBaseA() called" << std::endl;
    }
};

// ���г�Ա����Ҳ�и���
// ������������������Ա������������
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

// �����Ա����
// ����������Ȼ�����Ա�����������෴˳������
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

    // �������ڶ��ջ�����뿪��������ʱ���������෴��������
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

// ����˳�������빹��˳���෴
