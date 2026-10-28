#include "book.h"

book::book()
{
	title = "no title";
	year = 0;
	author = "no author";
	pages = 0;
	genre = None;
}

void book::ShowInfo() const
{
	cout << "Title: " << title << endl;
	cout << "Year: " << year << endl;
	cout << "Author: " << author << endl;
	cout << "Pages: " << pages << endl;
	cout << "Genre: " << genre << endl;
}
