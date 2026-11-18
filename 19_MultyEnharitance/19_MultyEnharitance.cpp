#include <iostream>
using namespace std;

class Car
{

};

class Body
{
    string type;
public:
	Body():type("no type"){}
	Body(string t):type(t){}
	void print()const
	{
		cout << "------Body-----" << endl;
		cout << "Type: " << type << endl;
	}
};

class Wheel
{
	int radius;
public:
	Wheel():radius(0){}
	Wheel(int r):radius(r){}
	void print()const
	{
		cout << "------Wheel-----" << endl;
		cout << "Radius: " << radius << endl;
	}
};

class Engine
{
	float volume;
public:
	Engine():volume(0){}
	Engine(float v):volume(v){}
	void print()const
	{
		cout << "------Engine-----" << endl;
		cout << "Volume: " << volume << endl;
	}
};

enum DoorOpening { None, Straight, Up};

class Door
{
	DoorOpening doorOpening;
public:
	Door():doorOpening(None){}
	Door(DoorOpening d):doorOpening(d){}
	void print()const
	{
		cout << "------Door-----" << endl;
		cout << "Doors open: ";
		switch (doorOpening)
		{
		case None:cout << "None" << endl;
			break;
		case Straight:cout << "Straight" << endl;
			break;
		case Up:
			break; cout << "Up" << endl;
		default:
			break;
		}
	}
};

class Headlight
{
	string color;
	int power;
public:
	Headlight():color("no color"),power(0){}
	Headlight(string c,int p):color(c),power(p){}
	void print()const
	{
		cout << "------Headlight-----" << endl;
		cout << "Color: " << color << endl;
		cout << "Power: " << power << endl;
	}
};

class Driver
{

};

int main()
{
    
}

