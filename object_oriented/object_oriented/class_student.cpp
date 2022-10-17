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
		cout << "姓名：" << name << " 学号：" << id << endl;
	}
};

int main()
{
	Student s;
	s.name = "张三";
	s.id = 1;
	s.showStudent();

	return 0;
}