#include <iostream>
#include <vector>
using namespace std;

int main()
{
	struct Time
	{
		int h, m, s;
   };
	class Train
	{
		int number;
		Time departureTime;
		string destination;
	};
	class Railway
	{
		vector<Train> trains;
		void AddTrain(Train t)
		{
			trains.push_back(t);
		}
	};
} 

