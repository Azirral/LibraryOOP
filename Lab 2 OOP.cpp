#include <ostream>
#include <string>
#include <iostream>
#include "Book.h"
#include "Library.h"
int main()
{
	//Task 1
	std::string a = "Andrzej Sapkowski", t = "Narrenturm";
	Book e;
	std::cout << "e: " << e << std::endl;
	Book b1 = { a, t };
	std::cout << "b1: " << b1 << std::endl;
	Book b2 = { "Jaroslaw Grzedowicz","Pan Lodowego Ogrodu" };
	std::cout << "b2: " << b2 << std::endl;
	Book b3 = b1;
	std::cout << "b3: " << b3 << " b1: " << b1 << std::endl;
	e = std::move(b2);
	std::cout << "e: " << e << " b2:" << b2 << std::endl;
	e.SetAuthor("Jacek Piekara");
	std::cout << "e: " << e << std::endl;
	e.SetTitle("Popiol i Korz");
	std::cout << "e: " << e << std::endl;

	//Task 2
	Library l;
	std::cout << "l: " << l << std::endl;
	//3-5 books
	Library l1 = { {"Jakub Cwiek", "Klamca"},
				   {"Jaroslaw Grzedowicz", "Wypychacz Zwierzat"},
				   {"Marina i Siergiej Diaczenko", "Miedziany Krol"} };
	std::cout << "l1: " << l1 << std::endl;
	Library l2(2);
	std::cout << "l2: " << l2 << std::endl;
	l2[0] = { "J.R.R. Tolkien", "Wladca Pierscieni" };
	l2[1] = { "J.K. Rowling", "Harry Potter" };
	std::cout << "l2: " << l2 << std::endl;
	l = std::move(l2);
	std::cout << "l: " << l << " l2: " << l2 << std::endl;
	l1[0] = std::move(l[1]);
	std::cout << "l1: " << l1 << " l: " << l << std::endl;

	system("pause");
	return 0;
}