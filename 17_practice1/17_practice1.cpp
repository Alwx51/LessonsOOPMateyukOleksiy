#include <iostream>
using namespace std;
#include <windows.h>    

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
};

class Shape
{
protected:
    string type;
public:
    Shape() :type("no type") {}
    Shape(string t):type(t){}
    virtual void print()const = 0;
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
        cout << "Type: " << type << endl;
        for (int i = 0; i < width; i++)
        {
        gotoxy(point.x, point.y+i);
            for (int i = 0; i < height; i++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Point start = { 5,7 };
    Point end = { 15,17 };
    Point p = { 19,17 };

    Line l("line", start, end);
    l.print();

    Rectangleh r("rectangle", p, 6, 8);
    r.print();




}

