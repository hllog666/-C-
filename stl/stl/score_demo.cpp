#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <ctime>

class Person
{
public:
	Person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}

	string name;
	int score;
};

void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "Ñ¡ÊÖ";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int sum = 0;
		for (auto dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		it->score = avg;
	}
}

void printVector(vector<Person>& v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << it->name << it->score << endl;
	}
}

void test01()
{
	vector<Person> v;
	createPerson(v);
	printVector(v);
	setScore(v);
	printVector(v);
}

int main()
{
	srand((unsigned)time(NULL));
	test01();

	return 0;
}