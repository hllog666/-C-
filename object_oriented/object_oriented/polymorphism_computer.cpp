#include <iostream>
using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		this->cpu = cpu;
		this->vc = vc;
		this->mem = mem;
	}

	void work()
	{
		cpu->calculate();
		vc->display();
		mem->storage();
	}

	~Computer()
	{
		if (cpu != nullptr)
		{
			delete cpu;
			cpu = nullptr;
		}
		if (vc != nullptr)
		{
			delete vc;
			vc = nullptr;
		}
		if (mem != nullptr)
		{
			delete mem;
			mem = nullptr;
		}
	}

private:
	CPU* cpu;
	VideoCard* vc;
	Memory* mem;
};

class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel��CPU��ʼ����" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel����ʾ����ʼ��ʾ" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢" << endl;
	}
};

class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU��ʼ����" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo����ʾ����ʼ��ʾ" << endl;
	}
};

class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢" << endl;
	}
};

void test01()
{
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelVideoCard = new IntelVideoCard;
	Memory* intelMemory = new IntelMemory;
	Computer* c1 = new Computer(intelCPU, intelVideoCard, intelMemory);
	c1->work();
	delete c1;

	CPU* lenovoCPU = new LenovoCPU;
	VideoCard* lenovoVideoCard = new LenovoVideoCard;
	Memory* lenovoMemory = new LenovoMemory;
	Computer* c2 = new Computer(lenovoCPU, lenovoVideoCard, lenovoMemory);
	c2->work();
	delete c2;
}

int main()
{
	test01();

	return 0;
}