#include <iostream>
using namespace std;

// ʹ��visual studio�Ŀ���������ʾ����
// cl /d1 reportSingleClassLayoutSon "inherit_object_model.cpp"
class Base
{
public:
	int a;
protected:
	int b;
private:
	int c;
};

class Son :public Base
{
public:
	int d;
};

void test01()
{
	cout << sizeof(Base) << endl;
	cout << sizeof(Son) << endl;
}

int main()
{
	test01();

	return 0;
}