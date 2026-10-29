#pragma once
#include "book.h"

class Library
{
	string name;
	string address;
	Book* books;
	int countBooks;
public:
	Library();
	Library(string name,string address);
	Library(const Library& other);
	Library& operator =(const Library& other);
	Library(Library&& other);
	void ShowLibrary()const;
	~Library();
	void AddBook(Book b);
};

