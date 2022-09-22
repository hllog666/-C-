#include "boss.h"

Boss::Boss(int id, string name, int departmentId)
{
	this->id = id;
	this->name = name;
	this->departmentId = departmentId;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getdepartmentName()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getdepartmentName()
{
	return "总裁";
}