#include <iostream>
using namespace std;

class Cube
{
public:
	void setLength(int length)
	{
		this->length = length;
	}

	int getLength()
	{
		return length;
	}

	void setWidth(int width)
	{
		this->width = width;
	}

	int getWidth()
	{
		return width;
	}

	void setHeight(int height)
	{
		this->height = height;
	}

	int getHeight()
	{
		return height;
	}

	int calcaluteVolumn()
	{
		return length * width * height;
	}

	int calculateArea()
	{
		return 2 * (length * width + width * height + length * height);
	}

	bool isSameCube(Cube& c)
	{
		return (this->getLength() == c.getLength()) &&
			(this->getWidth() == c.getWidth()) &&
			(this->getHeight() == c.getHeight());
	}

private:
	int length;
	int width;
	int height;
};

bool isSameCube(Cube& c1, Cube& c2);

int main()
{
	Cube c;
	c.setLength(3);
	c.setWidth(4);
	c.setHeight(5);
	int area = c.calculateArea();
	int volumn = c.calcaluteVolumn();

	cout << "c的面积为：" << area << endl;
	cout << "c的体积为：" << volumn << endl;

	Cube c2;
	c2.setLength(3);
	c2.setWidth(4);
	c2.setHeight(5);

	bool ret = c.isSameCube(c2);
	if (ret)
	{
		cout << "c == c2" << endl;
	}
	else
	{
		cout << "c != c2" << endl;
	}

	ret = isSameCube(c, c2);
	if (ret)
	{
		cout << "c == c2" << endl;
	}
	else
	{
		cout << "c != c2" << endl;
	}

	return 0;
}

bool isSameCube(Cube& c1, Cube& c2)
{
	return (c1.getLength() == c2.getLength()) &&
		(c1.getWidth() == c2.getWidth()) &&
		(c1.getHeight() == c2.getHeight());
}