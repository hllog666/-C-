#include <iostream>
using namespace std;
#include <string>
#include "Person.cpp"

void test01()
{
	Person<string, int> p("Tom", 10);
	p.showPerson();
}

int main()
{
	test01();

	return 0;
}