#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::PrintAll()
{
	cout << x << endl;
	cout << y << endl;
}

Point Point::operator--(int)
{
	this->x--;
	this->y--;
	return *this;
}

Point Point::operator++(int)
{
	this->x++;
	this->y++;
	return *this;
}
