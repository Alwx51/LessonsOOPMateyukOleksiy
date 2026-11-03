#include <iostream>
#include <conio.h>
using namespace std;

class Queue
{
	string arr[5];
	int front;
	int rear;
public:
	Queue():front(0),rear(4){}
	void init()
	{
		arr[0] = "Cherry";
		arr[1] = "Lemon";
		arr[2] = "Orange";
		arr[3] = "Star";
		arr[4] = "Diamond";
	}
	void Enqueue(string el)
	{
		rear = (rear + 1) % 5;
		arr[rear] = el;

	}
	string Dequeue()//queue cycle
	{
		
		string first = arr[0];
		for (int i = 0; i < rear; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[rear] = first;
		return first;
		
	}
	void drumRot(int count)
	{
		for (int i = 0; i < count; i++)
		{
			Dequeue();
		}
	}
	void print()
	{
		for (int i = 0; i < rear+1; i++)
		{
			cout << arr[i] << " | ";
		}
		cout << endl;
	}
	string getFirst()
	{
		return arr[0];
	}
	
};

int Random()
{
	int a = rand() % 20;
	return a;
}

int main()
{
	srand(time(0));
	Queue q1;
	Queue q2;
	Queue q3;
	q1.init();
	q2.init();
	q3.init();
	while (true)
	{
		cout << "Press ENTER to spin or ESC to exit";
		char key = _getch();
		if (key == 27)
			break;
		if (key == 13)
		{
			q1.drumRot(Random());
			q2.drumRot(Random());
			q3.drumRot(Random());
		}
		
		system("cls");

		if (q1.getFirst() == q2.getFirst() &&
			q2.getFirst() == q3.getFirst())
		{
			cout << "YOU WIN!" << endl;
			
		}
		else if (q1.getFirst() == "Diamond" &&
			q2.getFirst() == "Diamond"&&
			q3.getFirst() == "Diamond")
		{
			cout << "JACKPOT!!!";
		}
		else
		{
			cout << "Try again!" << endl;
			
		}

		q1.print();
		q2.print();
		q3.print();

		cout << "\nPress ENTER to spin again";
	}
	



}





