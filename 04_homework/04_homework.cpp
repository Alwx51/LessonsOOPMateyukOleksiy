#include <iostream>
using namespace std;

struct Abonent
{
    string contact_info;
};

class PhoneBook
{
    string name;
    string home_phone_number;
    string phone_number;
    string mobile_phone_number;
    Abonent contact_info;
public:
    static int count_phones;
    Abonent abonent;
    PhoneBook() :name("no name"), home_phone_number("no home number"),
        phone_number("no phone number"), mobile_phone_number("no mobile number"),
        contact_info{ "no info" } {
        count_phones++;
    }

    PhoneBook(string name):PhoneBook()
    {
        this->name = name;
    }
    PhoneBook(string name, string home_phone_number):PhoneBook(name)
    {
        this->home_phone_number = home_phone_number;
    }
    PhoneBook(string name, string home_phone_number, string mobile_phone_number):PhoneBook(name,home_phone_number)
    {
        this->mobile_phone_number = mobile_phone_number;
    }
    PhoneBook(string name, string home_phone_number, string mobile_phone_number, Abonent contact_info) :PhoneBook(name, home_phone_number, mobile_phone_number)
    {
        this->contact_info = contact_info;
    }

    void Print()
    {
        

        cout << "Name: " << name << endl;
        cout << "Home number: " << home_phone_number << endl;
        cout << "Phone number: " << phone_number << endl;
        cout << "Mobile number: " << mobile_phone_number << endl;
        cout << "Contact info: " << contact_info.contact_info << endl;
    }

};

int PhoneBook::count_phones = 0;

int main()
{
    PhoneBook phone1;
    phone1.Print();
    cout << "Count phones: " << PhoneBook::count_phones << endl;
    PhoneBook phone2("Oleksiy Mateyuk Andriyovich","+38034532653");
    phone2.Print();
    cout << "Count phones: " << PhoneBook::count_phones << endl;
    PhoneBook phone3("Oleksiy Mateyuk Andriyovich","+38034532653","+38047284925");
    phone3.Print();
    PhoneBook phone4("Oleksiy Mateyuk Andriyovich", "+38034532653", "+38047284925", Abonent{ "+38095324567" });
    phone4.Print();
    cout << "Count phones: " << PhoneBook::count_phones << endl;


}


