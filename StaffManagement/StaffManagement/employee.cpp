#include "employee.h"

Employee::Employee(int id, string name, int departmentId)
{
	this->id = id;
	this->name = name;
	this->departmentId = departmentId;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getdepartmentName()
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::getdepartmentName()
{
	return string("Ա��");
}