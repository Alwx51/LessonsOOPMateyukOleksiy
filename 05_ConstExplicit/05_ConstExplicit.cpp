#include <iostream>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;
    void setDate(int day)
    {
        this->day = day;
    }
    int getDay()
    {
        day += 10;
        return day;
    }
    int getDay()const
    {
        int a = 5;
        a++;
        return day;
    }
    void Print()const
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

class Account {
private:
    double sum;
    const double rate;
public:
    Account(double sum, double rate):rate(rate)
    {
        this->sum = sum;
        
    }
    double getRate()const
    {
        return rate;
    }
    double getIncome()
    {
        return sum * rate / 100;
    }
    double getIncome()const
    {
        return sum * rate / 100;
    }
    double getSum()const
    {
        return sum;
    }
    double setSum()
    {
        sum += getIncome();
        return sum;
    }
};

void doSomething(long number)
{

}

float doSomething() { return 1.5; }

class Array
{
    int* arr;
    int size;
public:
    explicit Array(int size)
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
    void display(int index)const
    {
        cout << arr[index] << " ";
    }
        
};


void PrintArray(const Array &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.display(i);
    }
    cout << endl;
}

class Book {
private:
    string author;
    string name;
    string publisher;
    int year;
    int quantity;
    int number_of_pages;
public:
    Book()
    {
        author = "unknown";
        name = "unknown";
        publisher = "unknown";
        year = 0;
        quantity = 0;
        number_of_pages = 0;
    }
    Book(string author, string name, string publisher,
        int year, int quantity, int pages)
    {
        this->author = author;
        this->name = name;
        this->publisher = publisher;
        this->year = year;
        this->quantity = quantity;
        number_of_pages = pages;
        
    }
    string getAuthor()const
    {
        return author;
    }
    int getYear()const
    {
        return year;
    }
    string getPublisher()const
    {
        return publisher;
    }
    void print()const
    {
        cout << author << endl;
        cout << name << endl;
        cout << publisher << endl;
        cout << year << endl;
        cout << quantity << endl;
        cout << number_of_pages << endl;
    }
    
};

class Library
{
    Book* books;
    int size;
public:
    Library()
    {
        books = nullptr;
        size = 0;
    }
    explicit Library(int size)
    {
        books = nullptr;
        this->size = size;
    }
    void AddBook(Book book)
    {
        Book* temp = new Book[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = books[i];
        }
        temp[size] = book;
        this->size += 1;
        delete[]books;
        books = temp;
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            books[i].print();
        }
    };
    void PrintBookAnyAuthor(string a)const
    {
        for (int i = 0; i < size; i++)
        {   
            if (books[i].getAuthor()==a)
            {
                books[i].print();
            }
            
        }
    }
    void PrintBookAnyYear(int y)const
    {
        for (int i = 0; i < size; i++)
        {
            if (books[i].getYear() == y)
            {
                books[i].print();
            }
            
        }
    }
};

class Worker
{
    string name;
    string position;
    int year_of_starting_a_job;
    int salary;
public:
    Worker()
    {
        name = "no name";
        position = "no position";
        year_of_starting_a_job = 0;
        salary = 0;
    }
    
    Worker(string name, string position, int year_of_starting_a_job, int salary)
    {
        this->name = name;
        this->position = position;
        this->year_of_starting_a_job = year_of_starting_a_job;
        this->salary = salary;
    }
    int GetYear()const
    {
        return year_of_starting_a_job;
    }
    int GetSalary()const
    {
        return salary;
    }
    string GetPos()const
    {
        return position;
    }
    void Print()const
    {

        cout << name << endl;
        cout << position << endl;
        cout << year_of_starting_a_job << endl;
        cout << salary << endl;
    }
};
class Company
{
    Worker* workers;
    int size;
public:
    Company()
    {
        workers = nullptr;
        size = 0;
    }
    explicit Company(int size)
    {
        workers = nullptr;
        this->size = size;
    }
    Company(Worker arr[],int size)
    {
        workers = arr;
        this->size = size;
    }
    void PrintAll()const
    {
        for (int i = 0; i < size; i++)
        {
            workers[i].Print();
            cout << endl;
        }
    };
    void PrintWorkersByExperience(int y)const
    {
        int year = 2026;
        for (int i = 0; i < size; i++)
        {
            if (year - workers[i].GetYear() > y)
            {
                workers[i].Print();
                cout << endl;
            }
        }
    }
    void PrintWorkersBySalary(int s)const
    {
        for (int i = 0; i < size; i++)
        {
            if (workers[i].GetSalary()>s)
            {
                workers[i].Print();
                cout << endl;
            }
        }
    }
    void PrintWorkersByPosition(string p)const
    {
        for (int i = 0; i < size; i++)
        {
            if (workers[i].GetPos() == p)
            {
                workers[i].Print();
                cout << endl;
            }
        }
    }

};

int main()
{
    //1 task
    Library lib;
    lib.AddBook(Book("William Shakespeare", "Hamlet", "Penguin Books", 2018, 5, 320));
    lib.AddBook(Book("J.K. Rowling", "Harry Potter", "Bloomsbury", 2018, 3, 150));
    lib.AddBook(Book("George Orwell", "Animal Farm", "Secker & Warburg", 2015, 4, 256));
    lib.Print();
    cout << "-------------" << endl;
    lib.PrintBookAnyAuthor("William Shakespeare");
    cout << "-------------" << endl;
    lib.PrintBookAnyYear(2018);


    //task2
    cout << "-------------" << endl;
    Worker workers[] = {
        Worker("John Smith", "Manager", 2015, 25000),
        Worker("Anna Brown", "Programmer", 2020, 30000),
        Worker("David Wilson", "Accountant", 2018, 22000),
        Worker("Mary Johnson", "Programmer", 2012, 35000),
        Worker("Peter Davis", "Manager", 2022, 18000)
    };
    int size = 5;
    Company company(workers,size);
    company.PrintAll();
    cout << "-------------" << endl;
    company.PrintWorkersByExperience(5);
    cout << "-------------" << endl;
    company.PrintWorkersBySalary(25000);
    cout << "-------------" << endl;
    company.PrintWorkersByPosition("Programmer");




    //int size = 4;
    //Array arr(size);
    //for (int i = 0; i < arr.getSize(); i++)
    //{
    //    arr.setValue(size - i,i);
    //}
    //PrintArray(arr);
    //cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    //PrintArray(8);//implicit int --> Array

    //Array a = 100;
    //PrintArray(a);











//implicit
    //int a = 3.14;
    //cout << a << endl;

    //double b(10);
    //cout << b << endl;
    //doSomething(5);//implicit int --> long

    //float pi = (float)3.14;//explicit

    //const int size = 5;
    //int month[3]{ 31,31,28 };
    ////month[0] = 45;

    

    //Date holidayDate{ 25,10,2026 };

    //holidayDate.Print();
    //holidayDate.Print();
    //holidayDate.day = 31;
    //holidayDate.Print();

    //const Date independencyDay{ 24,8,2027 };
    ////independencyDay.Print();
    ////independencyDay.day = 25;
    ////independencyDay.Print();

    //Account account1(2000, 5);
    //const Account account2(5000, 8);

    //cout << account1.getRate() << endl;
    //cout << account2.getRate() << endl;

    //cout << account1.getSum() << endl;
    //cout << account2.getSum() << endl;

    //cout << account1.getIncome() << endl;
    //cout << account2.getIncome() << endl;

    //cout << account1.setSum() << endl;
    //cout << account2.setSum() << endl;error


}

