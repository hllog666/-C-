#include <iostream>
using namespace std;
#include <string>

class Student
{
public:
	string name;
	int id;

	void showStudent()
	{
		cout << "������" << name << " ѧ�ţ�" << id << endl;
	}
};

int main()
{
	Student s;
	s.name = "����";
	s.id = 1;
	s.showStudent();

	return 0;
}