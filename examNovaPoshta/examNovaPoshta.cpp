#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
using namespace std;

class Service
{
protected:
    string type;
    int price;
    string description;
    double weight;
public:
    Service():type("no name"),price(0),description("no description"),weight(0){}
    Service(string n, string d, double w) :type(n), description(d), price(0)
    {
        weight = (w > 0) ? w : 0;
    }
    void SetWeight(double w)
    {
        weight = (w > 0) ? w : 0;
    }
    string GetName()const
    {
        return type;
    }
    virtual void PrintInfo()const = 0;
    virtual double CalculatePrice() = 0;
    virtual ~Service() = 0 {};

};

class StandardDelivery:public Service
{
public:
    StandardDelivery():Service()
    {
        price = 50;
    }
    StandardDelivery(string n, string d, double w):Service(n,d,w)
    {
        price = 50;
    }
    void PrintInfo()const override
    {
        cout << "-------------Standard Delivery-------------" << endl;
        cout << "Type: " << type << endl;
        cout << "Price: " << price << " UAH" << endl;
        cout << "Description: " << description << endl;
        cout << "Weight: " << weight << endl;
        cout << endl;
    }
    double CalculatePrice()override
    {
        return price + weight * 10;
    }
};

class ExpressDelivery:public Service
{
    int deliveryHours;
public:
    ExpressDelivery():Service(),deliveryHours(24)
    {
        price = 80;
    }
    ExpressDelivery(string n, string d, double w,int h):Service(n,d,w)
    {
        if (h > 0 && h <= 24)
            deliveryHours = h;
        else
            deliveryHours = 1;
        price = 80;
    }
    void PrintInfo()const override
    {
        cout << "-------------Express Delivery-------------" << endl;
        cout << "Type: " << type << endl;
        cout << "Price: " << price << " UAH" << endl;
        cout << "Description: " << description << endl;
        cout << "Weight: " << weight << endl;
        cout << "Delivery hours: " << deliveryHours << endl;
        cout << endl;
    }
    double CalculatePrice()override
    {
        if(deliveryHours>=20)
            return price + weight * 15;
        else
            return (price + weight * 15) * 1.5;
    }
};

class FragileDelivery:public Service
{
    int packagingFee;
public:
    FragileDelivery():Service(),packagingFee(0)
    {
        price = 100;
    }
    FragileDelivery(string n, string d, double w,int pF):Service(n,d,w)
    {
        if (pF > 0 && pF <= 200)
            packagingFee = pF;
        else
            packagingFee = 0;
        price = 100;
    }
    void PrintInfo()const override
    {
        cout << "-------------Fragile Delivery-------------" << endl;
        cout << "Type: " << type << endl;
        cout << "Price: " << price << " UAH" << endl;
        cout << "Description: " << description << endl;
        cout << "Weight: " << weight << endl;
        cout << "Packaging fee: " << packagingFee << " UAH"<<endl;
        cout << endl;
    }
    double CalculatePrice()override
    {
        return price + weight * 12 + packagingFee;
    }
};

class Order
{
    string trackingNumber;
    string senderName;
    string receiverName;
    string description;
    double weight;
    Service* service;
    bool isPaid;
    bool isDelivered;
public:
    Order() :trackingNumber("no number"), senderName("no sender name"),
        receiverName("no receiver name"), description("no desc"),
        weight(0), service(nullptr), isPaid(false), isDelivered(false){ }
    Order(string t,string s,string r,string d,double w,bool isP,bool isD) :trackingNumber(t),
        senderName(s),receiverName(r), description(d),weight(0), service(nullptr), isPaid(isP),
        isDelivered(isD)
    {
        weight = (w > 0) ? w : 0;
    }
    void AddService(Service* service)
    {
        this->service = service;
        if (this->service != nullptr) {
            this->service->SetWeight(this->weight);
        }
    }
    void PrintReceipt()
    {
        cout << "-----------Receipt-----------" << endl;
        cout << char(218) << "--------------------------" << char(191) << endl;

        cout << "| " << left << setw(25) << ("Receipt: " + trackingNumber) << "|" << endl;
        cout << "| " << left << setw(25) << ("Sender: " + senderName) << "|" << endl;
        cout << "| " << left << setw(25) << ("Receiver: " + receiverName) << "|" << endl;
        cout << "| " << left << setw(25) << ("Item: " + description) << "|" << endl;
        cout << "| Weight: " << left << setw(17) << weight << "|" << endl;

        if (service != nullptr)
        {
            cout << "| Service: " << left << setw(16) << service->GetName() << "|" << endl;
            cout << "| To pay: " << setw(12) << (service->CalculatePrice()) << " UAH |" << endl;
        }

        cout << char(192) << "--------------------------" << char(217) << endl;
    }
};

class PostOffice
{
    list<Service*> services;
};

int main()
{
    Service* standard = new StandardDelivery("Default", "Delivery within 3-5 days", 0);
    Order order1("TTN-1001", "Oleksiy", "Maksym", "Gaming Mouse", 1.5, true, false);
    order1.AddService(standard);
    order1.PrintReceipt();
}

