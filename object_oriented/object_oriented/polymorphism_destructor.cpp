#include <iostream>
using namespace std;
#include <string>

class Animal
{
public:
	Animal()
	{
		cout << "Animal构造函数" << endl;
	}

	/*virtual ~Animal()
	{
		cout << "Animal析构函数" << endl;
	}*/

	virtual ~Animal() = 0;

	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout << "Animal纯虚析构" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造函数" << endl;
		this->name = new string(name);
	}

	virtual void speak()
	{
		cout << "小猫在说话" << endl;
	}

	~Cat()
	{
		if (name != nullptr)
		{
			cout << "Cat析构函数" << endl;
			delete name;
			name = nullptr;
		}
	}

	string *name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	delete animal;
}

int main()
{
	test01();

	return 0;
}