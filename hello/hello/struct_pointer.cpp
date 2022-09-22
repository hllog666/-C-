#include <iostream>
using namespace std;
#include <string>

struct Student
{
	string name;
	int age;
	int score;
};

void printStudent(struct Student& s);

int main()
{
	struct Student s = { "张三",20,100 };
	struct Student* p = &s;
	p->age = 30;
	printStudent(s);

	return 0;
}

void printStudent(struct Student& s)
{
	cout << "名字：" << s.name << "，年龄：" << s.age << "，分数：" << s.score << endl;
}