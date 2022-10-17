#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

void Speak(Animal& animal)
{
	animal.speak();
}

void test01()
{
	Cat cat;
	Speak(cat);

	Dog dog;
	Speak(dog);
}

int main()
{
	test01();

	return 0;
}