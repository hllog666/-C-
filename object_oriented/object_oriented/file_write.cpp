#include <iostream>
using namespace std;
#include <fstream>

void test01()
{
	ofstream ofs;
	ofs.open("write.txt", ios::out);
	ofs << "Դ��֮�£���������" << endl;
	ofs.close();
}

int main()
{
	test01();

	return 0;
}