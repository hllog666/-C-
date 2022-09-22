#include <iostream>
using namespace std;
#include <string>

struct Hero
{
	string name;
	int age;
	string sex;
};

void bubbleSort(struct Hero heroArr[], int len);
void printHero(struct Hero heroArr[], int len);

int main()
{
	struct Hero heroArr[] =
	{
		"����",23,"��",
		"����",22,"��",
		"�ŷ�",20,"��",
		"����",21,"��",
		"����",19,"Ů"
	};
	int len = sizeof(heroArr) / sizeof(heroArr[0]);
	printHero(heroArr, len);
	cout << "-------------------" << endl;

	bubbleSort(heroArr, len);
	printHero(heroArr, len);

	return 0;
}

void bubbleSort(struct Hero heroArr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (heroArr[j].age > heroArr[j + 1].age)
			{
				struct Hero temp = heroArr[j];
				heroArr[j] = heroArr[j + 1];
				heroArr[j + 1] = temp;
			}
		}
	}
}

void printHero(struct Hero heroArr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "������" << heroArr[i].name << " ���䣺" << heroArr[i].age
			<< " �Ա�" << heroArr[i].sex << endl;
	}
}