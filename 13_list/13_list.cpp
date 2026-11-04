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
        current = head;
        head = current.next;
        delete current;
    }
};

class Point
{
    int x;
    int y;
};
class Vector
{
    List<Point> points;
    int size;
    void AddPointToTail(Point p)
    {
        points.AddToHead(p);
    }
    void AddPointToHead(Point p)
    {
        points.AddToTail(p);
    }
    void DeletePointFromHead()
    {
        points.DeleteFromHead(p);
    }
    void DeletePointFromTail()
    {
        points.DeleteFromTail(p);
    }
};

int main()
{
    List l;
    /*for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }*/
    l.Print();
    l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    
    l.Print();
    l.DeleteFromTail();
    l.Print();
    l.DeleteFromTail();
    l.Print();
    









}


