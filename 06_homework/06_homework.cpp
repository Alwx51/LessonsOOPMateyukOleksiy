#include <iostream>
using namespace std;

class Array
{
    int* arr;
    int size;
public:
    Array()
    {
        size = 0;
        arr = nullptr;
    }
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
    }
    Array(int size, int num)
    {
        this->size = size;
        arr = new int[size];
    }
    ~Array()
    {
        if (arr != nullptr)
            delete[]arr;
    }
    int getSize()const
    {
        return size;
    }
    int getValue(int index)
    {
        return arr[index];
    }
    void setValue(int num, int index)
    {
        arr[index] = num;
    }
    void PrintArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
    }

    void ChangeArray(int num)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] += num;
        }
    }
    void operator()(int num)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] += num;
        }
    }

};






int main()
{
    Array arr(10);
    arr.PrintArray();

    cout<<arr[5]<<endl;
    arr.ChangeArray(5);
    arr.PrintArray();
    arr(10);
    arr.PrintArray();

}