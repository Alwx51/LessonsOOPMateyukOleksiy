#include <iostream>
using namespace std;

class Person
{
    string name;
public:
    Person() :name("no name"){}
    Person(string name) :name(name){}
    virtual void print()const
    {
        cout << "Name: " << name << endl;       
        cout << endl;
    }
    virtual ~Person() = 0 {};
};

class Aspirant :public Person
{
    string* subject;
    int countSubjects;
public:
    Aspirant() :subject(nullptr), countSubjects(0), Person() {}
    Aspirant(string n, initializer_list<string> list) :Person(n)
    {
        this->countSubjects = list.size();
        subject = new string[countSubjects];
        int i = 0;
        for (string sub : list)
        {
            subject[i] = sub;
            i++;
        }
    }

    void Print()const
    {
        Person::print();
        cout << "Subjects: ";
        for (int i = 0; i < countSubjects; i++)
        {
            cout << subject[i] << " | ";
        }

    }
    ~Aspirant()
    {
        if (subject != nullptr)
        {
            delete[]subject;
        }
    }
};

int main()
{
    srand(time(0));
 /*   Person student("Vasia");
    student.print();*/

    /*Aspirant aspirant("Ivan"{ "Ukraine revolution","UNR","World war" });
    aspirant.print();*/

    Person* group[3]
    {
        /*new Person("Vasia")*/

        new Aspirant("Ivan",{ "Ukraine revolution","UNR","World war" }),
        new Aspirant("Ivan",{ "Ukraine revolution","UNR","World war" }),
        new Aspirant("Jesse",{ "Sinya zabava","Gasoline","Oil" })

    };
    for (int i = 0; i < 3; i++)
    {
        group[i]->print();
        delete group[i];
    }
}
