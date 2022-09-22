#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 8);
	cout << ret << endl;
}

int main()
{
	test01();

	return 0;
}