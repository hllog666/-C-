#include <iostream>
using namespace std;

// 浅拷贝的问题：可能会释放同一块内存
class Person
{
public:
	Person()
	{
		cout << "构造函数" << endl;
	}

	Person(int age, int height)
	{
		this->age = age;
		this->height = new int(height);
		cout << "有参构造函数" << endl;
	}

	Person(const Person& p)
	{
		this->age = p.age;
		this->height = new int(*p.height);
	}

	~Person()
	{
		if (height != nullptr)
		{
			delete height;
			height = nullptr;
		}
		cout << "析构函数" << endl;
	}

	int age;
	int* height;
};

void test01()
{
	Person p1(18, 180);
	cout << "p1.age = " << p1.age << " p1.height = " << *p1.height << endl;

	Person p2(p1);
	cout<< "p2.age = " << p2.age << " p2.height = " << *p2.height << endl;

	p1.age = 20;
	*p1.height = 190;
	cout << "p1.age = " << p1.age << " p1.height = " << *p1.height << endl;
	cout << "p2.age = " << p2.age << " p2.height = " << *p2.height << endl;
}

int main()
{
	test01();

	return 0;
}