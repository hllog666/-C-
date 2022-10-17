#include <iostream>
using namespace std;

// 成员默认为private
class C1
{
	int a;
};

// 成员默认为public
struct C2
{
	int a;
};

int main()
{
	C1 c1;
	// c1.a = 100;

	C2 c2;
	c2.a = 100;

	return 0;
}