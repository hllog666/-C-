#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

class Boss :public Worker
{
public:
	Boss(int id, string name, int departmentId);

	virtual void showInfo();

	virtual string getdepartmentName();
};