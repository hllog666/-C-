#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	friend ostream& operator<<(ostream& cout, const Person& p);

	bool operator==(const Person& p)
	{
		return (this->name == p.name && this->age == p.age);
	}

	string name;
	int age;
};

ostream& operator<<(ostream& cout, const Person& p)
{
	cout << p.name << p.age;
	return cout;
}

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

class GreaterThirty
{
public:
	bool operator()(Person p)
	{
		return p.age > 30;
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	auto pos = find_if(v.begin(), v.end(), GreaterFive());
	if (pos == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了" << endl;
		cout << *pos << endl;
	}
}

void test02()
{
	vector<Person> v;
	Person p1("A", 10);
	Person p2("B", 20);
	Person p3("C", 30);
	Person p4("D", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	auto pos = find_if(v.begin(), v.end(), GreaterThirty());
	if (pos == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了" << endl;
		cout << *pos << endl;
	}
}

int main()
{
	test01();
	test02();

	return 0;
}