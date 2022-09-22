#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class MyGreaterFive
{
public:
	bool operator()(int v)
	{
		return v > 5;
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	auto it = find_if(v.begin(), v.end(), MyGreaterFive());
	if (it == v.end())
	{
		cout << "Î´ÕÒµ½" << endl;
	}
	else
	{
		cout << *it << endl;
	}
}

int main()
{
	test01();

	return 0;
}