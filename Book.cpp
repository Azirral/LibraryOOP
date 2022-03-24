#pragma once
#include <ostream>
#include <string>
#include "Book.h"
Book::Book() //default constructor (without parameters)
{
}
Book::Book(const std::string& author, const std::string& title) //l-reference
{
	this->author = author;
	this->title = title;
}
Book::Book(std::string&& author, std::string&& title) //r-reference 
{
	this->author = std::move(author);
	this->title = std::move(title);
}
Book::Book(const Book& other) //copy constructor
{
	author = other.author;
	title = other.title;
}
Book::Book(Book&& other)  //move constructor
{
	author = std::move(other.author);
	title = std::move(other.title);
}
Book& Book::operator=(const Book& other) //copy assignment operator
{
	author = other.author;
	title = other.title;
	return *this;
}
Book& Book::operator=(Book&& other)  //move assignment operator
{
	author = std::move(other.author);
	title = std::move(other.title);
	return *this;
}
const std::string& Book::GetAuthor() const
{
	return author;
}
const std::string& Book::GetTitle() const
{
	return title;
}
void Book::SetAuthor(const std::string& author) //author setter with constant l-refrence
{
	this->author = author;
}
void Book::SetTitle(const std::string& title) //title setter with constant l-refrence
{
	this->title = title;
}
void Book::SetAuthor(std::string&& author)  //author setter with r-refrence
{
	this->author = std::move(author);
}
void Book::SetTitle(std::string&& title)  //title setter with r-refrence
{
	this->title = std::move(title);
}
std::ostream& operator<<(std::ostream& out, const Book& book) // ostream print operator <<
{
	if (!book.GetAuthor().empty() && !book.GetTitle().empty())
	{
		return out << book.GetAuthor() << " - " << book.GetTitle();
	}
	return out << "Empty book" << std::endl;
}