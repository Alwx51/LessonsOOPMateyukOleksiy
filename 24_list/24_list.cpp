#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

void ShowList(list<int>& l1, list<int>& l2)
{
	list<int>::iterator it;     
	cout << "List 1: ";
	for (it = l1.begin(); it != l1.end();it++)
	{
		cout << *it << " ";
	}
	cout << "List 2: "; 
	for (it = l2.begin(); it != l2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

struct Book
{
	string name;
	string author;
	int pages;
};

bool CompareBookByName(const Book& b1, const Book& b2)
{
	return b1.name < b2.name;
}
bool CompareBookByAuthor(const Book& b1, const Book& b2)
{
	return b1.author < b2.author;
}
bool CompareBookByPages(const Book& b1, const Book& b2)
{
	return b1.pages < b2.pages;
}

int main()
{
	list<Book> library;
	library.assign({
		Book{"Kobzar","Shevchenko",1000},
		Book{"Maria","Kotliarevskiy",333},
		Book{"Adventures of Tom Soer","Mark  Twain",555}

		});
	cout << "-------------- Original list: -----------------" << endl;
	for (Book b:library)
	{
		cout << left<<setw(25)<<b.name << setw(18) << b.author << setw(10) << b.pages << endl;
	}
	library.sort(CompareBookByName);
	cout << "-------------- Sort list by name: -----------------" << endl;
	
	for (Book b:library)
	{
		cout << left<<setw(25)<<b.name << setw(18) << b.author << setw(10) << b.pages << endl;
	}
	library.sort(CompareBookByAuthor);
	cout << "-------------- Sort list by author: -----------------" << endl;
	
	for (Book b:library)
	{
		cout << left<<setw(25)<<b.name << setw(18) << b.author << setw(10) << b.pages << endl;
	}
	library.sort(CompareBookByPages);
	cout << "-------------- Sort list by pages: -----------------" << endl;
	
	for (Book b:library)
	{
		cout << left<<setw(25)<<b.name << setw(18) << b.author << setw(10) << b.pages << endl;
	}
	list<int> l1, l2;
	cout << "Size: " << l1.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		l1.push_back(i);
		l2.push_front(i);
	}

	ShowList(l1, l2);
	l1.assign({ 11,22,33,44 });
	ShowList(l1, l2);


	l1.erase(l1.begin());
	ShowList(l1, l2);

	list<int>::iterator it = l1.begin();
	it++;
	it++;

	l1.erase(it);
	ShowList(l1, l2);


	l1.push_back(100);
	l1.push_front(100);
	ShowList(l1, l2);
	l1.insert(l1.begin(), 99);
	l1.insert(l1.begin(), {88,55,66,33});
	l1.insert(l1.end(), l2.begin(), l2.end());
	l1.insert(l1.begin(), 5,77);
	ShowList(l1, l2);

	l1.remove(77);
	ShowList(l1, l2);

	l1.resize(100);
	ShowList(l1, l2);

	l1.splice(l1.end(), l2, l2.begin());
	ShowList(l1, l2);

	l1.sort();
	l2.sort();

	l1.merge(l2);
	ShowList(l1, l2);
	l1.unique();
	ShowList(l1, l2);

	l1.swap(l2);
	ShowList(l1, l2);
}
