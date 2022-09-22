#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		this->empNum = 0;
		this->isFileEmpty = true;
		this->empArray = NULL;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->empNum = 0;
		this->isFileEmpty = true;
		this->empArray = NULL;
		ifs.close();
		return;
	}

	int num = this->getEmpNum();
	this->empNum = num;
	//根据职工数创建数组
	this->empArray = new Worker * [this->empNum];
	//初始化职工
	initEmp();
}

void WorkerManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********   欢迎使用职工管理系统   *********" << endl;
	cout << "*************  0.退出管理系统  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp()
{
	cout << "请输入添加职工的数量" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->empNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		if (this->empArray != NULL)
		{
			for (int i = 0; i < this->empNum; ++i)
			{
				newSpace[i] = this->empArray[i];
			}
		}
		for (int i = 0; i < addNum; ++i)
		{
			int id;
			string name;
			int departmentSelect;
			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、总裁" << endl;
			cin >> departmentSelect;

			Worker* worker = NULL;
			switch (departmentSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->empNum + i] = worker;
		}
		delete[] this->empArray;
		this->empArray = newSpace;
		this->empNum = newSize;
		this->isFileEmpty = false;
		cout << "成功添加" << addNum << "名新职工" << endl;

		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->empNum; ++i)
	{
		ofs << this->empArray[i]->id << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->departmentId << endl;
	}
	ofs.close();
}

int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int departmentId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> departmentId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int departmentId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> departmentId)
	{
		Worker* worker = NULL;
		//根据不同的部门Id创建不同对象
		if (departmentId == 1)  // 1普通员工
		{
			worker = new Employee(id, name, departmentId);
		}
		else if (departmentId == 2) //2经理
		{
			worker = new Manager(id, name, departmentId);
		}
		else //总裁
		{
			worker = new Boss(id, name, departmentId);
		}
		//存放在数组中
		this->empArray[index] = worker;
		index++;
	}
}

void WorkerManager::showEmp()
{
	if (this->isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < empNum; i++)
		{
			//利用多态调用接口
			this->empArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::delEmp()
{
	if (this->isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按职工编号删除
		cout << "请输入想要删除的职工号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1)  //说明index上位置数据需要删除
		{
			for (int i = index; i < this->empNum - 1; i++)
			{
				this->empArray[i] = this->empArray[i + 1];
			}
			this->empNum--;

			this->save(); //删除后数据同步到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::isExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->empNum; i++)
	{
		if (this->empArray[i]->id == id)
		{
			index = i;

			break;
		}
	}

	return index;
}

void WorkerManager::modEmp()
{
	if (this->isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			//查找到编号的职工

			delete this->empArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//更改数据 到数组中
			this->empArray[ret] = worker;

			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	//按任意键 清屏
	system("pause");
	system("cls");
}

void WorkerManager::findEmp()
{
	if (this->isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) //按职工号查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = isExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->empArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) //按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < empNum; i++)
			{
				if (empArray[i]->name == name)
				{
					cout << "查找成功,职工编号为："
						<< empArray[i]->id
						<< " 号的信息如下：" << endl;

					flag = true;

					this->empArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}


	system("pause");
	system("cls");
}

void WorkerManager::sortEmp()
{
	if (this->isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < empNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < empNum; j++)
			{
				if (select == 1) //升序
				{
					if (empArray[minOrMax]->id > empArray[j]->id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (empArray[minOrMax]->id < empArray[j]->id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = empArray[i];
				empArray[i] = empArray[minOrMax];
				empArray[minOrMax] = temp;
			}

		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->showEmp();
	}
}

void WorkerManager::cleanFile()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->empArray != NULL)
		{
			for (int i = 0; i < this->empNum; i++)
			{
				if (this->empArray[i] != NULL)
				{
					delete this->empArray[i];
				}
			}
			this->empNum = 0;
			delete[] this->empArray;
			this->empArray = NULL;
			this->isFileEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->empArray != NULL)
	{
		delete[] this->empArray;
		this->empArray = NULL;
	}
}