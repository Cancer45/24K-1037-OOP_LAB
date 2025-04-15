#ifndef BOOK_H
#define BOOK_H

#include <iostream>

class Book
{
    public:
    std::string title, author, ISBN;
    Book (std::string title = "default", std::string author = "default", std::string ISBN = "0001");

    std::string getTitle ();
    std::string getAuthor ();
    std::string getISBN ();
};

#endif