#include <iostream>
using namespace std;
#include <string>

// public�����ڿ��Է��ʣ�������Է���
// protected�����ڿ��Է��ʣ����ⲻ�ܷ��ʣ�������Է���
// private�����ڿ��Է��ʣ����ⲻ�ܷ��ʣ����಻�ܷ���
class Person
{
public:
	string name;

protected:
	string car;

private:
	int password;

public:
	void func()
	{
		name = "����";
		car = "���г�";
		password = 123;
	}
};

int main()
{
	Person p;
	p.name = "����";
	// p.car = "����";
	// p.password = 243;

	return 0;
}