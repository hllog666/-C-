#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	int getAge()
	{
		return age;
	}

	void setLover(string lover)
	{
		this->lover = lover;
	}

private:
	string name;
	int age;
	string lover;
};

int main()
{
	Person p;
	p.setName("张三");
	p.setLover("如花");

	cout << "姓名：" << p.getName() << endl;
	cout << "年龄：" << p.getAge() << endl;

	return 0;
}