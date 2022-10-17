#include <iostream>
using namespace std;
#include <string>

class Building;

class GoodGay
{
public:
	GoodGay();

	void visit();

	Building* building;
};

class Building
{
	friend class GoodGay;

public:
	Building();

	string sittingRoom;

private:
	string bedRoom;
};

Building::Building()
{
	sittingRoom = "¿ÍÌü";
	bedRoom = "ÎÔÊÒ";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << building->sittingRoom << endl;
	cout << building->bedRoom << endl;
}

void test01()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test01();

	return 0;
}