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
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	ifs.close();
	cout << p.age << p.name << endl;
}

int main()
{
	test01();

	return 0;
}