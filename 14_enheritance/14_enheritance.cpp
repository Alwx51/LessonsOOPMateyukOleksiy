#include <iostream>
using namespace std;

//class Enemy
//{
//protected:
//    string name;
//    int health;
//    float strength;
//    static const int maxHealth = 100;  
//public:
//    Enemy() :name("no name"), health(maxHealth), strength(0){}
//    Enemy(string name,int streng) :name(name), health(maxHealth), strength(streng){}
//    void print()const
//    {
//        cout << "Name: " << name << endl;
//        cout << "Health: " << health << endl;
//        cout << "Strength: " << strength << endl;
//    }
//    void DecreaseHealth(int value)
//    {
//        if (health - value < 0)
//            health = 0;
//        else
//            health -= value;
//    }
//    bool isAlive()const
//    {
//        return health > 0;
//    }
//    void Fight(int damage)
//    {
//        cout << "Getting damage " << damage << "%" << endl;
//        DecreaseHealth(damage);
//        cout << "Health after damage " << health << "%" << endl;
//    }
//    float Attack()
//    {
//        cout << "Attacking with strength: " << strength << endl;
//        return strength;
//    }
//
//};
//
//
//class Dragon : public Enemy
//{
//    float armor;
//public:
//    Dragon():armor(0), Enemy(){}
//    Dragon(string n,float s,float a):armor(a),Enemy(n,s){}
//    void Fight(int damage)
//    {
//        Enemy::Fight(damage - armor);
//    }
//    void print()const
//    {
//        cout << "----------------Dragon------------------" << endl;
//        Enemy::print();
//        cout << "Armor " << armor << endl;
//    }
//};
//
//class Wizard :public Enemy
//{
//    float turbo_attack;
//public:
//    Wizard():turbo_attack(0),Enemy(){}
//    Wizard(string n,float s,float t):turbo_attack(t),Enemy(n,s){}
//    void Fight(int damage)
//    {
//        Enemy::Fight(damage);
//    }
//    float AttackWithTurboPower()
//    {
//        cout << "Attacking with turbo power " << turbo_attack << endl;
//        return turbo_attack+strength;
//    }
//    void Print()
//    {
//        cout << "------------------------Wizard------------------------" << endl;
//        Enemy::print();
//        cout << "Turbo attack power " << turbo_attack << endl;
//    }
//};

class Student
{
protected:
    int averageMark;
    string group;
    string futureJob;
    string surname;
public:
    Student():averageMark(0),group("N-0"),futureJob("dvornik"),surname("no surname"){}
    Student(int a,string g,string f,string s):averageMark(a), group(g), futureJob(f), surname(s) {}
    void print()
    {
        cout << "-Student-" << endl;
        cout << "Average mark = " << averageMark << endl;
        cout << "Group: " << group << endl;
        cout << "Future job: " << futureJob << endl;
        cout << "Surname: " << surname << endl;
    }

};

class Aspirant:public Student
{
    string kandedatTheme;
    int countPages;
    int countMaxPages = 500;
public:
    Aspirant():kandedatTheme("no theme"),countPages(0),Student(){}
    Aspirant(string k,int cp, int a, string g, string f, string s):kandedatTheme(k),countPages(cp),Student(a,g,f,s){}
    void print()
    {
        cout << "-Aspirant-" << endl;
        Student::print();
        cout << "Kandedatna theme: " << kandedatTheme << endl;
        cout << "Count pages: " << countPages << endl;
    }

    void defendDesertation()
    {
        cout << "Congratulation!!! You write desertation!!!" << endl;
    }

    void addPages(int pages)
    {
        countPages += pages;
        if (countPages >= countMaxPages)
        {
            countPages = countMaxPages;
            defendDesertation();
        }
        else
        {
            cout << "Your pages: " << countPages << endl;
        }
        
    }
};

int main()
{
    Aspirant aspirant("shos",12, 13,"KN-1", "programmist", "Mateiuk");



    /*Dragon dragon("zubochist",5,2);
    Dragon dragon1("galda",7,2);
    
    dragon.print();
    dragon1.print();
    int i = 0;
    do
    {
        cout << "----------------Round " << i << "------------------" << endl;
        dragon.Fight(dragon1.Attack());
        dragon1.Fight(dragon.Attack());
        i++;
        cout << endl;

    } while (dragon1.isAlive()&&dragon.isAlive());

    dragon.print();
    dragon1.print();

    i = 1;
    Wizard wizard("Chaklun", 10,10);
    do
    {
        cout << "----------------Round " << i << "------------------" << endl;
        wizard.Fight(dragon1.Attack());
        dragon1.Fight(wizard.Attack());
        i++;
        cout << endl;

    } while (dragon1.isAlive()&&wizard.isAlive());
    
    wizard.print();
    dragon1.print();*/
}

