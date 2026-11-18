#include <iostream>
using namespace std;
#include <windows.h>   
#include <fstream>

void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

struct Point
{
    int x;
    int y;
    Point():x(0),y(0){}
    Point(int x,int y):x(x),y(y){}
    friend ostream& operator << (ostream& out, const Point& point)
    {
        out << "X [ " << point.x << "]" << "   Y[" << point.y << "]";
        return out;
    }
};

class Shape
{
protected:
    string type;
public:
    Shape() :type("no type") {}
    Shape(string t):type(t){}
    virtual void print()const = 0;
    virtual void saveToFile() = 0;
    virtual ~Shape() = 0 {};
};

class Line:public Shape
{
    Point start_line;
    Point end_line;
public:
    Line():Shape(){}
    Line(string t,Point s,Point e):start_line(s),end_line(e),Shape(t){}
    void print()const
    {
        cout << "Point 1:x = " << start_line.x << " y = " << start_line.y << endl;
        gotoxy(start_line.x, start_line.y); cout << "*";
        gotoxy(end_line.x, end_line.y); cout << "*";
        
    }
    void saveToFile()override
    {
        ofstream out;
        out.open("Line.txt");
        out << "Start line: "<<start_line<<" End line: "<<end_line;
        out << endl;
        out.close();
    }
};

class Rectangleh :public Shape
{
    Point point;
    int width;
    int height;
public:
    Rectangleh():Shape(){}
    Rectangleh(string t,Point p,int w,int h):point(p),width(w),height(h),Shape(t){}
    void print()const override
    {       
        for (int i = 0; i < height; i++)
        {
        gotoxy(point.x, point.y+i);
            for (int i = 0; i < width; i++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    void saveToFile()override
    {
        ofstream out;
        out.open("Rectangle.txt");
        out << "Point: "<<point;
        out << endl;
        out.close();
    }
};

class Polylineh:public Shape
{
    Point* dots;
    int count;
public:
    Polylineh() :dots(nullptr), count(0), Shape() {}
    Polylineh(string t, initializer_list<Point> list) :Shape(t)
    {
        this->count = list.size();
        dots = new Point[count];
        int i = 0;
        for (Point dot : list)
        {
            dots[i] = dot;
            i++;
        }
    }
    void print()const override
    {
        for (int i = 0; i < count; i++)
        {
            
            gotoxy(dots[i].x, dots[i].y + i);           
            cout << "o";
        }
        gotoxy(0, 26);
        cout << "Shape: " << type << endl;
        for (int i = 0; i < count; i++)
        {
            cout << dots[i] << " | ";
            
        }
    }
    ~Polylineh()
    {
        if (dots != nullptr)
            delete[]dots;
    }
    void saveToFile()override
    {
        ofstream out;
        out.open("Polyline.txt");
        for (int i = 0; i < count; i++)
        {
            out << dots[i] << " | ";
        }
        out << endl;
        out.close();
    }
};

int main()
{
    Point start = { 5,7 };
    Point end = { 15,17 };
    Point p = { 19,17 };
    Point p2 = { 3,8 };
    Point p3 = { 6,1 };
    Point p4 = { 9,15 };
    Point p5 = { 2,6 };

    Line l("line", start, end);
    l.print();
    l.saveToFile();


    Rectangleh r("rectangle", p, 6, 8);
    r.print();
    r.saveToFile();
    
    Polylineh poly("Lamana liniya", { p2,p3,p4,p5 });
    poly.print();
    poly.saveToFile();



}

