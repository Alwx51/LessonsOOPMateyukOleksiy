#pragma once
#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	Point();
	Point(int x, int y);
	void PrintAll();
	Point operator--(int);
	Point operator++(int);
	bool operator > (const Point& other)
	{
		return ((this->x + this->y) > (other.x + other.y));
	}
	bool operator < (const Point& other)const
	{
		return ((this->x + this->y) < (other.x + other.y));
	}
	Point operator !()
	{
		return Point(-x, -y);
	}
};

