#include <iostream>
using namespace std;

const double PI = 3.14;

class Circle
{
public:
	double r;
	double calculatePerimeter()
	{
		return 2 * PI * r * r;
	}
};

int main()
{
	Circle c;
	c.r = 10;
	double perimeter = c.calculatePerimeter();
	cout << perimeter << endl;

	return 0;
}