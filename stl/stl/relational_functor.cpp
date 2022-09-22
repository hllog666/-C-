#include <iostream>
using namespace std;
#include <functional>
#include <vector>
#include <algorithm>

void printVector(const vector<int>& v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	printVector(v);

	sort(v.begin(), v.end(), MyCompare());
	printVector(v);
}

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	printVector(v);

	sort(v.begin(), v.end(), greater<int>());
	printVector(v);
}

int main()
{
	test01();
	test02();

	return 0;
}