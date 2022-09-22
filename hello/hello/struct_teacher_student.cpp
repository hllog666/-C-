#include <iostream>
using namespace std;
#include <string>
#include <ctime>

struct Student
{
	string name;
	int score;
};

struct Teacher
{
	string name;
	struct Student stuArr[5];
};

void allocateSpace(struct Teacher tArr[], int len);
void printInfo(struct Teacher tArr[], int len);

int main()
{
	srand((unsigned int)time(NULL));

	struct Teacher tArr[3];
	int len = sizeof(tArr) / sizeof(tArr[0]);
	allocateSpace(tArr, len);
	printInfo(tArr, len);

	return 0;
}

void allocateSpace(struct Teacher tArr[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tArr[i].name = "Teacher_";
		tArr[i].name += nameSeed[i];

		for (int j = 0; j < 5; j++)
		{
			tArr[i].stuArr[j].name = "Student_";
			tArr[i].stuArr[j].name += nameSeed[i];

			int random = rand() % 61 + 40;
			tArr[i].stuArr[j].score = random;
		}
	}
}

void printInfo(struct Teacher tArr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名：" << tArr[i].name << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << "学生姓名：" << tArr[i].stuArr[j].name 
				<< "考试分数：" << tArr[i].stuArr[j].score << endl;
		}
	}
}