#pragma once
#include <initializer_list>
#include<iostream>
#include <string>
#include "Library.h"
Library::Library()
{
	books = nullptr;
	size = 0;
}
Library::Library(std::size_t size)
	: size{size}, books{new Book[size]}
{
	std::cout << "Library(" << size << ")" << std::endl;
}
Library::Library(std::initializer_list<Book> list)
	: size{ list.size() }, books{ new Book[list.size()] }
{
	std::size_t i = 0;
	for (Book book : list)
	{
		books[i] = book;
		i++;
	}
}
Library::Library(const Library& orig)
	: size(orig.size), books{ new Book[orig.size] } {
	for (std::size_t i = 0; i < size; i++)
	{
		books[i] = orig.books[i];
	}
}
Library::Library(Library&& orig) {
	std::cout << "Library(Library&&)" << std::endl;
	books = orig.books;
	size = orig.size;
	orig.books = nullptr;
	orig.size = 0;
}
Library& Library::operator=(const Library& right) {
	Library tmp = right;
	std::swap(books, tmp.books);
	std::swap(size, tmp.size);
	return *this;
}
Library& Library::operator=(Library&& right) {
	std::cout << "operator=(Library&&)" << std::endl;
	std::swap(books, right.books);
	std::swap(size, right.size);
	return *this;
}
Book& Library::operator[] (std::size_t index)
{
	return books[index];
}
const Book& Library::operator[](std::size_t index) const {
	return books[index];
}
std::size_t Library::GetSize() const
{
	return size;
}
std::ostream& operator<<(std::ostream& ostr, const Library& book) {
	ostr << "Library{";
	for (std::size_t i = 0; i < book.GetSize(); i++)
	{
		if (i > 0)
		{
			ostr << ',';
		}
		ostr << book[i];
	}
	ostr << '}';
	return ostr;
}
Library::~Library(){
	if (books != nullptr)
 {
 std::cout << "Releasing memory " << books << std::endl;
 delete[] books;
 }
}
