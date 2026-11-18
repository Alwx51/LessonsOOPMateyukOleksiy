#include <iostream>
using namespace std;



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
		case Up:cout << "Up" << endl;
			break; 
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
	string name;
	string surname;
	int age;
	int experience;
public:
	Driver():name("no name"),surname("no surname"),age(0),experience(0){}
	Driver(string n,string s,int a,int e):name(n),surname(s),age(a),experience(e){}
	void print()const
	{
		cout << "------Driver-----" << endl;
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << " year" << endl;
		cout << "Experience: " << experience << " year"<<endl;
	}
	
};

class Car
{
	Body body;
	Wheel* wheel;
	Engine engine;
	Door* door;
	Headlight* headlight;
	Driver* driver;
	int count_wheel;
	int count_door;
	int count_headlight;
public:
	Car() :wheel(nullptr), door(nullptr), headlight(nullptr), driver(nullptr),count_wheel(0),count_door(0),count_headlight(0) {}
	Car(string t, float v) :body(t), engine(v), driver(nullptr),count_wheel(0), count_door(0), count_headlight(0)
	{
		count_wheel = 4;
		count_door = 4;
		count_headlight = 2;
		wheel = new Wheel[count_wheel];
		wheel[0] = Wheel(35);
		wheel[1] = Wheel(35);
		wheel[2] = Wheel(35);
		wheel[3] = Wheel(35);
		door = new Door[count_door];
		door[0] = Door(DoorOpening::Up);
		door[1] = Door(DoorOpening::Up);
		door[2] = Door(DoorOpening::Straight);
		door[3] = Door(DoorOpening::Straight);
		headlight = new Headlight[count_headlight];
		headlight[0] = Headlight("Yellow", 95);
		headlight[1] = Headlight("Yellow", 75);
	}
	Car(Driver* d):wheel(nullptr), door(nullptr), headlight(nullptr), driver(nullptr), count_wheel(0), count_door(0), count_headlight(0)
	{
		this->driver = d;
	}
	void print()const
	{
		cout << "----------Car-----------" << endl;
		body.print();
		for (int i = 0; i < count_wheel; i++)
		{
			wheel[i].print();
		}
		engine.print();
		for (int i = 0; i < count_door; i++)
		{
			door[i].print();
		}
		for (int i = 0; i < count_headlight; i++)
		{
			headlight[i].print();
		}
		if (driver != nullptr)
			driver->print();
		else
			cout << "No driver" << endl;

	}
	void AddDriver(Driver* driver)
	{
		this->driver = driver;
	}
	~Car()
	{
		delete[]wheel;
		delete[]door;
		delete[]headlight;
		

	}
};

int main()
{
	Driver d1("Oleksiy", "Mateiuk", 15, 12);
	Car c("Sedan",1.4);
	c.print();
	c.AddDriver(&d1);
	c.print();

	Car c2(&d1);
	c2.print();
}

