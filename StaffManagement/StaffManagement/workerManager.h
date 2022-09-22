#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();

	void showMenu();

	void exitSystem();

	void addEmp();

	void save();

	int getEmpNum();

	void initEmp();

	void showEmp();

	void delEmp();

	int isExist(int id);

	void modEmp();

	void findEmp();

	void sortEmp();

	void cleanFile();

	~WorkerManager();

	int empNum;
	Worker** empArray;
	bool isFileEmpty;
};