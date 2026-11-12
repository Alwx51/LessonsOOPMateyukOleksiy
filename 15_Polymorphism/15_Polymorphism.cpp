#include <iostream>
//#include <Windows.h>
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
    //void BeepBeep()
    //{
    //    Beep(500, 300);
    //    Beep(400, 200);
    //    Beep(1000, 200);
    //}
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
    double area;
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
    virtual void Draw()const
    {
        cout << "---------------Draw------------------" << endl;
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
        cout << "Width: " << width << endl;
    }
    void GetArea() override
    {
        cout << "---------------Area------------------" << endl;
        area = height * width;
        cout << "Area of rectangle: " << area << endl;
    }
    void Draw()const override
    {
        cout << "---------------Draw------------------" << endl;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

class Circle:public Shape
{
    int radius;
    int diametr;
    const double pi = 3.14;
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
    void Draw() const override
    {
        for (int y = -radius; y <= radius; y++)
        {
            for (int x = -radius; x <= radius; x++)
            {
                if (x * x + y * y <= radius * radius)
                    cout << "* ";
                else
                    cout << "  ";
            }
            cout << endl;
        }
    }
    

};

class Triangle90:public Shape
{
    int first_leg;
    int second_leg;
public:
    Triangle90():first_leg(0),second_leg(0),Shape(){}
    Triangle90(string n,int f,int s):first_leg(f), second_leg(s), Shape(n) {}
    void Show()const override
    {
        cout << "---------------Triangle90------------------" << endl;
        Shape::Show();
        cout << "First leg: " << first_leg << endl;
        cout << "Second leg: " << second_leg << endl;
    }
    void GetArea() override
    {
        cout << "---------------Area------------------" << endl;
        area = (first_leg*second_leg)/2.0;
        cout << "Area of triangle90: " << area << endl;
    }
    void Draw()const override
    {
        cout << "---------------Draw------------------" << endl;
        for (int i = 0; i < first_leg; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

class Triangle:public Shape
{
    int basis;
    int height;
public:
    Triangle():basis(0),height(0),Shape(){}
    Triangle(string n,int b,int h):basis(b), height(h), Shape(n) {}
    void Show()const override
    {
        cout << "---------------Triangle------------------" << endl;
        Shape::Show();
        cout << "Basis: " << basis << endl;
        cout << "Height: " << height << endl;
    }
    void GetArea() override
    {
        cout << "---------------Area------------------" << endl;
        area = 0.5 * basis * height;
        cout << "Area of triangle: " << area << endl;
    }
    void Draw()const override
    {
        cout << "---------------Draw------------------" << endl;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < height-i-1; j++)
            {
                cout << "  ";
            }
            for (int j = 0; j < 2*i+1; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

class Trapeze:public Shape
{
    int basis1;
    int basis2;
    int height;
public:
    Trapeze():basis1(0),basis2(0),height(0),Shape(){}
    Trapeze(string n,int b1,int b2,int h):basis1(b1),basis2(b2),height(h),Shape(n){}
    void Show()const override
    {
        cout << "---------------Trapeze------------------" << endl;
        Shape::Show();
        cout << "Basis1: " << basis1 << endl;
        cout << "Basis2: " << basis2 << endl;
        cout << "Height: " << height << endl;
    }
    void GetArea() override
    {
        cout << "---------------Area------------------" << endl;
        area = (basis1 + basis2) / 2.0 * height;
        cout << "Area of trapeze: " << area << endl;
    }
    void Draw() const override
    {
        int top = min(basis1, basis2);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < height - i - 1; j++)
            {
                cout << "  ";
            }
            for (int j = 0; j < top + 2 * i; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

void TestShape(Shape& shape)
{
    shape.Show();
    shape.GetArea();
    shape.Draw();
}

int main()
{

    Rectangle rectangle("rectangle", 10, 20);
    Circle circle("circle", 4);
    Triangle90 triangle90("triangle90", 4,6);
    Triangle triangle("triangle",9,8);
    Trapeze trapeze("trapeze",9,8,7);


    TestShape(rectangle);
    TestShape(circle);
    TestShape(triangle90);
    TestShape(triangle);
    TestShape(trapeze);

    //Car car("BMW", 2024, 3.0);
    //car.setSpeed(280);
    //car.Drive();
    //car.print();


    //PoliceCar police_car("Renult Duster",2025,1.6,500);
    //police_car.setSpeed(220);
    //police_car.print();
    //police_car.Drive();
    //police_car.BeepBeep();

    //SportCar sport("Formula 1", 2026, 4.5, 100);
    //sport.setSpeed(400);
    //sport.Drive();
    //sport.print();

    //TestDrive(car);
    //TestDrive(police_car);
    //TestDrive(sport);

    //Car* cars[3]{
    //    new Car("BMW", 2024, 3.0),
    //    new PoliceCar("Renult Duster", 2025, 1.6, 500),
    //    new SportCar("Formula 1", 2026, 4.5, 100)
    //};

    //for (int i = 0; i < 3; i++)
    //{
    //    cars[i]->Drive();
    //    cars[i]->print();
    //    delete cars[i];
    //}
}