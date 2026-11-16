//#include <iostream>
//using namespace std;
//
//class Person
//{
//    string name;
//    string spetialization;
//    int age;
//    int* marks;
//    int countMark;
//public:
//    Person():name("no name"),spetialization("none"),age(0), marks(nullptr), countMark(0) {}
//    Person(string name,string s,int age):name(name),age(age),spetialization(s)
//    {
//        countMark = rand() % 15 + 1;
//        marks = new int[countMark];
//        for (int i = 0; i < countMark; i++)
//        {
//            marks[i] = rand() % 12 + 1;
//        }
//    }
//    virtual void print()const
//    {
//        cout << "Name: " << name << endl;
//        cout << "Spetialization: " << spetialization << endl;
//        cout << "Age: " << age << endl;
//        cout << "Marks: ";
//        for (int i = 0; i < countMark; i++)
//        {
//            cout << marks[i] << " ";
//        }
//        cout << endl;
//    }
//    virtual ~Person()
//    {
//        if (marks != nullptr)
//            delete[]marks;
//    }
//};
//
//class Aspirant :public Person
//{
//    string* subject;
//    int countSubjects;
//public:
//    Aspirant():subject(nullptr),countSubjects(0),Person(){}
//    Aspirant(string n,string s,int a,initializer_list<string> list):Person(n,s,a)
//    {
//        this->countSubjects = list.size();
//        subject = new string[countSubjects];
//        int i = 0;
//        for (string sub:list)
//        {
//            subject[i] = sub;
//            i++;
//        }
//    }
//
//    void Print()const
//    {
//        Person::print();
//        cout << "Subjects: ";
//        for (int i = 0; i < countSubjects; i++)
//        {
//            cout << subject[i] << " | ";
//        }
//        
//    }
//    ~Aspirant()
//    {
//        if (subject!=nullptr)
//        {
//            delete[]subject;
//        }
//    }
//};
//
//int main()
//{
//    srand(time(0));
//    Person student("Vasia","Programmer", 18);
//    student.print();
//
//    Aspirant aspirant("Ivan", "History", 20, { "Ukraine revolution","UNR","World war" });
//    aspirant.print();
//
//    Person* group[3]
//    {
//        new Person("Vasia","Programmer", 18),
//        new Aspirant("Ivan", "History", 20, { "Ukraine revolution","UNR","World war" }),
//        new Aspirant("Jesse", "Chemistry", 22, { "Sinya zabava","Gasoline","Oil" })
//
//    };
//    for (int i = 0; i < 3; i++)
//    {
//        group[i]->print();
//        delete group[i];
//    }
//}
