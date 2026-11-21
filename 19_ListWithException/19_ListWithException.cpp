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
        Node() :prev(nullptr), value(0), next(nullptr) {}
        Node(Node* p, T v, Node* n) :prev(p), value(v), next(n) {}
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
    void AddToHead(T val) {
        Node* newNode = new Node(nullptr, val, head);
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
        if (isEmpty())
            throw exception("List is empty");
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
        if (isEmpty())
            throw exception("List is empty");
        if (tail->prev == nullptr)
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
    void DeleteByIndex(int index)
    {
        if (isEmpty())
            throw exception("List is empty");
        if (index<0)
            throw exception("Invalid index");
        Node* current = head;

        if (index == 0)
        {
            DeleteFromHead();
            return;
        }

        for (int i = 0; i < index; i++)
        {
            if (current != nullptr)
            {
                current = current->next;
            }
            else
                throw exception("Index out of range");
        }
        if (current == nullptr)
            throw exception("Index out of range");
        if (current == tail)
        {
            DeleteFromTail();
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
};

int main()
{
    try
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
        l.addToTail(100);
        l.addToTail(200);
        l.addToTail(300);
        l.Print();
        l.DeleteFromHead();
        l.Print();
        l.DeleteByIndex(4);
        l.Print();
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown error" << endl;
    }
}

