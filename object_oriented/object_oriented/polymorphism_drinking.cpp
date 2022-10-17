#include <iostream>
using namespace std;

class AbstractDrinking
{
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void PureInCup() = 0;
	virtual void PutSomething() = 0;
	void makeDrink()
	{
		Boil();
		Brew();
		PureInCup();
		PutSomething();
	}
};

class Coffee :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "ÖóÅ©·òÉ½Èª" << endl;
	}

	virtual void Brew()
	{
		cout << "³åÅÝ¿§·È" << endl;
	}

	virtual void PureInCup()
	{
		cout << "µ¹Èë±­ÖÐ" << endl;
	}

	virtual void PutSomething()
	{
		cout << "¼ÓÈëÌÇºÍÅ£ÄÌ" << endl;
	}
};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "Öóâù±¦" << endl;
	}

	virtual void Brew()
	{
		cout << "ÅÝ²è" << endl;
	}

	virtual void PureInCup()
	{
		cout << "µ¹Èë±­ÖÐ" << endl;
	}

	virtual void PutSomething()
	{
		cout << "¼ÓÈëèÛè½" << endl;
	}
};

void work(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;
}

void test01()
{
	work(new Coffee);
}

int main()
{
	test01();

	return 0;
}