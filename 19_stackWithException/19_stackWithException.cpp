#include <iostream>
using namespace std;
template<typename T>
class Stack
{
private:
    enum { EMPTY = -1 };
    T* arr;
    int size;
    int topIndex;
public:
    Stack() = default;
    Stack(int size) 
    {
        if (size > 0)
        {
            this->size = size;
            arr = new T[size];
            topIndex = -1;
        }
        else
            throw length_error("size < 0");
        
    }
    Stack(initializer_list<T>list)
    {
        this->size = list.size();
        arr = new T[size];
        int i = 0;
        for (T elem : list)
        {
            arr[i] = elem;
            i++;
        }
    }
    ~Stack()
    {
        if (arr != nullptr)
            delete[]arr;
    }
    bool isFull()
    {
            return topIndex == size - 1;
        
    }
    bool Push(T elem)
    {
        if (!isFull())
        {

            arr[++topIndex] = elem;
            return true;
        }
        else
            throw exception("Stack is full");
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
        else
            throw exception("Stack is empty");
    }
    int GetCount()
    {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    T Peek()
    {
        if (!isEmpty())
        {
            return arr[topIndex];
        }
        else
            throw exception("Stack is empty");
    }
    void Print()
    {
        cout << "Size = " << size << endl;
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void resize()
    {
        if (topIndex == size - 1)
        {
            int newSize = size * 2;
            T* temp = new T[newSize];
            for (int i = 0; i <= topIndex; i++)
            {
                temp[i] = arr[i];
            }
            delete[]arr;
            arr = temp;
            size = newSize;
        }


    }
};

int main()
{

    try
    {
        Stack<int> s(10);
        
        for (int i = 0; i < 5; i++)
        {
        s.Push(15);

        }
        s.Pop();
        s.Pop();
        s.Pop();
        s.Pop();
        s.Pop();
        
        s.Peek();
        s.resize();
    }
    catch (length_error ex)
    {
        cout << "Length error" << endl;
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

