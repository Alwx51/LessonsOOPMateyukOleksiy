#pragma once
#include "Point.h"
#include <windows.h>

class Vector
{
	Point* points;
	int countPoint;
public:
	Vector();
	Vector(Vector&& other);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	void AddPoint(Point p);	
	void gotoxy(int x, int y);
	void Print();
	~Vector();
};

