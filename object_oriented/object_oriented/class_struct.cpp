#include <iostream>
using namespace std;

// ��ԱĬ��Ϊprivate
class C1
{
	int a;
};

// ��ԱĬ��Ϊpublic
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