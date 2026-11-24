#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Time
{
	int h, m, s;
	bool operator > (const Time& other) const
	{
		if (this->h != other.h) return this->h > other.h;
		if (this->m != other.m) return this->m > other.m;
		return this->s > other.s;
	}
};
class Train
{
	int number;
	Time departureTime;
	string destination;
public:
	Train() :number(0), departureTime{ 0,0,0 },destination("no destination"){}
	Train(int n,Time t,string d):number(n), departureTime(t),destination(d){}
	void print()const
	{
		cout << "Train # " << number << endl;
		cout << "Hours: " << departureTime.h << endl;
		cout << "Minutes: " << departureTime.m << endl;
		cout << "Seconds: " << departureTime.s << endl;
		cout << "Destination: " << destination << endl;
		cout << endl;
	}
	void setDepartureTime(Time newTime)
	{
		departureTime = newTime;
	}
	string getDestination()const
	{
		return destination;
	}
	int getNumber()const
	{
		return number;
	}
	bool operator > (const Train& other) const
	{
		return this->departureTime > other.departureTime;
	}
	void save(ofstream& out) const
	{
		out << number;
		out << ":";
		out << departureTime.h << "/"<<departureTime.m<<"/"<< departureTime.s;
		out << ":";
		out << destination;
	}
	void load(ifstream& in)
	{
		in >> number;
		in >> departureTime.h;
		in >> departureTime.m;
		in >> departureTime.s;
		in >> destination;
	}
};
class Railway
{
	vector<Train> trains;
public:
	void AddTrain(Train t)
	{
		trains.push_back(t);
	}
	void PrintAll()const
	{
		for (int i = 0; i < trains.size(); i++)
		{
			trains[i].print();
		}
	}
	void PrintTrainByNumber(int num)const
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].getNumber() == num)
			{
				trains[i].print();
				return;
			}
		}
		cout << "Train not found" << endl;
		
	}
	void EditDepartureTime(int num, Time newTime)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].getNumber() == num)
			{
				trains[i].setDepartureTime(newTime);
				cout << "Edit successfuly" << endl;
				return;
			}
		}
		cout << "Number not found" << endl;
	}
	void SortByTime()
	{
		for (int i = 0; i < trains.size(); i++)
		{
			for (int j = trains.size() - 1; j > i; j--)
			{
				if (trains[j - 1] > trains[j])
				{
					Train temp = trains[j - 1];
					trains[j - 1] = trains[j];
					trains[j] = temp;

				}
			}
		}
	}
	void ShowByDestination(string d)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].getDestination()==d)
			{
				trains[i].print();
			}
		}
	}
	void SaveToFile(string filename) const
	{
		ofstream file(filename);
		for (int i = 0; i < trains.size(); i++)
		{
			trains[i].save(file);
		}
		file.close();
	}

	void LoadFromFile(string filename)
	{
		ifstream file(filename);
		trains.clear();
		while (!file.eof())
		{
			Train temp;
			temp.load(file);
			if (file.fail()) break;
			trains.push_back(temp);
		}
	
		file.close();
	}
};


int main()
{
	Railway station;
	station.AddTrain(Train(43, { 19, 25, 0 }, "Kyiv"));
	station.AddTrain(Train(12, { 8, 5, 0 }, "Lviv"));
	station.AddTrain(Train(88, { 14, 40, 0 }, "Rivne"));
	station.AddTrain(Train(105, { 22, 15, 0 }, "Lviv"));

	cout << "=== ALL TRAINS ===" << endl;
	station.PrintAll();

	cout << "==== SEARCH TRAIN #88 ===" << endl;
	station.PrintTrainByNumber(88);

	cout << "=== EDIT TIME FOR #88 ===" << endl;
	station.EditDepartureTime(88, { 6, 30, 0 });
	station.PrintTrainByNumber(88);

	cout << "=== SORTED BY TIME ===" << endl;
	station.SortByTime();
	station.PrintAll();

	cout << "=== TRAINS TO LVIV ===" << endl;
	station.ShowByDestination("Lviv");

	cout << "=== FILE OPERATIONS ===" << endl;
	station.SaveToFile("trains.txt");

	Railway newStation;
	newStation.LoadFromFile("trains.txt");
	newStation.PrintAll();
} 

