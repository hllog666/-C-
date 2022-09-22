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
	struct Student stuArr[] =
	{
		{"张三",20,100},
		{"李四",26,64},
		{"王五",18,75}
	};

	int len = sizeof(stuArr) / sizeof(stuArr[0]);
	for (int i = 0; i < len; i++) {
		printStudent(stuArr[i]);
	}

	return 0;
}

void printStudent(struct Student& s)
{
	cout << "名字：" << s.name << "，年龄：" << s.age << "，分数：" << s.score << endl;
}