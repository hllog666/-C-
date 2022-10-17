#include <iostream>
using namespace std;
#include <fstream>

class Person
{
public:
	char name[64];
	int age;
};

void test01()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "уехЩ",10 };
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}

int main()
{
	test01();

	return 0;
}