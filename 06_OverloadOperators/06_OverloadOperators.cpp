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
    explicit Point(int value)
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
    
    Point operator--()
    {
        --this->x;
        --this->y;
        return *this;
    }
    Point operator++(int)
    {
        this->x++;
        this->y++;
        return *this;
    }
    Point operator--(int)
    {
        this->x--;
        this->y--;
        return *this;
    }
#pragma endregion
#pragma region Logic operators < > <= >= ! == !=
    bool operator > (const Point& other)
    {
        return ((this->x + this->y) > (other.x + other.y));
    }
    bool operator < (const Point& other)const
    {
        return ((this->x + this->y) < (other.x + other.y));
    }
    bool operator >= (const Point& other)const
    {
        return ((this->x + this->y) >= (other.x + other.y));
    }
    
    bool operator == (const Point & other)const
    {
        return ((this->x == other.x) && (this->y == other.y));
    }
    bool operator != (const Point & other)const
    {
        //return ((this->x != other.x) && (this->y != other.y));
        return !(*this == other);
    }


#pragma endregion
   
    int getX()const { return x; }
    int getY()const { return y; }
    void SetX(int newX) { this->x = newX; }
    void SetY(int newY) { this->y = newY; }
    friend Point operator++(Point& point);
    friend ostream& operator << (ostream& out, const Point& point);
    friend istream& operator >> (istream& in, Point& point);
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

//global function

bool operator <= (const Point& left,const Point& right)
{
    return ((left.getX() + left.getY()) <= (right.getX() + right.getY()));
}
Point operator++(Point &point)
{
    point.x++;
    point.y++;
    //point.SetX(point.getX()+1);
    //point.SetX(point.getX()+1);
    
    
    return point;
}
ostream& operator << (ostream& out, const Point& point)
{
    out << "X [ " << point.x << "]" << "   Y[" << point.y << "]";
    return out;
}
istream& operator >> (istream& in, Point& point)
{
    in >> point.x;
    in >> point.y;
    return in;
}

class Book {
    string author;
    string name;
    string publish;
    int year;
    int pages;
public:
    Book() {
        this->author = "No author";
        this->name = "No name";
        this->publish = "No publisher";
        this->year = 0;
        this->pages = 0;
    }
    Book(string author, string name, string publish, int year, int pages) {
        this->author = author;
        this->name = name;
        this->publish = publish;
        this->year = year;
        this->pages = pages;
    }
    Book(const Book& other) {
        this->author = other.author;
        this->name = other.name;
        this->publish = other.publish;
        this->year = other.year;
        this->pages = other.pages;
    }
    explicit Book(int year) {
        this->author = "No author";
        this->name = "No name";
        this->publish = "No publisher";
        this->year = year;
        this->pages = 0;
    }
    void Print()const {
        cout << "Author: " << author << '\n';
        cout << "Name: " << name << '\n';
        cout << "Publish: " << publish << '\n';
        cout << "Year: " << year << '\n';
        cout << "Pages: " << pages << '\n';
    }
    string getAuthor()const {
        return author;
    }
    string getPublis()const {
        return publish;
    }
    int getYear()const {
        return year;
    }
};
class Library {
    Book* books;
    int countBooks;
public:
    Library() {
        books = nullptr;
        countBooks = 0;
    }
    ~Library() {
        if (countBooks != 0) delete[] books;
    }
    void PrintAll() {
        for (int i = 0; i < countBooks; i++) {
            books[i].Print();
            cout << '\n';
        }
    }
    void PrintAuthor(string author)const {
        for (int i = 0; i < countBooks; i++)
            if (books[i].getAuthor() == author) books[i].Print();
    }
    void PrintPublish(string publish)const {
        for (int i = 0; i < countBooks; i++)
            if (books[i].getPublis() == publish) books[i].Print();
    }
    void PrintYear(int year)const {
        for (int i = 0; i < countBooks; i++)
            if (books[i].getYear() > year) books[i].Print();
    }
    void addBook(Book& book) {
        Book* temp = new Book[countBooks + 1];
        for (int i = 0; i < countBooks; i++) {
            temp[i] = books[i];
        }
        temp[countBooks] = book;
        delete[] books;
        books = temp;
        countBooks++;
    }
};


int main()
{
    //lesson2
    int a = 5, b = 4;
    Point p1(5, 3);
    Point p2(7, 8);
    //ostream cout;
    cout << p1;
    p1.Print();
    ++p1;
    p1.Print();
    --p1;
    p1.Print();

    p1++;
    p1.Print();
    p1--;
    p1.Print();
    cout << "Enter point x and y: ";

















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
