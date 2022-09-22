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
		"刘备",23,"男",
		"关羽",22,"男",
		"张飞",20,"男",
		"赵云",21,"男",
		"貂蝉",19,"女"
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
		cout << "姓名：" << heroArr[i].name << " 年龄：" << heroArr[i].age
			<< " 性别：" << heroArr[i].sex << endl;
	}
}