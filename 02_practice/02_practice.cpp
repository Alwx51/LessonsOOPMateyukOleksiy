#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

class Student
{
	string name;
	int age;
	int* marks;
	int countMarks;
	float averageMark;
	void SetAverageMark()
	{
		double summa = 0;
		for (int i = 0; i < countMarks; i++)
		{
			summa += marks[i];
		}
		averageMark = summa / countMarks;
	}
public:
	Student()//methods
	{
		cout << "Default constructor" << endl;
		name = "no name";
		age = 0;
		marks = nullptr;
		countMarks = 0;
		averageMark = 0;
	}
	Student(string name,int age)//methods
	{
		cout << "Parametrized constructor" << endl;
		this->name = name;
		this->age = age;
		marks = nullptr;
		countMarks = 0;
		averageMark = 0;

	}
	void AddMark(int mark)
	{
		int* temp = new int[countMarks + 1];
		for (int i = 0; i < countMarks; i++)
		{
			temp[i] = marks[i];
		}
		temp[countMarks] = mark;
		if (marks != nullptr)
		{
			delete[]marks;
		}
		marks = temp;
		countMarks++;
		SetAverageMark();
	}

	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		for (int i = 0; i < countMarks; i++)
		{
			cout << marks[i] << " ";
		}
		cout << "\nAverage Mark: " << averageMark << endl;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	void SetAge(int age)
	{
		this->age = age;
	}
	string GetName(string name)
	{
		return name;
	}
	int GetAge(int age)
	{
		return age;
	}

	void Save()
	{
		ofstream out;
		out.open("Student.txt");
		out << name << endl;
		out << age << endl;
		out << countMarks << endl;

		for (int i = 0; i < countMarks; i++)
		{
			out << marks[i] << " ";
		}

		

		out.close();

		cout << "Data saved successfully!" << endl;


	}

	void Load()
	{
		ifstream in;
		in.open("Student.txt");
		in >> name;
		in >> age;
		in >> countMarks;

		delete[]marks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++)
		{
			in >> marks[i];		
		}

		in.close();
		SetAverageMark();
		cout << "Data read successfully!" << endl;
	}

	~Student()
	{
		cout << "Destructor" << name<<endl;
		if (marks != nullptr)
		{
			delete[]marks;
		}
	}
};

int main()
{
	Student student("Oleksiy", 15);
	student.AddMark(10);
	student.AddMark(11);
	student.AddMark(10);
	student.AddMark(12);
	student.Save();
	Student s2;
	s2.Load();
	s2.Print();




}
