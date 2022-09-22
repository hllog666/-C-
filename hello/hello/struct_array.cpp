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
		{"����",20,100},
		{"����",26,64},
		{"����",18,75}
	};

	int len = sizeof(stuArr) / sizeof(stuArr[0]);
	for (int i = 0; i < len; i++) {
		printStudent(stuArr[i]);
	}

	return 0;
}

void printStudent(struct Student& s)
{
	cout << "���֣�" << s.name << "�����䣺" << s.age << "��������" << s.score << endl;
}