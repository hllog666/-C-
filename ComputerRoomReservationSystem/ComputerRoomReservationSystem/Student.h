#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <vector>
#include "ComputerRoom.h"
#include <fstream>
#include "GlobalFile.h"
#include "Order.h"

class Student :public Identity
{
public:
	Student();

	Student(int id, string name, string password);

	virtual void operatorMenu();

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	int id;
	vector<ComputerRoom> computerRoom;
};