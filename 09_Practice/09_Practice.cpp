
#include "Point.h"
#include "Vector.h"

int main()
{
    Point point1(13, 45);
    Point point3(12, 44);
    point1.PrintAll();
    Point point2(2, 8);
    point2.PrintAll();

    
    point1++;
    point2++;
    point1.PrintAll();
    point2.PrintAll();
    point1--;
    point2--;
    point1.PrintAll();
    point2.PrintAll();

    Vector vector;
    vector.AddPoint(point3);
    vector.Print();
}