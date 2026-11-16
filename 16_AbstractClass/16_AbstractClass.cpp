#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
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
        PlaySound(TEXT("bark.wav"), NULL, SND_FILENAME | SND_SYNC);

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
        PlaySound(TEXT("kar.wav"), NULL, SND_FILENAME | SND_SYNC);

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
        PlaySound(TEXT("frog.wav"), NULL, SND_FILENAME | SND_SYNC);

    }
    void Move()
    {
        cout << "I am swimming down........" << swimDeep << endl;
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
protected:
    string name;
    int km_h;
    int count_of_passangers;
    int MAX_count_of_passangers;
    double distance;
    double price_per_1_km;
    double price;
    double time;
public:
    Transport():name("no name"), km_h(0),count_of_passangers(0), MAX_count_of_passangers(0), price(0), time(0),distance(0),price_per_1_km(0) {}
    Transport(string n,int km_h,int c,int max, double d, double p):name(n),km_h(km_h),count_of_passangers(c),MAX_count_of_passangers(max), distance(d), price_per_1_km(p), price(0), time(0)
    {
        if (count_of_passangers > 0 && count_of_passangers <= MAX_count_of_passangers)
            count_of_passangers = c;
        else
            count_of_passangers = 0;
        this->km_h = (km_h > 0) ? km_h : 0;
        distance = (d > 0) ? d : 0;
        price_per_1_km = (p > 0) ? p : 0;
        MAX_count_of_passangers = (max > 0) ? max : 0;
        
    }
    void FuncTime()
    {
        if (km_h > 0)
            time = distance / km_h;
        else
            time = 0;
        cout << "Time: " << time << " hours" << endl;
    }
    void FuncPrice()
    {
        price = distance * price_per_1_km * count_of_passangers;
        cout << "Price: " << price << "$" << endl;
    }
    virtual void Print()const = 0;
    virtual ~Transport() = default;
};

class Car:public Transport
{
    int horse_power;
public:
    Car():Transport(), horse_power(0){}
    Car(string n, int km_h, int c, double d, double p,int h):horse_power(h),Transport(n,km_h,c,4,d,p)
    {        
        horse_power = (h > 0) ? h : 0;
    }
    void FuncTime()
    {
        Transport::FuncTime();
    }
    void FuncPrice()
    {
        Transport::FuncPrice();
    }
    void Print()const override
    {
        cout << "------------Car-------------" << endl;
        cout << "Model: " << name << endl;
        cout << "Km/h: " << km_h << endl;
        cout << "Count of passengers: " << count_of_passangers << endl;
        cout << "Max count of passengers: " << MAX_count_of_passangers << endl;
        cout << "Distance: " << distance << " km"<<endl;
        cout << "Price per 1 km: " << price_per_1_km << "$"<<endl;
        cout << "Price: " << price << "$"<<endl;
        cout << "Time: " << time << " hours"<<endl;
        cout << "Horse power: " << horse_power << endl;
        cout << "-----------------------------" << endl;
    }
};
class Bicycle :public Transport
{
    bool hasTrunk;
public:
    Bicycle():Transport(),hasTrunk(false) {}
    Bicycle(string n, int km_h, int c, double d, double p,bool h):hasTrunk(h),Transport(n,km_h,c,2,d,p){}
    void FuncTime()
    {
        Transport::FuncTime();
    }
    void FuncPrice()
    {
        Transport::FuncPrice();
    }

    void Print()const override
    {
        cout << "------------Bicycle-------------" << endl;
        cout << "Model: " << name << endl;
        cout << "Km/h: " << km_h << endl;
        cout << "Count of passengers: " << count_of_passangers << endl;
        cout << "Max count of passengers: " << MAX_count_of_passangers << endl;
        cout << "Distance: " << distance << " km"<<endl;
        cout << "Price per 1 km: " << price_per_1_km << "$" << endl;
        cout << "Has trunk(1 - yes, 0 - no): " << hasTrunk <<endl;
        cout << "Price: " << price << "$" << endl;
        cout << "Time: " << time << " hours" << endl;
        cout << "-----------------------------" << endl;
    }
};

class Cart:public Transport
{
    int count_of_horses;
public:
    Cart() :Transport(), count_of_horses(0){}
    Cart(string n, int km_h, int c, double d, double p, int h) :count_of_horses(h), Transport(n, km_h, c, 2, d, p)
    {
        if (count_of_horses > 0 && count_of_horses <= 4)
            count_of_horses = h;
        else
            count_of_horses = 0;

    }
    void FuncTime()
    {
        Transport::FuncTime();
    }
    void FuncPrice()
    {
        Transport::FuncPrice();
    }
    void Print()const override
    {
        cout << "------------Cart-------------" << endl;
        cout << "Cart: " << name << endl;
        cout << "Km/h: " << km_h << endl;
        cout << "Count of passengers: " << count_of_passangers << endl;
        cout << "Max count of passengers: " << MAX_count_of_passangers << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Price per 1 km: " << price_per_1_km << endl;
        cout << "Count of horses: " << count_of_horses << endl;
        cout << "Price: " << price << endl;
        cout << "Time: " << time << " hours" << endl;
        cout << "-----------------------------" << endl;
    }
};

void DeleteByIndex(Transport**& arr,int& size,int index)
{
    if (index < 0 || index >= size) {
        cout << "Error: Invalid index!" << endl;
        return;
    }
    delete arr[index];
    if (size == 1) {
        delete[] arr;
        arr = nullptr;
        size = 0;
        return;
    }
    Transport** temp = new Transport * [size - 1];
    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = index+1; i < size; i++)
    {
        temp[i-1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size--;
}
void AddByIndex(Transport**& arr,int& size,int index,Transport* value)
{
    if (index < 0 || index > size) {
        cout << "Error: Invalid index!" << endl;
        delete value;
        return;
    }
    
    Transport** temp = new Transport * [size + 1];
    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i];
    }
    temp[index] = value;
    for (int i = index; i < size; i++)
    {
        temp[i+1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size++;
}

int main()
{
    int size = 0;
    Transport** transports = nullptr;
    AddByIndex(transports,size,0, new Car("BMW M5", 120, 3, 240, 10.5, 600));
    AddByIndex(transports,size,1, new Bicycle("Trek Marlin", 20, 1, 40, 2, true));
    AddByIndex(transports,size,2, new Cart("Wooden Cart", 15, 2, 30, 5, 2));

    for (int i = 0; i < size; i++)
    {
        transports[i]->FuncTime();
        transports[i]->FuncPrice();
        transports[i]->Print();
        cout << endl;
    }

    DeleteByIndex(transports, size, 1);

    for (int i = 0; i < size; i++) {
        transports[i]->Print();
    }

    for (int i = 0; i < size; i++) {
        delete transports[i];
    }

    delete[]transports;










    Parrot parrot("Kesha", "House", 0.5, 5, true);
    // ЯКЩО РОЗКОМЕНТУВАТИ ТО БУДЕ ЗВУК
    //parrot.MakeSound();
    //parrot.Move();
    //parrot.Show();
    ////Animal animal("Tom", "Flat", 12);
    ////animal.Move();
    ////animal.Show();
    ////animal.MakeSound();

    Frog frog("Crazy frog", "Lake", 0.2, 2);
    // ЯКЩО РОЗКОМЕНТУВАТИ ТО БУДЕ ЗВУК
    //frog.MakeSound();
    //frog.Move();
    //frog.Show();


    Dog dog("Roki", "Flat", 12, "Taksa");
    //dog.Show();
    //dog.Move();








    // ЯКЩО РОЗКОМЕНТУВАТИ ТО БУДЕ ЗВУК ГАВКАННЯ
    //dog.MakeSound();

    //RollCall(dog);
    //RollCall(parrot);
    //RollCall(frog);
}

