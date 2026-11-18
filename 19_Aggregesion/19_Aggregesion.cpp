#include <iostream>
using namespace std;

enum Type { None,Standart, XL, XXL };

class Cartridge
{
	float volume;
	string color;
	Type type;
public:
	Cartridge():volume(0),color("no color"),type(None){}
	Cartridge(float v,string c,Type t):volume(v),color(c),type(t){}
	void ShowInfo()const
	{
		cout << "Volume: " << volume << endl;
		cout << "Color: " << color << endl;
		cout << "Type: ";
		switch (type)
		{
		case None:cout << "None";
			break;
		case Standart:cout << "Standart";
			break;
		case XL:
			break; cout << "XL";
		case XXL:
			break; cout << "XXL";
		default:
			break;
		}
		cout << endl;
	}

};

class Scanner
{
	float scanResolution;
	float height, width;
public:
	Scanner():scanResolution(0),height(0),width(0){}
	Scanner(float s, float h, float w):scanResolution(s),height(h),width(w){}
	void ShowInfo()const
	{
		cout << "Scan resolution: " << scanResolution << endl;
		cout << "Area: " << height << "x"<<width<<endl;
	}
};

class Document
{
	string name;
	string format;
	int pages;
public:
	Document() :name("no name"), format("no format"), pages(0) {}
	Document(string n, string f, int p) :name(n), format(f), pages(p) {}
	void ShowInfo()const
	{
		cout << "--------------- Document: " << name << endl;
		cout << "Format: " << format << endl;
		cout << "Pages: " << pages << endl;
	}

};

class Printer
{
	string model;
	Cartridge* cartridges;
	int count;
	Scanner scanner;
	Document *doc;
public:
	Printer():model("no model"),cartridges(nullptr),count(0),doc(nullptr){}
	Printer(string m,float s,float h,float w):model(m),scanner(s,h,w),doc(nullptr)
	{
		count = 4;
		cartridges = new Cartridge[count];
		cartridges[0] = Cartridge(300, "Red", Type::Standart);
		cartridges[1] = Cartridge(300, "Green", Type::Standart);
		cartridges[2] = Cartridge(300, "Blue", Type::Standart);
		cartridges[3] = Cartridge(300, "Black", Type::Standart);
	}
	void Scan()
	{
		cout << "Scanning........." << endl;
	}
	void printDocument()
	{
		if (doc != nullptr)
		{
			cout << "Print documents........" << endl;
			doc->ShowInfo();
		}
		else
		{
			cout << "No document" << endl;
		}
		
	}
	void PrintSettings()
	{
		for (int i = 0; i < count; i++)
		{
			cartridges[i].ShowInfo();
		}
		scanner.ShowInfo();
	}
	void AddDoc(Document* doc)
	{
		this->doc = doc;
	}
	~Printer()
	{
		if (cartridges != nullptr)
			delete[]cartridges;
	}
};



int main()
{
	Printer printer("Canon", 300, 40, 60);
	printer.printDocument();
	printer.Scan();
	printer.PrintSettings();

	Document doc("Password", "A5", 16);
	Document doc2("C++ for begginers", "A4", 127);

	printer.AddDoc(&doc);
	printer.printDocument();
	printer.AddDoc(&doc2);
	printer.printDocument();
}

