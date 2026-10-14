#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

class Student
{
    string name;
    int age;
    int* marks;
    int countMarks;
public:
    Student()
    {
        this->name = "no name";
        this->age = 0;
        this->marks = nullptr;
        this->countMarks = 0;
    }
    Student(string name,int age)
    {
        this->name = name;
        this->age = age;
        this->marks = nullptr;
        this->countMarks = 0;
    }
    Student(const Student& other)
    {
        this->name = other.name;
        this->age = other.age;
        this->marks = other.marks;
        this->countMarks = other.countMarks;
        this->marks = new int[countMarks];
        for (int i = 0; i < countMarks; i++)
        {
            this->marks[i] = other.marks[i];
        }
    }
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Count marks: " << countMarks << endl;
        cout << "Marks: ";
        for (int i = 0; i < countMarks; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
    void AddMark(int mark)
    {
        int* temp = new int[countMarks + 1];
        for (int i = 0; i <countMarks; i++)
        {
            temp[i] = marks[i];
        }
        temp[countMarks] = mark;
        
    }
    void Delete()
    {
        if (marks != nullptr)
        {
            delete[]marks;
        }
    }
    ~Student()
    {
        Delete();
    }
};

class Array
{
    long* arr;
    int size;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }
    Array(int size)
    {
        this->size = size;
        arr = new long[size] {};
    }
    Array(const Array& other)
    {
        this->size = other.size;
        this->arr = new long[size];
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

        
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void FillRandom()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
    }

    void InitArr()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter " << i << " number: ";cin >> arr[i];

                
                
        }
    }
    void AddElement(int arr1)
    {
        long* temp = new long[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        temp[size] = arr1;
        delete[]arr;
        size++;
        arr = temp;
    }
    void DeleteElement(int index)
    {
        if (index < 0 || index >= size)  
            return;
        long* temp = new long[size - 1];
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        for (int i = index; i < size-1; i++)
        {
            temp[i] = arr[i + 1];
        }
        delete[]arr;
        arr = temp;
        size--;
        
    }

    void BubbleSort()
    {
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (arr[j - 1] > arr[j])
                {
                    temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;

                }
            }
        }
    }
    void BubbleSort1()
    {
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (arr[j - 1] < arr[j])
                {
                    temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;

                }
            }
        }
    }

    long FindMin()
    {
        long min = arr[0];

        for (int i = 1; i < size; i++)
        {
            if (arr[i]<min)
            {
                min = arr[i];   
            }
        }
        return min;
    }
    long FindMax()
    {
        long max = arr[0];

        for (int i = 1; i < size; i++)
        {
            if (arr[i]>max)
            {
                max = arr[i];   
            }
        }
        return max;
    }

    ~Array()
    {
        delete[]arr;
    }
};

int main()
{
    Array arr(15);
    arr.Print();
    cout << endl;
    arr.FillRandom();
    arr.Print();
    cout << endl;
    arr.InitArr();
    arr.Print();
    cout << endl;
    arr.AddElement(90);
    arr.Print();
    cout << endl;
    arr.DeleteElement(2);
    arr.Print();
    cout << endl;
    arr.BubbleSort();
    arr.Print();
    cout << endl;
    arr.BubbleSort1();
    arr.Print();
    cout << endl;
    cout << "Min: "<<arr.FindMin() << endl;
    cout << "Max: "<<arr.FindMax() << endl;
    Student st;
    st.Print();



    //Student student("Ivan", 18);
    //student.Print();
    //student.AddMark(12);
    //student.AddMark(7);
    //student.AddMark(9);
    //student.AddMark(4);
    //student.AddMark(10);
    //student.Print();

    //Student copy = Student(student);

    //cout << "Original " << endl;
    //student.Print();
    //cout << "Copy" << endl;
    //copy.Print();

    //Point point{ 15,25 };
    //int number = 2;//ініціалізація з копіюванням
    //int value(2);//пряма ініціалізація
    //int size{33};//уніфікована ініціалізація

    //const float goodTemp{ 36.6 };
    //int marks[3]{ 1,4,7 };
    //int matrix[2][2]{ {1,2},{3,5} };
}
