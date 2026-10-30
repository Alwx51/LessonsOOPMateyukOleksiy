#include <iostream>
using namespace std;
/*
class Stack
{
    enum { EMPTY = -1, FULL = 9 };
    int arr[FULL + 1];
    int topIndex;
public:
    //default delete
    Stack()
    {
        topIndex = EMPTY;
    }
    Stack(const Stack& other) = delete;

    bool isFull()
    {
        return topIndex == FULL;
    }
    bool Push(int elem)
    {
        if (!isFull())
        {
            
            arr[++topIndex] = elem;
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        return topIndex == EMPTY;
    }

    int Pop()
    {
        if (!isEmpty())
        {
            return arr[topIndex--];
            
        }
    }
    int GetCount()
    {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    int Peek()
    {
        if (!isEmpty())
        {
            return arr[topIndex];

        }
    }
    void Print()
    {
        for (int i = 0; i < topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
*/

class Stack
{
private:
    enum {EMPTY = -1};
    int* arr;
    int size;
    int topIndex;
public:
    Stack() = default;
    Stack(int size) :size(size)
    {
        arr = new int[size];
        topIndex = -1;
    }
    ~Stack()
    {
        if (arr != nullptr)
            delete[]arr;
    }
    bool isFull()
    {
        return topIndex == size-1;
    }
    bool Push(int elem)
    {
        if (!isFull())
        {

            arr[++topIndex] = elem;
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        return topIndex == EMPTY;
    }

    int Pop()
    {
        if (!isEmpty())
        {
            return arr[topIndex--];
        }
    }
    int GetCount()
    {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    int Peek()
    {
        if (!isEmpty())
        {
            return arr[topIndex];
        }
    }
    void Print()
    {
        for (int i = 0; i < topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(15);
    for (int i = 0; i < 7; i++)
    {
        st.Push(rand() % 50);
    }
    
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);
    cout << "Size = " << st.GetCount() << endl;
    st.Print();
    while (!st.isEmpty())
    {
        cout << "Delete elem: " << st.Pop() << endl;
        st.Print();
    }
    cout << "Size = " << st.GetCount() << endl;
















}

