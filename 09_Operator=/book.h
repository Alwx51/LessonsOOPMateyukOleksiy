#pragma once
#include <iostream>
using namespace std;



enum Genre{ None, Fantasy,Roman,History,Drama, Sci_Fi,Horror, Comedy,Poltitcal,Programming };
class book
{
private:
	string title;
	int year;
	string author;
	int pages;
	Genre genre = Comedy;
public:
	book();
	book(string t, int y, string a, int p, Genre g) :title(t), year(y), author(a),
		pages(0), genre(g) { }
	void ShowInfo()const;

};

