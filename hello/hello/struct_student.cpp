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
	s1.name = "����";
	s1.age = 43;
	s1.score = 60;

	struct Student s2 = { "����",20,100 };

	printStudent(s1);
	printStudent(s2);

	return 0;
}

void printStudent(struct Student& s)
{
	cout << "���֣�" << s.name << "�����䣺" << s.age << "��������" << s.score << endl;
}