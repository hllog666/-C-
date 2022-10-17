#include <iostream>
using namespace std;
#include <fstream>

void test01()
{
	ofstream ofs;
	ofs.open("write.txt", ios::out);
	ofs << "源码之下，了无秘密" << endl;
	ofs.close();
}

int main()
{
	test01();

	return 0;
}