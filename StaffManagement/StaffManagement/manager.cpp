#include "manager.h"

Manager::Manager(int id, string name, int departmentId)
{
	this->id = id;
	this->name = name;
	this->departmentId = departmentId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getdepartmentName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getdepartmentName()
{
	return string("����");
}