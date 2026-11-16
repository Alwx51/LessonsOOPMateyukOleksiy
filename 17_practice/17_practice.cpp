#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    string place;
    int age;
    float weight;
public:
    Animal() : name("no name"), place("no place"), age(0), weight(0) {}
    Animal(string n, string p, int a, float w) : name(n), place(p), age(a)
    {
        weight = (w > 0) ? w : 0;
        age = (a > 0) ? a : 0;
    }

    int GetAge() const 
    {
        return age;
    }
    virtual int GetMaxAge() const = 0; 
    virtual void Show() const = 0;
    virtual void Grow()
    {
        age++; 
    }
};

class Fox : public Animal
{
    int max_age = 25;
public:
    Fox() : Animal() {}
    Fox(string n, string p, int a, float w) : Animal(n, p, a, w) {}
    int GetMaxAge() const override
    {
        return max_age; 
    }
    void Show() const override
    {
        cout << "Fox: " << name << " (Age: " << age << ")" << endl;
    }    
};

class Rabbit : public Animal
{
    int max_age = 5;
public:
    Rabbit() : Animal() {}
    Rabbit(string n, string p, int a, float w) : Animal(n, p, a, w) {}
    int GetMaxAge() const override { return max_age; }
    void Show() const override { cout << "Rabbit: " << name << " (Age: " << age << ")" << endl; }
    
};

int main()
{
    
}
