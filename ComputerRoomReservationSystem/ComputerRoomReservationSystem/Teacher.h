#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include "Order.h"
#include <vector>

class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int id, string name, string password);

	virtual void operatorMenu();

	void showAllOrder();

	void validOrder();

	int id;

};