#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "GlobalFile.h"
#include <fstream>
#include <string>

class OrderFile
{
public:
	OrderFile();

	void updateOrder();

	map<int, map<string, string>>orderData;
	int size;
};