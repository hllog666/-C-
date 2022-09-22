#include <iostream>
using namespace std;
#include <string>

struct Student
{
	string name;
	int age;
	int score;
};

void printStudent(struct Student* s);

int main()
{
	struct  Student s = { "ÕÅÈı",20,100 };
	cout << "[main] name = " << s.name << ", age = " << s.age << ", score = " << s.score << endl;
	printStudent(&s);

	return 0;
}

void printStudent(struct Student* s)
{
	cout << "[printStudent] name = " << s->name << ", age = " << s->age << ", score = " << s->score << endl;
}