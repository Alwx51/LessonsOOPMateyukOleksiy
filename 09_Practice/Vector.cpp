#include "Vector.h"

Vector::Vector()
{
	points = nullptr;
	countPoint = 0;
}

Vector::Vector(Vector&& other)
{
	this->countPoint = other.countPoint;
	this->points = other.points;
	other.points = nullptr;
	other.countPoint = 0;
	cout << "Move constructor" << endl;
}

Vector::Vector(const Vector& other)
{
	countPoint = other.countPoint;
	this->points = new Point[countPoint];
	for (int i = 0; i < countPoint; i++)
	{
		this->points[i] = other.points[i];
	}

}

Vector& Vector::operator=(const Vector& other)
{
	if (this == &other)
	{
		return *this;
	}

	if (points != nullptr)
	{
		delete[] points;
	}
	countPoint = other.countPoint;
	this->points = new Point[countPoint];
	for (int i = 0; i < countPoint; i++)
	{
		this->points[i] = other.points[i];
	}
	return*this;
}

void Vector::AddPoint(Point p)
{
	Point* temp = new Point[countPoint + 1];
	for (int i = 0; i < countPoint; i++)
	{
		temp[i] = points[i];
	}
	temp[countPoint] = p;
	if (points != nullptr)
		delete[]points;
	points = temp;
	countPoint++;

}

void Vector::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Vector::Print()
{
	for (int i = 0; i < countPoint; i++)
	{
		points[i].PrintAll();
	}
}

Vector::~Vector()
{
	if (points != nullptr)
		delete[]points;
}
