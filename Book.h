#pragma once
#include <ostream>
#include <string>
class Book {
	std::string author, title;
public:
	Book();
	Book(const std::string& author, const std::string& title);
	Book(std::string&& author, std::string&& title);
	Book(const Book& other);
	Book(Book&& other);
	Book& operator=(const Book& other);
	Book& operator=(Book&& other);
	const std::string& GetAuthor() const;
	const std::string& GetTitle() const;
	void SetAuthor(const std::string& author);
	void SetTitle(const std::string& title);
	void SetAuthor(std::string&& author);
	void SetTitle(std::string&& title);
};
std::ostream& operator<<(std::ostream& out, const Book& book);