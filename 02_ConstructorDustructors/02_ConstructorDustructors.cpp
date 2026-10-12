#include <iostream>
#include <Windows.h>
using namespace std;

//struct Date
//{
//	int day;
//	int month;
//	int year;
//	void PrintDate()
//	{
//		cout << "Birthdate: " << day << "/"
//			<< month << "/" << year << endl;
//	}
//};
//
//class Student
//{
//	string name;
//	string surname;
//	string middle_name;
//	Date birthdate; 
//	string phone;
//	int* marks;
//	int countMarks;
//	float averageMark;
//	void AverageMark()
//	{
//		double summa = 0;
//		for (int i = 0; i < countMarks; i++)
//		{
//			summa += marks[i];
//		}
//		averageMark = summa / countMarks;
//	}
//public:
//	Student()//methods
//	{
//		cout << "Default constructor" << endl;
//		name = "no name";
//		surname = "no surname";
//		birthdate = { 1,1,1 };
//		phone = "no phone";
//		marks = nullptr;
//		countMarks = 0;
//		averageMark = 0;
//	}
//	Student(string name,string surname,string middle_name)//methods
//	{
//		cout << "Parametrized constructor" << endl;
//		this->name = name;
//		this->surname = surname;
//		this->middle_name = middle_name;
//
//	}
//	void AddMark(int mark)
//	{
//		int* temp = new int[countMarks + 1];
//		for (int i = 0; i < countMarks; i++)
//		{
//			temp[i] = marks[i];
//		}
//		temp[countMarks] = mark;
//		if (marks != nullptr)
//		{
//			delete[]marks;
//		}
//		marks = temp;
//		countMarks++;
//		AverageMark();
//	}
//
//	void Print()
//	{
//		cout << "Name: " << name << endl;
//		cout << "Surname: " << surname << endl;
//		cout << "Middle name: " << middle_name << endl;
//		birthdate.PrintDate();
//		cout << "Phone: " << phone << endl;
//		cout << "Marks: ";
//		for (int i = 0; i < countMarks; i++)
//		{
//			cout << marks[i] << " ";
//		}
//		cout << "\nAverage Mark: " << averageMark << endl;
//	}
//	void SetName(string name)
//	{
//		this->name = name;
//	}
//	void SetSurname(string surname)
//	{
//		this->surname = surname;
//	}
//	void Initialization()
//	{
//		name = "no name";
//		surname = "no surname";
//		birthdate = { 1,1,1 };
//		phone = "no phone";
//		marks = nullptr;
//		countMarks = 0;
//		averageMark = 0;
//	}
//	~Student()
//	{
//		cout << "Destructor" << name<<endl;
//		if (marks != nullptr)
//		{
//			delete[]marks;
//		}
//	}
//};

struct Coord
{
	int x;
	int y;
	void print()
	{
		cout << x << endl;
		cout << y << endl;
	}
};

class Rectangle1
{
	int width;
	int height;
	char symbol;
	Coord coord;
public:
	Rectangle1()
	{
		cout << "Default constructor" << endl;
		width = 0;
		height = 0;
		symbol = '*';
		coord.x = 0;
		coord.y = 0;
	}
	Rectangle1(int width,int height,char symbol)
	{
		cout << "Parametrized constructor" << endl;
		this->width = width;
		this->height = height;
		this->symbol = symbol;
		coord.x = 0;
		coord.y = 0;
	}
	void Print()
	{
		for (int i = 0; i < height; i++)
		{
			SetPos(coord.x, coord.y + i);
			for (int j = 0; j < width; j++)
			{
				cout << symbol << " ";
			}
			cout << endl;
		}
	}
	void SetNewSize(int new_width, int new_height)
	{
		this->width = new_width;
		this->height = new_height;
	}

	void SetPos(int x, int y)
	{
		COORD c;
		c.X = x;
		c.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

	void setSizeXY(int x, int y) {
		this->coord.x = x;
		this->coord.y = y;
		
	}
};

int main()
{
	Rectangle1 rectangle(5,8,'u');
	//*rectangle.Print();

	rectangle.SetNewSize(10, 10);
	rectangle.setSizeXY(17, 17);
	rectangle.Print();





	/*Student student

	student.Initialization();
	student.Print();

	student.SetName("Anton");
	student.SetSurname("Chugun");
	student.Print();

	Student st2("Vasya", "ivanchuk", "Mykolaivich");
	st2.AddMark(7);
	st2.AddMark(12);
	st2.AddMark(8);
	st2.AddMark(9);
	st2.Print();*/
	






}

