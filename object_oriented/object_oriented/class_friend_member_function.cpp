#include <iostream>
using namespace std;
#include <string>

class Building;

class GoodGay
{
public:
	GoodGay();

	void visit();
	void visit2();

	Building* building;
};

class Building
{
	friend void GoodGay::visit();

public:
	Building();

	string sittingRoom;
private:
	string bedRoom;
};

Building::Building()
{
	sittingRoom = "øÕÃ¸";
	bedRoom = "Œ‘ “";
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

void GoodGay::visit2()
{
	cout << building->sittingRoom << endl;
	// cout << building->bedRoom << endl;
}

void test01()
{
	GoodGay gg;
	gg.visit();
	cout << "----" << endl;
	gg.visit2();
}

int main()
{
	test01();

	return 0;
}