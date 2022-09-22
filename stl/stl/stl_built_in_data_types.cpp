#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void myPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "-----------" << endl;

	for_each(v.begin(), v.end(), myPrint);
}

int main()
{
	test01();

	return 0;
}