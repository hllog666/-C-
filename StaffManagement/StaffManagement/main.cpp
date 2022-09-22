#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"

int main()
{
	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		wm.showMenu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ£º" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.addEmp();
			break;
		case 2:
			wm.showEmp();
			break;
		case 3:
			wm.delEmp();
			break;
		case 4:
			wm.modEmp();
			break;
		case 5:
			wm.findEmp();
			break;
		case 6:
			wm.sortEmp();
			break;
		case 7:
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}