#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    class student
    {
    private:
        string name;
        int day;
        int month;
        int year;
        string phone_number;
        string university_name; 
        string university_city; 
        string university_country; 
        string city;
        string country;
        string number_of_group;
    public:
        void InitStudent()
        {
            cout << "Enter name(PIB): ";getline(cin, name);
            cout << "Enter your date of birth: ";cin >> day;
            cout << "Enter your birth month: ";cin >> month;
            cout << "Enter your birth year: ";cin >> year;
            cout << "Enter your phone number: ";cin >> phone_number;
            cin.ignore();
            cout << "Enter university name: ";getline(cin, university_name);
            cout << "Enter university city: ";getline(cin, university_city);
            cout << "Enter university country: ";getline(cin, university_country);
            cout << "Enter your city: ";getline(cin, city);
            cout << "Enter your country: ";getline(cin, city);
            cout << "Enter your number of group: ";cin >> number_of_group;
        }
        void ShowStudent()
        {
            cout << "Full name: " << name<<endl;
            cout << "Date of birth: " << day<<endl;
            cout << "Your birth month: " << month<<endl;
            cout << "Your birth year: " << year<<endl;
            cout << "Phone number: " << phone_number<<endl;
            cout << "University: " << university_name << endl;
            cout << "University city: " << university_city << endl;
            cout << "University country: " << university_country << endl;
            cout << "City: " << city<<endl;
            cout << "Country: " << country<<endl;
            cout << "Number of group: " << number_of_group<<endl;
        }
        void SetName(string name)
        {
            this->name = name;
        }
        void SetDay(int day)
        {
            this->day = day;
        }
        void SetMonth(int month)
        {
            this->month = month;
        }
        void SetYear(int year)
        {
            this->year = year;
        }
        void SetPhoneNumber(string phone_number)
        {
            this->phone_number = phone_number;
        }
        void SetUniversityName(string university_name)
        {
            this->university_name = university_name;
        }
        void SetUniversityCity(string university_city)
        {
            this->university_city = university_city;
        }
        void SetUniversityCountry(string university_country)
        {
            this->university_country = university_country;
        }
        void SetCity(string city)
        {
            this->city = city;
        }
        void SetCountry(string country)
        {
            this->country = country;
        }
        void SetNumberOfGroup(string number_of_group)
        {
            this->number_of_group = number_of_group;
        }
        string GetName()
        {            
            return name;
        }
        int GetDay()
        {            
            return day;
        }
        int GetMonth()
        {            
            return month;
        }
        int GetYear()
        {            
            return year;
        }
        string GetPhoneNumber()
        {            
            return phone_number;
        }
        string GetUniversityName()
        {
            return university_name;
        }
        string GetUniversityCity()
        {
            return university_city;
        }
        string GetUniversityCountry()
        {
            return university_country;
        }
        string GetCity()
        {            
            return city;
        }
        string GetCountry()
        {            
            return country;
        }
        string GetNumberOfGroup()
        {            
            return number_of_group;
        }
        void SaveFromFile()
        {
            ofstream out;
            out.open("Student.txt");
            out <<name << endl;
            out << day << " "<<month <<" " <<year << ""<<endl;
            out <<phone_number << endl;
            out << university_name << endl;
            out << university_city << endl;
            out << university_country << endl;
            out << city << endl;
            out <<country << endl;
            out <<number_of_group << endl;
            out.close();
        }
        void ReadFromFile()
        {
            ifstream in;
            in.open("Student.txt");
            if (!in.is_open())
            {
                cout << "Not found" << endl;
                return;
            }
                

            getline(in, name);
            in >> day >> month >> year; 
            in >> phone_number;
            in.ignore();
            getline(in, university_name);
            getline(in, university_city);
            getline(in, university_country);
            getline(in, city);
            getline(in, country);
            getline(in, number_of_group);
            in.close();
        }

    };
    student student;
    student.InitStudent();
    student.ShowStudent();
    student.SaveFromFile();
    student.ReadFromFile();
    student.ShowStudent();
}

