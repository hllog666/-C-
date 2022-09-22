#include <iostream>
using namespace std;
#include "MyArray.h"
#include <string>

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;

	for (int i = 0; i < 5; i++)
	{
		arr1.PushBack(i);
	}
	arr1.PopBack();
	printIntArray(arr1);
	cout << arr1.getCapacity() << endl;
	cout << arr1.getSize() << endl;
}

class Person
{
public:
	Person()
	{

	}

	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i].name << arr[i].age << endl;
	}
}

void test02()
{
	MyArray<Person> arr(10);
	Person p1("Tom", 20);
	Person p2("Cat", 30);
	Person p3("Bob", 40);
	Person p4("Candy", 10);
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	printPersonArray(arr);
	cout << arr.getCapacity() << endl;
	cout << arr.getSize() << endl;
}

int main()
{
	test01();
	test02();

	return 0;
}