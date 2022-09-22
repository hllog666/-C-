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
	struct Student s1;
	s1.name = "李四";
	s1.age = 43;
	s1.score = 60;

	struct Student s2 = { "张三",20,100 };

	printStudent(s1);
	printStudent(s2);

	return 0;
}

void printStudent(struct Student& s)
{
	cout << "名字：" << s.name << "，年龄：" << s.age << "，分数：" << s.score << endl;
}