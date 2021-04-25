#include <iostream>

// ʵ�飺������˳��

class CBase
{
public:
    CBase()
    {
	std::cout << "CBase() called" << std::endl;
    }
};

// �̳�
// �ȹ��츸�࣬�ٹ�������
class CDerived : public CBase
{
public:
    CDerived()
    {
	std::cout << "CDerived() called" << std::endl;
    }
};

// ���
// �ȹ����Ա���ٹ��챾��
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

// ��ϣ���Ա�������и���
// �ȹ����Ա�����и����ȹ����丸�ࣩ���ٹ��챾��
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

// ��һ����
class CBaseA
{
public:
    CBaseA()
    {
	std::cout << "CBaseA() called" << std::endl;
    }
};

// ���г�Ա����Ҳ�и���
// �ȹ��츸�࣬�ٹ����Ա���ٹ�������
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

// �����Ա����
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

// ��ʽָ����Ա�����ʼ��
// ��Ա����˳������˳�򣬶��ǹ��캯���ĳ�ʼ���б�
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
