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

	bool operator==(Person p)
	{
		return this->age == p.age;
	}

	string name;
	int age;
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	int num = count(v.begin(), v.end(), 30);
	cout << num << endl;
}

void test02()
{
	vector<Person> v;
	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 30);
	Person p5("�ܲ�", 40);
	Person p6("�����", 35);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int cnt = count(v.begin(), v.end(), p6);
	cout << cnt << endl;
}

int main()
{
	test01();
	test02();

	return 0;
}