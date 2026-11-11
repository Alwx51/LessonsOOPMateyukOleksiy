#include <iostream>
#include <Windows.h>
using namespace std;

class Car
{
    string model;
    int year;
protected: 
    int speed;
    float volume;
public:
    Car():model("no model"),year(0),speed(0),volume(0){}
    Car(string m,int y, float v):model(m),year(y),speed(0),volume(v){}
    virtual void Drive()const
    {
        cout << "I am a Car! I can drive with speed: " << speed << "km/h" << endl;
    }
    void setSpeed(int speed)
    {
        if (speed > 0)
            this->speed = speed;
        else
            speed = 0;
    }
    virtual void print()const
    {
        cout << "------------Car---------------" << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Speed: " << speed << endl;
        cout << "Volume: " << volume << endl;
    }
};

class PoliceCar:public Car
{
    int soundVolume;
public:
    PoliceCar():soundVolume(0),Car(){}
    PoliceCar(string m, int y, float v, int s) :soundVolume(s), Car(m,y,v) {}
    void Drive()const override
    {
        cout << "I am a police car. I can drive with speed " << speed << "km/h" << endl;
    }
    void print()const override
    {
        Car::print();
        cout << "Sound volume: " << soundVolume << "db" << endl;
    }
    void BeepBeep()
    {
        Beep(500, 300);
        Beep(400, 200);
        Beep(1000, 200);
    }
};
class SportCar:public Car
{
    int turboSpeed;
public:
    SportCar():turboSpeed(0),Car(){}
    SportCar(string m, int y, float v, int ts) :turboSpeed(ts), Car(m,y,v) {}
    void Drive()const
    {
        cout << "I am a sport car. I can drive with speed " << turboSpeed << "km/h" << endl;
    }
    void print()const override
    {
        Car::print();
        cout << "Turbo speed: " << turboSpeed<< endl;
    }
    void Nitro()
    {
        speed += turboSpeed;
        cout << "Turbo speed " << speed << "km/h" << endl;
    }
};

void TestDrive(Car& car)
{
    car.setSpeed(70);
    car.Drive();
    car.print();
}

class Shape
{
protected:
    string name;
    int area;
public:
    Shape():name("no name"),area(0){}
    Shape(string n):name(n), area(0) {}
    virtual void Show()const
    {
        cout << "---------------Figure------------------" << endl;
        cout << "Name: " << name << endl;
    }
    virtual void GetArea()
    {
        cout << "---------------Area------------------" << endl;
    }
};

class Rectangle:public Shape
{
    int height;
    int width;
    
public:
    Rectangle():height(0),width(0),Shape(){}
    Rectangle(string n,int h,int w):height(h),width(w),Shape(n){}
    void Show()const override
    {
        cout << "---------------Rectangle------------------" << endl;
        Shape::Show();
        cout << "Height: " << height << endl;
        cout << "Width: " << height << endl;
    }
    void GetArea() override
    {
        cout << "---------------Area------------------" << endl;
        area = height * width;
        cout << "Area of rectangle: " << area << endl;
    }
};

class Circle:public Shape
{
    int radius;
    int diametr;
    const int pi = 3.14;
public:
    Circle():radius(0),diametr(0),Shape(){}
    Circle(string n,int r):radius(r),diametr(r*2),Shape(n) {}
    void Show()const override
    {
        cout << "---------------Circle------------------" << endl;
        Shape::Show();
        cout << "Radius: " << radius << endl;
        cout << "Diametr: " << diametr << endl;
    }
    void GetArea() override
    {
        cout << "---------------Area------------------" << endl;
        area = pi * radius * radius;
        cout << "Area of circle: " << area << endl;
    }


};

int main()
{
    Car car("BMW", 2024, 3.0);
    car.setSpeed(280);
    car.Drive();
    car.print();


    PoliceCar police_car("Renult Duster",2025,1.6,500);
    police_car.setSpeed(220);
    police_car.print();
    police_car.Drive();
    police_car.BeepBeep();

    SportCar sport("Formula 1", 2026, 4.5, 100);
    sport.setSpeed(400);
    sport.Drive();
    sport.print();

    TestDrive(car);
    TestDrive(police_car);
    TestDrive(sport);

    Car* cars[3]{
        new Car("BMW", 2024, 3.0),
        new PoliceCar("Renult Duster", 2025, 1.6, 500),
        new SportCar("Formula 1", 2026, 4.5, 100)
    };

    for (int i = 0; i < 3; i++)
    {
        cars[i]->Drive();
        cars[i]->print();
        delete cars[i];
    }
}