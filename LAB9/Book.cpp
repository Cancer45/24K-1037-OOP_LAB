#include "Book.h"
#include <iostream>

    Book::Book (std::string title, std::string author, std::string ISBN) : title(title), author(author), ISBN(ISBN) {}
   
    std::string Book::getTitle ()
    {
        return title;
    }

    std::string Book::getAuthor ()
    {
        return author;
    }

    std::string Book::getISBN ()
    {
        return ISBN;
    }
