#include <iostream>
using namespace std;
#include <string>

class Animal
{
public:
	Animal()
	{
		cout << "Animal���캯��" << endl;
	}

	/*virtual ~Animal()
	{
		cout << "Animal��������" << endl;
	}*/

	virtual ~Animal() = 0;

	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout << "Animal��������" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat���캯��" << endl;
		this->name = new string(name);
	}

	virtual void speak()
	{
		cout << "Сè��˵��" << endl;
	}

	~Cat()
	{
		if (name != nullptr)
		{
			cout << "Cat��������" << endl;
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