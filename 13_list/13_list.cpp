#include <iostream>
using namespace std;


template<typename T>
class List
{
    struct Node
    {
        T value;
        Node* next;
        Node() :value(0), next(nullptr) {}
        Node(T value, Node* next) :value(value), next(next) {}
    };
    Node* head;
    
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(T value)
    {
        Node* newNode = new Node(value,head);
        /*newNode->value = value;
        newNode->next = head;*/

        head = newNode;
    }
    void Print()
    {
        Node* current = head;
        while (current!=nullptr)
        {
            cout << current->value << " ";
            current = current->next;
            
        }
        cout << endl;
    }
    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(T value)
    {
        Node* newNode = new Node(value, nullptr);
        if (head==nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void DeleteFromTail()
    {
        if (head == nullptr)return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }       
    }
    void DeleteFromHead()
    {
        if (head == nullptr)return;
        Node* current = head;
        head = current->next;
        delete current;
    }
};

class Point
{
    int x;
    int y;
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
    void printCoord()
    {
        cout << "X = " << x << endl;
        cout << "Y= " << y << endl;
    }
    friend ostream& operator<<(ostream& out, const Point& p)
    {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};
class Vector
{
    List<Point> points;
    int size;
public:
    Vector():size(0){}
    void AddPointToTail(Point p)
    {
        points.AddToTail(p);
        size++;
    }
    void AddPointToHead(Point p)
    {
        points.AddToHead(p);
        size++;
    }
    void DeletePointFromHead()
    {
        if (size == 0)
        {
            return;
        }
        points.DeleteFromHead();
        size--;
    }
    void DeletePointFromTail()
    {
        points.DeleteFromTail();
        size--;
    }
    void Print()
    {
        points.Print();
    }
};

int main()
{
    List<int> l;
    /*for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }*/
    
    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    
    l.Print();
    l.DeleteFromTail();
    l.Print();
    l.DeleteFromTail();
    l.Print();
    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    l.Print();
    l.DeleteFromHead();
    l.Print();









}


