#include <iostream>
using namespace std;
#include <string>

class Building
{
	friend void goodGay(Building* building);

public:
	Building()
	{
		sittingRoom = "¿ÍÌü";
		bedRoom = "ÎÔÊÒ";
	}

	string sittingRoom;

private:
	string bedRoom;
};

void goodGay(Building* building)
{
	cout << building->sittingRoom << endl;
	cout << building->bedRoom << endl;
}

void test01()
{
	Building building;
	goodGay(&building);
}

int main()
{
	test01();

	return 0;
}