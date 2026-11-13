#include <iostream>
using namespace std;

class Animal
{
    string name;
    string place;
    float weight;
public:
    Animal():name("no name"),place("no place"),weight(0){}
    Animal(string n,string p,float w):name(n),place(p),weight(w)
    {
        /*if (w > 0)
            weight = w;
        else
            weight = 0;*/
        weight = (w > 0) ? w : 0;
    }
    void Show()const
    {
        cout << "Name: " << name << endl;
        cout << "Place: " << place << endl;
        cout << "Weight: " << weight << endl;
    }
    virtual void MakeSound() = 0;//pure virtual function
    virtual void Move()
    {
        cout << "I am moving........" << endl;
    }
};

class Dog:public Animal
{
    string breed;
public:
    Dog():breed("no breed"),Animal(){}
    Dog(string n,string p,float w,string b):breed(b),Animal(n,p,w){}
    void MakeSound()override
    {
        cout << "Goof-goof-goof-goof" << endl;

    }
    void Move()
    {
        cout << "I am running and jumping........" << endl;
    }
    void Show()
    {
        Animal::Show();
        cout << "Type breed: " << breed << endl;
    }
};

class Parrot:public Animal
{
    float flyHeight;
    bool canSpeak;
public:
    Parrot() :flyHeight(0), canSpeak(false), Animal(){}
    Parrot(string n, string p, float w, float fH, bool s) :flyHeight(fH), canSpeak(s), Animal(n,p,w) {}
    void MakeSound()override
    {
        cout << "Kar-kar-kar-kar-kar" << endl;

    }
    void Move()
    {
        cout << "I am flying up to........" << flyHeight<<"and i can speak or not: "<<canSpeak<<endl;
    }
    void Show()
    {
        Animal::Show();
        cout << "Fly height: " << flyHeight << endl;
        cout << "Can speak: " << canSpeak << endl;
    }
};

class Amphibian :public Animal
{
protected:
    float swimDeep;
public:
    Amphibian():swimDeep(),Animal(){}
    Amphibian(string n,string p,float w,float sD):swimDeep(sD),Animal(n,p,w){}
    //void MakeSound()override
    //{
    //    cout << "Kar-kar-kar-kar-kar" << endl;

    //}
    void Move()
    {
        cout << "I am swimming down........" << swimDeep<< endl;
    }
    void Show()
    {
        Animal::Show();
        cout << "Swim deep: " << swimDeep << endl;
    }
};

class Frog:public Amphibian
{
public:
    Frog():Amphibian(){}
    Frog(string n, string p, float w, float s):Amphibian(n,p,w,s){}
    void MakeSound()override
    {
        cout << "Kva-kva-kva-kva-kva" << endl;

    }
    void Move()
    {
        cout << "I am swimming down........" << swimDeep << "and i can speak or not: " << canSpeak << endl;
    }
};

void RollCall(Animal& a)
{
    a.MakeSound();
}

class Employer
{
protected:
    string name;
    string surname;
    int salary;
    string job;
public:
    Employer():name("no name"),surname("no surname"),salary(0),job("no job"){}
    Employer(string n,string sur,int s,string j):name(n),surname(sur),salary(s),job(j){}
    virtual void Print()const = 0;
};

class President:public Employer
{
    string level_of_English;
public:
    President():Employer() {}
    President(string n, string sur, int s, string j,string lvl) :level_of_English(lvl), Employer(n,sur,s,j){}
    void Print()const override
    {
        cout << "--------President---------" << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Salary: " << salary << endl;
        cout << "Job: " << job << endl;
        cout << "Level of English: " << level_of_English << endl;
    }
};

class Manager:public Employer
{
    int count_of_employers;
public:
     Manager():Employer(){}
     Manager(string n, string sur, int s, string j, int c) :count_of_employers(c), Employer(n, sur, s, j) {}
     void Print()const override
     {
         cout << "--------Manager---------" << endl;
         cout << "Name: " << name << endl;
         cout << "Surname: " << surname << endl;
         cout << "Salary: " << salary << endl;
         cout << "Job: " << job << endl;
         cout << "Count of employers: " << count_of_employers << endl;
     }
};
class Worker:public Employer
{
    string expirience;
public:
     Worker():Employer(){}
     Worker(string n, string sur, int s, string j, string e) :expirience(e), Employer(n, sur, s, j) {}
     void Print()const override
     {
         cout << "--------Worker---------" << endl;
         cout << "Name: " << name << endl;
         cout << "Surname: " << surname << endl;
         cout << "Salary: " << salary << endl;
         cout << "Job: " << job << endl;
         cout << "Expirience: " << expirience << endl;
     }
};

class Transport
{
    string name;
    int count_of_passangers;
    string price;
public:
    Transport():name("no name"),count_of_passangers(0),price(0){}
    Transport(string n,int c,string p):name(n),count_of_passangers(c),price(p){}
};

int main()
{
    //Parrot parrot("Kesha", "House", 0.5, 5, true);
    //parrot.MakeSound();
    //parrot.Move();
    //parrot.Show();
    ////Animal animal("Tom", "Flat", 12);
    ////animal.Move();
    ////animal.Show();
    ////animal.MakeSound();

    //Frog frog("Crazy frog", "Lake", 0.2, 2);
    //frog.MakeSound();
    //frog.Move();
    //frog.Show();


    //Dog dog("Roki", "Flat", 12, "Taksa");
    //dog.Show();
    //dog.Move();
    //dog.MakeSound();

    //RollCall(dog);
    //RollCall(parrot);
    //RollCall(frog);
}

