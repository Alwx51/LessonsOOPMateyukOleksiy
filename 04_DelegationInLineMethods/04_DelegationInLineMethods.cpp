#include <iostream>
using namespace std;
#define PI 3.14;

inline void Hello()
{
    cout << "Hello" << endl;
}

class Human
{
    string name;
    int age;
    float weight;
public:
    static int count_humans;
    Human() :name("no name"), age(0), weight(0) { count_humans++; }
    Human(string name):Human()
    {
        this->name = name;
        //age = 0;-+
        //weight = 0;
    }
    Human(string name, int age):Human(name)
    {
        //this->name = name;
        this->age = age;
        //weight = 0;
    }
    Human(string name,int age,float weight):Human(name,age)
    {
        //this->name = name;
        //this->age = age;
        this->weight = weight;
    }

    

    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
    }
};


int Human::count_humans = 0;
int main()
{ 
    Human h1;
    h1.Print();
    cout << "Count humans: " << Human::count_humans<<endl;

    Human h2("Oleg");
    h2.Print();
    cout << "Count humans: " << h2.count_humans << endl;

    Human h3("Vova", 17);
    h3.Print();
    cout << "Count humans: " << h3.count_humans << endl;

    Human h4("Mykola",54,234);
    h4.Print();
    cout << "Count humans: " << h4.count_humans << endl;



    Hello(); 
    cout << PI;
}

