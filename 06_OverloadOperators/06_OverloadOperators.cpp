#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(int value)
    {
        this->x = value;
        this->y = value;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()
    {
        cout << "X = " << x << " Y = " << y << endl;
    }
    Point Plus(const Point &other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point Minus(const Point &other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    //Overloads operators
    //void operator [symbol operator](){}
#pragma region math operator



    Point operator +(const Point& other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator -(const Point& other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator *(const Point& other)
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }
    Point operator /(const Point& other)
    {
        Point res(this->x / other.x, this->y / other.y);
        return res;
    }
#pragma endregion
#pragma region Binary Operators
    Point operator +=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Point operator = (const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
#pragma endregion
#pragma region Uno operators
    Point operator -()
    {
        //return(this->x * -1, this->y * -1);
        return Point(-x, -y);
    }
#pragma endregion
#pragma region Logic operators < > <= >= ! == !=
    bool operator > (const Point& other)
    {
        return ((this->x + this->y) > (other.x + other.y));
    }
    bool operator < (const Point& other)
    {
        return ((this->x + this->y) < (other.x + other.y));
    }
    bool operator >= (const Point& other)
    {
        return ((this->x + this->y) >= (other.x + other.y));
    }
    bool operator <= (const Point & other)
    {
        return ((this->x + this->y) <= (other.x + other.y));
    }
    bool operator == (const Point & other)
    {
        return ((this->x == other.x) && (this->y == other.y));
    }
    bool operator != (const Point & other)
    {
        //return ((this->x != other.x) && (this->y != other.y));
        return !(*this == other);
    }


#pragma endregion
   
};

class Time
{
    int hours;
    int minutes;
    int seconds;
public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    explicit Time(int sec)
    {
        hours = sec / 3600;
        minutes = sec / 60 % 60;
        seconds = sec % 60;
    }
    Time(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    void PrintTime()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    int TotalSeconds()const
    {
        int totals = hours*3600+minutes*60+seconds;
        return totals;
    }
    void TimeToHMS(int totals)
    {
        hours = totals / 3600;
        minutes = totals / 60 % 60;
        seconds = totals % 60;
    }
    void AddOneSec()
    {
        int s = TotalSeconds();
        s++;
        TimeToHMS(s);
    }
    Time operator +(const Time& other)
    {
        //Time res(this->hours + other.hours, this->minutes + other.minutes,this->seconds + other.seconds);
        Time res(this->TotalSeconds() + other.TotalSeconds());
        return res;
    }
    Time operator -(const Time& other)
    {
        //Time res(this->hours + other.hours, this->minutes + other.minutes,this->seconds + other.seconds);
        Time res(this->TotalSeconds() - other.TotalSeconds());
        return res;
    }
    Time operator *(const Time& other)
    {
        //Time res(this->hours + other.hours, this->minutes + other.minutes,this->seconds + other.seconds);
        Time res(this->TotalSeconds() * other.TotalSeconds());
        return res;
    }
    Time operator /(const Time& other)
    {
        //Time res(this->hours + other.hours, this->minutes + other.minutes,this->seconds + other.seconds);
        Time res(this->TotalSeconds() / other.TotalSeconds());
        return res;
    }
    bool operator > (const Time& other)
    {
        return (this->TotalSeconds() > other.TotalSeconds());
    }
    bool operator < (const Time& other)
    {
        return (this->TotalSeconds() < other.TotalSeconds());
    }
    bool operator >= (const Time& other)
    {
        return (this->TotalSeconds() >= other.TotalSeconds());
    }
    bool operator <= (const Time & other)
    {
        return (this->TotalSeconds() <= other.TotalSeconds());
    }
    bool operator == (const Time& other)
    {
        return (this->TotalSeconds() == other.TotalSeconds());
    }
    bool operator != (const Time& other)
    {
        return !(*this == other);
    }
};

int main()
{
    //practice
    //Time t1(5555);
    Time t1(11, 59, 59);
    t1.PrintTime();
    t1.AddOneSec();
    t1.PrintTime();

    Time t2(10, 45, 9);
    Time res = t1 + t2;
    res.PrintTime();





    //int hours = 5555/3600
    //int minute = 5555/60%60
    //int sec = 5555%60

    int a = 5, b = 4;
    Point p1(5, 3);
    Point p2(7, 8);
    //Point res = p1 + p2;
    //res = p1 - p2;
    //res = p1 * p2;

    //Point res = p1.Plus(p2);
    //cout << "Point 1:";p1.Print();
    //cout << "Point 2:";p2.Print();
    //cout << "Res: "; res.Print();
    //res = p1.Minus(p2);
    //cout << "Res: "; res.Print();

    //res = p1 + p2;//res = p1.operator+(p2);
    //cout << "Res: ";res.Print();
    //res = p1 + p2;//res = p1.operator-(p2);
    //cout << "Res: ";res.Print();
    //res = p1 * p2; //res = p1.operator*(p2);
    //cout << "Res: ";res.Print();
    //res = p1 / p2;//res = p1.operator/(p2);
    //cout << "Res: ";res.Print();

    //p1 += p2;

    //res = -p1;

    //p1 = p2;

    //if (p1 > p2)
    //    cout << "p1 < p2" << endl;
    //else
    //    cout << "p1 > p2" << endl;

    if (t1 > t2)
        cout << "t1 > t2" << endl;
    else
        cout << "t1 < t2" << endl;
    if (t1 == t2)
        cout << "t1 == t2" << endl;
    else
        cout << "t1 != t2" << endl;
}
