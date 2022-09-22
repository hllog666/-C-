#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[capacity];
	}

	MyArray(const MyArray& arr)
	{
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	MyArray& operator=(const MyArray& arr)
	{
		if (this->pAddress != nullptr)
		{
			delete[] this->pAddress;
			this->pAddress = nullptr;
			this->capacity = 0;
			this->size = 0;
		}
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	~MyArray()
	{
		if (this->pAddress != nullptr)
		{
			delete[] pAddress;
			pAddress = nullptr;
		}
	}

	void PushBack(const T& val)
	{
		if (this->capacity == this->size)
		{
			return;
		}
		this->pAddress[this->size] = val;
		this->size++;
	}

	void PopBack()
	{
		if (this->size == 0)
		{
			return;
		}
		this->size--;
	}

	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	int getCapacity()
	{
		return this->capacity;
	}

	int getSize()
	{
		return this->size;
	}

private:
	T* pAddress;
	int capacity;
	int size;
};