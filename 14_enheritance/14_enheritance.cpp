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

class Passport
{
    string country;
    string fullName;
    int birthdate;
    string gender;
    int number;
    int date_of_issue;
    int expiration_date;
#pragma region validator
    int validateYear(int year)
    {
        if (year > 1000 && year <= 9999)
        {
            return year;
        }
        else
        {
            cout << "Error invalid number [" << year << "]" << endl;
            return 0;
        }
    }
    int validateBirthdate(int date)
    {
        if (date >= 10000000 && date <= 99999999)
        {
            return date;
        }
        else
        {
            cout << "Error invalid number [" << date << "]" << endl;
            return 0;
        }
    }
    string validateGender(string gender)
    {
        if (gender == "female"||gender == "male")
        {
            return gender;
        }
        else
        {
            cout << "Error invalid gender [" << gender << "]" << endl;
            return "error";
        }
    }
#pragma endregion
public:
#pragma region constructors
    Passport():country("unknown"),fullName("no full name"),birthdate(00000000),gender("unknown"),number(0),date_of_issue(0000), expiration_date(0000){}
    Passport(string c, string f,int b,string g,int n,int d,int e):country(c), fullName(f), gender(g), number(n)
    {
        date_of_issue = validateYear(d);
        expiration_date = validateYear(e);
        birthdate = validateBirthdate(b);
        gender = validateGender(g);
    }
#pragma endregion
    void print()
    {
        cout << "Country: " << country << endl;
        cout << "Full name: " << fullName << endl;
        cout << "birthdate: " << birthdate << endl;
        cout << "Gender: " << gender << endl;
        cout << "Number: " << number << endl;
        cout << "Date of issue: " << date_of_issue << endl;
        cout << "Expiration data: " << expiration_date << endl;
    }
};

class ForeignPassport:public Passport
{
    int passportNum;
    static const int max_countrys = 100;
    string countrys[max_countrys];
    int count_of_country;
public:
#pragma region constructors2
    ForeignPassport() :passportNum(0),count_of_country(0), Passport()
    {
        addCountry("Poland");
        addCountry("Germany");
        addCountry("USA");
        addCountry("France");
        addCountry("Spain");
    }
    ForeignPassport(int p, string c, string f, int b, string g, int n, int d, int e):passportNum(p),count_of_country(0),Passport(c,f,b,g,n,d,e)
    {
        addCountry("Poland");
        addCountry("Germany");
        addCountry("USA");
        addCountry("France");
        addCountry("Spain");
    }
#pragma endregion
    void addCountry(const string& country)
    {
        if (count_of_country>=max_countrys)
        {
            cout << "Limit" << endl;
        }
        else
        {
            countrys[count_of_country] = country;
            count_of_country++;
        }
    }
    void printAllCountrys()
    {
        cout << "Passport Number:" << passportNum << endl;
        cout << "----All countrys----" << endl;
        for (int i = 0; i < count_of_country; i++)
        {
            cout << countrys[i] <<":"<< endl;
        }
        cout << "----------------------" << endl;
        cout << "Number of countrys: " << count_of_country << endl;
    }
    void printAllData()
    {
        cout << "-------All Data-------" << endl;
        Passport::print();
        cout << "Passport number: " << passportNum << endl;      
        printAllCountrys();
        
        

    }
    //перевірка перед подорожю
    void ValidateCountry(string country)
    {
        for (int i = 0; i < count_of_country; i++)
        {
            if (countrys[i] == country)
            {
                cout << "This country is in the passport" << endl;
                break;
            }
            

        }

        

        
        

    }
};

int main()
{
    Aspirant aspirant("Doctor of Philosophy",12, 13,"KN-1", "programmist", "Mateiuk");
    aspirant.addPages(150);
    aspirant.addPages(150);
    aspirant.addPages(150);
    aspirant.addPages(150);

    //task2
    ForeignPassport passport(13,"Ukraine","Olelsiy Mateiuk Andriovich",13072011,"male",26,3011,1209);
    passport.printAllCountrys();
    passport.printAllData();
    passport.addCountry("Great Britain");
    passport.printAllCountrys();
    passport.ValidateCountry("Great Britain");

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

