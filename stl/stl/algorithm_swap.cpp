#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i * 100);
	}
	for_each(v1.begin(), v1.end(), [](int val)->void {cout << val << endl; });
	for_each(v2.begin(), v2.end(), [](int val)->void {cout << val << endl; });
	cout << endl;

	swap(v1, v2);
	for_each(v1.begin(), v1.end(), [](int val)->void {cout << val << endl; });
	for_each(v2.begin(), v2.end(), [](int val)->void {cout << val << endl; });
	cout << endl;
}

int main()
{
	test01();

	return 0;
}