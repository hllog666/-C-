#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>
#include <ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string name;
	int salary;
};

void createWorker(vector<Worker>& vWorker)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.name = "员工";
		worker.name += nameSeed[i];
		worker.salary = rand() % 10000 + 10000;
		vWorker.push_back(worker);
	}
}

void printWorkerVecotr(const vector<Worker>& vWorker)
{
	for (auto it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << it->name << it->salary << endl;
	}
}

void setGroup(vector<Worker>& vWorker, multimap<int, Worker>& mWorker)
{
	for (auto it = vWorker.begin(); it != vWorker.end(); it++)
	{
		int deptId = rand() % 3;
		mWorker.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGroup(const multimap<int, Worker>& mWorker)
{
	cout << "-----------" << endl;
	cout << "策划部门：" << endl;
	auto pos = mWorker.find(CEHUA);
	int count = mWorker.count(CEHUA);
	int index = 0;
	for (; pos != mWorker.end() && index < count; pos++, index++)
	{
		cout << pos->second.name << pos->second.salary << endl;
	}

	cout << "-----------" << endl;
	cout << "美术部门：" << endl;
	pos = mWorker.find(MEISHU);
	count = mWorker.count(MEISHU);
	index = 0;
	for (; pos != mWorker.end() && index < count; pos++, index++)
	{
		cout << pos->second.name << pos->second.salary << endl;
	}

	cout << "-----------" << endl;
	cout << "研发部门：" << endl;
	pos = mWorker.find(YANFA);
	count = mWorker.count(YANFA);
	index = 0;
	for (; pos != mWorker.end() && index < count; pos++, index++)
	{
		cout << pos->second.name << pos->second.salary << endl;
	}
}

void test01()
{
	vector<Worker> vWorker;
	createWorker(vWorker);
	printWorkerVecotr(vWorker);
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);
	showWorkerByGroup(mWorker);
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();

	return 0;
}