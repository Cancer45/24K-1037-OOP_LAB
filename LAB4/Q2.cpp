#include <iostream>

class Book
{
    public:
    int ID; 
    bool availability;
    std::string title, author;

    //constructor 1
    Book (int ID, std::string title, std::string author, bool availability)
    {
        this -> ID = ID;
        this -> availability = availability;
        this -> title = title;
        this -> author = author;
    }

    Book (int ID, std::string title, std::string author)
    {
        this -> ID = ID;
        this -> title = title;
        this -> author = author;
    }

    Book () {}
};

class Library
{
    int numBooks = 0;
    Book* allBooks = nullptr;

    public:
    void addBook (std::string title, std::string author)
    {
        Book newBook (numBooks, title, author, true);

        Book* tmpArray = new Book [numBooks + 1];

        for (int i = 0; i < numBooks; i++)
        tmpArray[i] = allBooks[i];
    
        tmpArray[numBooks] = newBook;
        std::cout << tmpArray[numBooks].title << " with ID " << tmpArray[numBooks].ID << " added." << std::endl;
        numBooks++;

        delete [] allBooks;
        allBooks = tmpArray; 
    }

    void borrowBook (int bookID)
    {
        for (int i = 0; i < numBooks; i++)
        {
            if (allBooks[i].ID == bookID)
            {
                {
                    if (allBooks[i].availability)
                    {
                        allBooks[i].availability = false;
                        std::cout << allBooks[i].title << " with ID " << allBooks[i].ID << " borrowed." << std::endl;
                        return;
                    }

                    else
                    {
                        std::cout << allBooks[i].title << " with ID " << allBooks[i].ID << " not available." << std::endl;
                        return;
                    }
                }
            }
        }

        std::cout << "No such book." << std::endl;
    }

    void returnBook (int bookID)
    {
        for (int i = 0; i < numBooks; i++)
        {
            if (allBooks[i].ID == bookID)
            {
                {
                    if (!allBooks[i].availability)
                    {
                        allBooks[i].availability = true;
                        std::cout << allBooks[i].title << " with ID " << allBooks[i].ID << " returned." << std::endl;
                        return;
                    }

                    else
                    {
                        std::cout << allBooks[i].title << " with ID " << allBooks[i].ID << " not borrowed by anyone." << std::endl;
                        return;
                    }
                }
            }
        }

        std::cout << "No such book." << std::endl;
    }

    void displayAll ()
    {
        std::string tmp;

        for (int i = 0; i < numBooks; i++)
        {
            std::cout << std::endl << "BOOK " << i + 1 << std::endl;
            std::cout << "Title: " << allBooks[i].title << std::endl;
            std::cout << "Author: " << allBooks[i].author << std::endl;
            std::cout << "ID: " << allBooks[i].ID << std::endl;
            
            if (allBooks[i].availability)
            tmp = "Yes";        

            else
            tmp = "No";

            std::cout << "Availability: " << tmp << std::endl;

            std::cout << std::endl;
        }
    }
};

int main ()
{
    Library library;

    library.addBook("Nicholas Nickelby", "Charles Dickens");
    library.borrowBook (0);
    library.displayAll ();
    library.returnBook (0);
    library.displayAll ();
    library.addBook("The Count of Monte Cristo", "Alexandre Dumas");

    library.borrowBook (1);
    library.displayAll ();
    library.returnBook (1);
    library.displayAll ();
}

