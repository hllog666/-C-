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
	//����ְ������������
	this->empArray = new Worker * [this->empNum];
	//��ʼ��ְ��
	initEmp();
}

void WorkerManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********   ��ӭʹ��ְ������ϵͳ   *********" << endl;
	cout << "*************  0.�˳�����ϵͳ  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp()
{
	cout << "���������ְ��������" << endl;
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
			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ܲ�" << endl;
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
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		this->save();
	}
	else
	{
		cout << "��������" << endl;
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
		//��¼����
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
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (departmentId == 1)  // 1��ͨԱ��
		{
			worker = new Employee(id, name, departmentId);
		}
		else if (departmentId == 2) //2����
		{
			worker = new Manager(id, name, departmentId);
		}
		else //�ܲ�
		{
			worker = new Boss(id, name, departmentId);
		}
		//�����������
		this->empArray[index] = worker;
		index++;
	}
}

void WorkerManager::showEmp()
{
	if (this->isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < empNum; i++)
		{
			//���ö�̬���ýӿ�
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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//��ְ�����ɾ��
		cout << "��������Ҫɾ����ְ���ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1)  //˵��index��λ��������Ҫɾ��
		{
			for (int i = index; i < this->empNum - 1; i++)
			{
				this->empArray[i] = this->empArray[i + 1];
			}
			this->empNum--;

			this->save(); //ɾ��������ͬ�����ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��

			delete this->empArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

			//�������� ��������
			this->empArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	//������� ����
	system("pause");
	system("cls");
}

void WorkerManager::findEmp()
{
	if (this->isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) //��ְ���Ų���
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = isExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->empArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) //����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;  //���ҵ��ı�־
			for (int i = 0; i < empNum; i++)
			{
				if (empArray[i]->name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ��"
						<< empArray[i]->id
						<< " �ŵ���Ϣ���£�" << endl;

					flag = true;

					this->empArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}


	system("pause");
	system("cls");
}

void WorkerManager::sortEmp()
{
	if (this->isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < empNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < empNum; j++)
			{
				if (select == 1) //����
				{
					if (empArray[minOrMax]->id > empArray[j]->id)
					{
						minOrMax = j;
					}
				}
				else  //����
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

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->showEmp();
	}
}

void WorkerManager::cleanFile()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;
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