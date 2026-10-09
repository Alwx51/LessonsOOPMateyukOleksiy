#include <iostream>
#include <fstream>
using namespace std;

//struct Player
//{
//    string name;
//    short age;
//    int games;
//    int goals;
//};
//
//void PrintPlayer(Player &pl)
//{
//    cout << "Name: " << pl.name << endl;
//    cout << "Age: " << pl.age << endl;
//    cout << "Games: " << pl.games << endl;
//    cout << "Goals: " << pl.goals << endl;
//}
//
//void InitPlayer(Player& pl)
//{
//    cout << "Enter name: "; cin >> pl.name;
//    cout << "Enter age: "; cin >> pl.age;
//    pl.games = 0;
//    pl.goals = 0;
//}
//void AddGameToPlayer(Player& pl, int goals = 0)
//{
//    pl.games++;
//    pl.goals += goals;
//}

class Player
{
private:
    string name;
    short age;
    int games;
    int goals;

public:

void PrintPlayer()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Games: " << games << endl;
    cout << "Goals: " << goals << endl;
}

void InitPlayer()
{
    cout << "Enter name: "; cin >> name;
    cout << "Enter age: "; cin >> age;
    games = 0;
    goals = 0;
}
void AddGameToPlayer(int goals = 0)
{
    games++;
    
    this->goals += goals;
}
};

class Student
{
private:
    string name;
    int marks[3];
public:
    //setter
    //getter
    void setName(string name)
    {
        this->name = name;
    }
    void SetMark(int index, int mark)
    {
        if (mark >=1 and mark <= 12)
        {
            marks[index] = mark;
        }
        else
        {
            marks[index] = 0;
        }
    }

    string getName()
    {
        return name;
    }
    int getMark(int index)
    {
        return marks[index];
    }
    double getAverage()
    {
        double summa = 0;
        for (int i = 0; i < 3; i++)
        {
            summa += marks[i];
        }
        return (double)summa / 3;
    }
};

class Dot
{
private:
    int x;
    int y;
    int z;
public:
    void InitDot()
    { 
        cout << "Enter x: "; cin >> x;
        cout << "Enter y: "; cin >> y;
        cout << "Enter z: "; cin >> z;
    }
    void PrintDot()
    {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
        cout << "Z: " << z << endl;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    int GetZ()
    {
        return z;
    }
    void SetX(int x)
    {
        this->x = x;
    }
    void SetY(int y)
    {
        this->y = y;
    }
    void SetZ(int z)
    {
        this->z = z;
    }

    void SaveToFile()
    {
        ofstream out;
        out.open("dot.txt");
        out << x<<endl;
        out << y<<endl;
        out << z<<endl;
        out.close();
    }
    void ReadFromFile()
    {
        ifstream in;
        in.open("dot.txt");
        in >> x;
        in >> y;
        in >> z;
        in.close();
    }
};

int main()
{
   /* Dot dot;
    dot.InitDot();
    dot.PrintDot();
    dot.SetX(100);
    dot.SetY(100);
    dot.SetZ(100);
    cout << dot.GetX() << " " << dot.GetY() << " " << dot.GetZ() << endl;
    dot.SaveToFile();*/
    Dot dot;
    dot.ReadFromFile();
    dot.PrintDot();
















    //Student st;
    //st.setName("Ivan");
    //st.SetMark(0,10);
    //st.SetMark(1,8);
    //st.SetMark(5,9);


    //cout << "Name: " << st.getName() << " Marks: " << st.getMark(0) << " "
    //    << st.getMark(1) << " " << st.getMark(2) << endl;
    //cout << "Average mark: " << st.getAverage() << endl;

    /*Player player;
    player.InitPlayer();
    player.PrintPlayer();
    player.AddGameToPlayer(3);
    player.PrintPlayer(); */













}
