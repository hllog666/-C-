#include <iostream>
using namespace std;
#include <string>

struct Student
{
	string name;
	int age;
	int score;
};

struct Teacher
{
	int id;
	string name;
	int age;
	struct Student stu;
};

void printTeacher(struct Teacher& t);

int main()
{
	struct Student s = { "小王",20,100 };
	Teacher t = { 1,"老王",50,s };
	printTeacher(t);

	return 0;
}

void printTeacher(struct Teacher& t)
{
	cout << "id = " << t.id << ", name = " << t.name << ", age = "
		<< t.age << ", s.name = " << t.stu.name << ", s.age = " << t.stu.age
		<< ", s.score = " << t.stu.score << endl;
}