#include <iostream>
using namespace std;

int main()
{
	cout << "111111111" << endl;
	goto FLAG;
	cout << "222222222" << endl;
	cout << "333333333" << endl;
	FLAG:
	cout << "444444444" << endl;
	cout << "555555555" << endl;

	return 0;
}