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

class Airplane
{
    string model;
    string type;
    int count_passengers;
    int max_passengers;
public:
    Airplane()
    {
        model = "no model";
        type = "no type";
        count_passengers = 0;
        max_passengers = 0;
    }
    Airplane(string model, string type,int count_passengers,int max_passengers)
    {
        this->model = model;
        this->type = type;
        this->count_passengers = count_passengers;
        this->max_passengers = max_passengers;
    }
    
    Airplane operator++ ()
    {
        if (count_passengers<max_passengers)
        {
            ++this->count_passengers;
        }
        else
        {
            cout << "Error the object is full" << endl;
        }
        
        return *this;
    }
    Airplane operator-- ()
    {
        if (count_passengers>0)
        {
            --this->count_passengers;
        }
        else
        {
            cout << "Error" << endl;
        }
        return *this;
    }
    
    void operator()(int num)
    {
        if (count_passengers + num<= max_passengers)
        {
            count_passengers += num;
        }
        else
        {
            cout << "Error the object is full" << endl;
        }
    }

    void Print()
    {
        cout << "Model: " << model<<endl;
        cout << "Type: " << type << endl;
        cout << "Count of passengers: " << count_passengers << endl;
        cout << "Max passengers: " << max_passengers << endl;
    }

    friend bool operator == (const Airplane& left,const Airplane& right);
    friend bool operator> (const Airplane& left, const Airplane& right);
};

bool operator==(const Airplane& left,const Airplane& right)
{
    return left.type == right.type;
}

bool operator> (const Airplane& left,const Airplane& right)
{
    return left.count_passengers > right.count_passengers;
}

int main()
{
    //task1
    Array arr(10);
    arr.PrintArray();

    cout<<arr[5]<<endl;
    arr.ChangeArray(5);
    arr.PrintArray();
    arr(10);
    arr.PrintArray();
    //task2
    Airplane airplane1("Boeing 737", "Passenger", 140, 150);
    Airplane airplane2("Airbus A320", "Passenger", 130, 180);
    airplane1.Print();
    cout << "--------"<<endl;
    airplane2.Print();
    cout << "--------" << endl;
    if (airplane1 == airplane2)
    {
        cout << "Airplane1 type == airplane2 type"<<endl;
    }
    ++airplane1;
    ++airplane2;
    airplane1.Print();
    cout << "--------" << endl;
    airplane2.Print();
    if (airplane1 > airplane2)
    {
        cout << "Airplane2 > airplane1" << endl;
    }
    airplane1(15);
    airplane2(15);
    airplane1.Print();
    cout << "--------" << endl;
    airplane2.Print();
}