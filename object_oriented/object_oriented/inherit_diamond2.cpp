#include <iostream>
using namespace std;

class Animal
{
public:
	int age;
};

class Sheep :virtual public Animal
{
public:
};

class Camel :virtual public Animal
{
public:
};

class Alpaca :public Sheep, public Camel
{
public:
};

void test01()
{
	Alpaca alpaca;
	alpaca.age = 10;
	cout << alpaca.age << endl;
}

int main()
{
	test01();

	return 0;
}