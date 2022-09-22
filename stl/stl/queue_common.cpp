#include <iostream>
using namespace std;
#include <queue>

void test01()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	cout << q.size() << endl;
}

int main()
{
	test01();

	return 0;
}