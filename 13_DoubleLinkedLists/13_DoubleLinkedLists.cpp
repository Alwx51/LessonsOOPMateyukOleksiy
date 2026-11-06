#include <iostream>
using namespace std;

template<typename T>
class List
{
    struct Node
    {
        Node* prev;
        T value;
        Node* next;
        Node():prev(nullptr),value(0),next(nullptr){}
        Node(Node *p, T v, Node *n):prev(p),value(v),next(n){}
    };

private:
    Node* head;
    Node* tail;
public:
    List()
    {
        head = tail = nullptr;
    }
    bool isEmpty()const
    {
        return head == nullptr;
    }
    void AddToHead(T val){
        Node* newNode = new Node(nullptr,val,head);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
    }

    void Print()
    {
        Node* current = head;
        /*
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;

        }
        cout << endl;*/

        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
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
    void addToTail(T value)
    {
        Node* newNode = new Node(tail, value, nullptr);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        

    }
    void DeleteFromHead()
    {
        if (isEmpty())return;
        if (head->next == nullptr)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        
    }
    
    void DeleteFromTail()
    {
        if (isEmpty())return;
        if (tail->prev==nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        

    }
};
struct Vagon
{
    int vagonNum;
    int seatsAmount;
    int countOfPassangers;
    Vagon() :vagonNum(0), seatsAmount(0), countOfPassangers(0) {}
    Vagon(int vagonN, int seatsA, int countOfP) :vagonNum(vagonN), seatsAmount(seatsA), countOfPassangers(countOfP) {}
};
ostream& operator << (ostream& out, const Vagon& v)
{
    out << "[" << v.vagonNum << "]" << "  [" << v.seatsAmount << "]"<< "  [" << v.countOfPassangers << "]";
    return out;
}

class Train
{

   
    string model;
    List<Vagon> vagons;
    int countVagons;
public:
    Train() :model("no model"), countVagons(0){}
    Train(string model,int count) :model(model),countVagons(count){}
    void PrintAll()
    {
        vagons.Print();
    }
    void addVagonToHead(Vagon v)
    {
        vagons.AddToHead(v);
    }


};

int main()
{
    List<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }
    l.Print();
    l.addToTail(100);
    l.addToTail(200);
    l.addToTail(300);
    l.Print();
    l.DeleteFromTail();
    l.Print();
    l.DeleteFromTail();
    l.Print();

    

}
