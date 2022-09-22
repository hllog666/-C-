#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <fstream>
#include "GlobalFile.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
#include "ComputerRoom.h"

class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string password);

	virtual void operatorMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	void initVector();

	bool checkRepeat(int id, int type);

	vector<Student> student;
	vector<Teacher> teacher;
	vector<ComputerRoom> computerRoom;
};