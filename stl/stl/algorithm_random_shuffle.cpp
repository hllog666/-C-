#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <ctime>

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int v)->void {cout << v << endl; });
}

int main()
{
	srand((unsigned)time(NULL));
	test01();

	return 0;
}