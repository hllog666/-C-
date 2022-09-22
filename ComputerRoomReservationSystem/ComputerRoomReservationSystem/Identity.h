#pragma once
#include <iostream>
using namespace std;
#include <string>

class Identity
{
public:
	virtual void operatorMenu() = 0;

	string name;
	string password;
};