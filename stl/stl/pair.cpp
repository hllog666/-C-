#include <iostream>
using namespace std;
#include <string>

void test01()
{
	pair<string, int> p("Tom", 10);
	cout << p.first << p.second << endl;

	pair<string, int> p2 = make_pair("Jack", 20);
	cout << p2.first << p2.second << endl;
}

int main()
{
	test01();

	return 0;
}