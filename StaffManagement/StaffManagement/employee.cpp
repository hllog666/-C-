#include "employee.h"

Employee::Employee(int id, string name, int departmentId)
{
	this->id = id;
	this->name = name;
	this->departmentId = departmentId;
}

void Employee::showInfo()
{
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getdepartmentName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getdepartmentName()
{
	return string("员工");
}