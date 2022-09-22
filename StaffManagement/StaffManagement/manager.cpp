#include "manager.h"

Manager::Manager(int id, string name, int departmentId)
{
	this->id = id;
	this->name = name;
	this->departmentId = departmentId;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getdepartmentName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getdepartmentName()
{
	return string("经理");
}