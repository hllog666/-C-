#include "boss.h"

Boss::Boss(int id, string name, int departmentId)
{
	this->id = id;
	this->name = name;
	this->departmentId = departmentId;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getdepartmentName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::getdepartmentName()
{
	return "�ܲ�";
}