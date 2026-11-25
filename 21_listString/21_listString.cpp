#include <iostream>
#include <string>
using namespace std;


int main()
{
	string name = "olena";
	string surname = "ilushin";

	cout << name << " " << surname << endl;
	surname += "++++++++++++++++";
	cout << name << " " << surname << endl;

	string one("hi world");
	cout << one << endl;

	string two(20, '&');
	cout << two << endl;

	string three(one);
	cout << three << endl;

	string five({ 'a','o','w' });
	cout << five << endl;
	five[0] = 'w';
	cout << five << endl;

	string six = one + five;
	cout << six << endl;

	char alls[] = "all irflgrwoihefihefwihoefiohefwhio";
	string seven(alls, 5);
	cout << seven << endl;

	string eight(alls + 6, alls + 10);
	cout << eight << endl;

	string nine(&alls[6], &alls[10]);
	cout << nine << endl;

	string ten(alls);
	cout << "size: " << ten.size() << endl;
	cout << "capacity: " << ten.capacity() << endl;
	for (int i = 0; i < ten.size(); i++)
	{
		cout << ten[i] << "  ";
	}
	cout << "=========================" << endl;
	for (auto s : ten) {
		cout << s << endl;
	}
	cout << "=========================" << endl;
	for (auto i = ten.begin(); i != ten.end(); i++)
	{
		cout << *i << endl;
	}

	int a = 5;
	int* ptr = &a;
	cout << *ptr << endl;

	const char c_str[] = "Hello";
	string str = "hello world";

	cout << "Size: " << str.size() << endl;
	cout << "Capacity: " << str.capacity() << endl;

	//str.clear();

	cout << "Size: " << str.size() << endl;
	cout << "Capacity: " << str.capacity() << endl;

	if (str.empty())
		cout << "Str is empty" << endl;

	cout << str << endl;

	str.append(" end. ");

	cout << str << endl;

	str.append(c_str, 3);

	cout << str << endl;

	str.append({ 'g','k','k','l' });

	cout << str << endl;

	str.append(str.begin() + 5, str.end() - 4);

	cout << str << endl;

	str.insert(str.begin(), 'H');
	cout << str << endl;

	str.insert(0, 5, 'A');
	cout << str << endl;

	str.insert(str.end(), { 'a','b','c' });
	cout << str << endl;
	
	str.erase(0, 15);
	cout << str << endl;

	str.erase(8);
	cout << str << endl;

	str.erase();
	cout << str << endl;

	str.replace(0, 5, "Yes");
	cout << str << endl;

	cout << "Index first 'o': " << str.find('q') << endl;

	if (str.find('q') == string::npos)
		cout << "Element not found" << endl;

	cout << "Index first 'o': " << str.rfind('o') << endl;
	cout << "Index first 'o': " << str.find_first_of('o') << endl;
	cout << "Index first 'o': " << str.find_first_not_of('o') << endl;
	cout << "Index first 'o': " << str.find_last_of('o') << endl;
	cout << "Index first 'o': " << str.find_last_not_of('o') << endl;

	cout << "Substring: " << str.substr(5, 15);
}