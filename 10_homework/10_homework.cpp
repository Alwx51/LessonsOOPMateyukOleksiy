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
    Stack(int size) :size(size)
    {
        arr = new T[size];
        topIndex = -1;
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
    T Peek()
    {
        if (!isEmpty())
        {
            return arr[topIndex];
        }
    }
    void Print()
    {
        cout <<"Size = "<< size << endl;
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void resize()
    {
        if (topIndex == size-1)
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
    Stack<char> st(15);
    st.Push('v');
    st.Push('e');
    st.Push('r');
    st.Push('i');
    st.Push('t');
    st.Push('y');
    st.Print();
    st.Push('v');
    st.Push('e');
    st.Push('r');
    st.Push('i');
    st.Push('t');
    st.Push('y');
    st.Push('v');
    st.Push('e');
    st.Push('r');
    st.resize();
    st.Push('i');
    st.Push('t');
    st.Push('y');
    st.Push('v');
    st.Push('e');
    st.Push('r');
    st.Push('i');
    st.Push('t');
    st.Push('y');
    st.Push('v');
    st.Push('e');
    st.Push('r');
    st.Push('i');
    st.Push('t');
    st.Push('y');
    
    st.Print();
    

    Stack<char> st2({ 'v','e','r','i','t','y' });


}

