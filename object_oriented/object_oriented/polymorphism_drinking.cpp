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
		cout << "��ũ��ɽȪ" << endl;
	}

	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}

	virtual void PureInCup()
	{
		cout << "���뱭��" << endl;
	}

	virtual void PutSomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}
};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "������" << endl;
	}

	virtual void Brew()
	{
		cout << "�ݲ�" << endl;
	}

	virtual void PureInCup()
	{
		cout << "���뱭��" << endl;
	}

	virtual void PutSomething()
	{
		cout << "�������" << endl;
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