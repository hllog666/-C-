#include <iostream>
using namespace std;

class Animal
{
public:
	int age;
};

class Sheep :public Animal
{
public:
};

class Camel :public Animal
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
	alpaca.Sheep::age = 10;
	alpaca.Camel::age = 20;
	cout << alpaca.Sheep::age << endl;
	cout << alpaca.Camel::age << endl;
}

int main()
{
	test01();

	return 0;
}