#include <iostream>
using namespace std;
#include <stack>

void test01()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	cout << s.size() << endl;
}

int main()
{
	test01();

	return 0;
}