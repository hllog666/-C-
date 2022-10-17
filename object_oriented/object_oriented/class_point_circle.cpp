#include <iostream>
using namespace std;

class Point
{
public:
	void setX(int x)
	{
		this->x = x;
	}

	int getX()
	{
		return x;
	}

	void setY(int y)
	{
		this->y = y;
	}

	int getY()
	{
		return y;
	}

private:
	int x;
	int y;
};

class Circle
{
public:
	void setCenter(Point center)
	{
		this->center = center;
	}

	Point getCenter()
	{
		return center;
	}

	void setR(int r)
	{
		this->r = r;
	}

	int getR()
	{
		return r;
	}

private:
	Point center;
	int r;
};

void isInCircle(Circle& c, Point& p);

int main()
{
	Point p;
	p.setX(10);
	p.setY(10);

	Point p2;
	p2.setX(10);
	p2.setY(0);

	Circle c;
	c.setCenter(p);
	c.setR(10);

	isInCircle(c, p2);

	return 0;
}

void isInCircle(Circle& c, Point& p)
{
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();

	if (distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}