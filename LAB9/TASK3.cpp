#include "Book.h"
#include <iostream>

class Library
{
    Book* all_books = nullptr;
    int num_books;

    public:
    Library (Book* all_books, int num_books) : num_books(num_books)
    {
        this -> all_books = new Book [num_books];

        for (int i = 0; i < num_books; i++)
            this -> all_books[i] = all_books[i];
    }

    ~Library ()
    {
        delete [] all_books;
    }

    void displayAll()
    {
        for (int i = 0; i < num_books; i++)
        {
            std::cout << "\nTitle: " + all_books[i].getTitle() + "\nAuthor: " + all_books[i].getAuthor() + "\nISBN: " + all_books[i].getISBN() <<std::endl; 
        }
    }

    void addBook (Book to_add)
    {
        Book* tmp_array = new Book [num_books + 1];

        for (int i = 0; i < num_books; i++)
            tmp_array[i] = all_books[i];

        tmp_array[num_books] = to_add;

        delete [] all_books;
        all_books = tmp_array;

        num_books++;
        std::cout << to_add.getTitle() + " ADDED\n";
    }

    void removeBook (std::string identifier /*use search function*/) 
    {
        Book to_remove = *searchBook(identifier);
        if (searchBook(identifier) != NULL)
        {
            Book* tmp_array = new Book [num_books - 1];

        for (int i = 0; i < num_books; i++)
        {
            if (all_books[i].ISBN == to_remove.getISBN())
            {
                
            }


        }

        delete [] all_books;
        all_books = tmp_array;

        num_books--;
        std::cout << to_remove.getTitle() + " REMOVED\n";
        }

        std::cout << "CAN'T REMOVE; NO SUCH BOOK\n";
    }
    Book* searchBook (std::string identifier /*could be title, author, or ISBN*/)
    {
        for (int i = 0; i < num_books; i++)
        {
            if (all_books[i].title == identifier)
                return &all_books[i];

            if (all_books[i].title == identifier)
                return &all_books[i];

            if (all_books[i].title == identifier)
                return &all_books[i];
        }

        std::cout << "NO SUCH BOOK\n";
        return NULL;
    }
};

int main ()
{
    Book* tmp_book = new Book("Nicholas Nickelby", "Charles Dickens", "1397100302108");
    std::cout << "\nTitle: " + tmp_book->getTitle() + "\nAuthor: " + tmp_book->getAuthor() + "\nISBN: " + tmp_book->getISBN() <<std::endl;

    Book* all_books = new Book [7];
    all_books[0] = Book("The Count of Monte Cristo", "Alexandre Dumas", "1047209568392");
    all_books[1] = Book("1984", "George Orwell", "9780451524935");
    all_books[2] = Book("To Kill a Mockingbird", "Harper Lee", "9780061120084");
    all_books[3] = Book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    all_books[4] = Book("Moby Dick", "Herman Melville", "9781503280786");
    all_books[5] = Book("Pride and Prejudice", "Jane Austen", "9781503290563");
    all_books[6] = Book("War and Peace", "Leo Tolstoy", "9780199232765");

    Library library(all_books, 7);
    library.displayAll();
    library.addBook(*tmp_book);
    library.removeBook("The Count of Monte Cristo");

    Book* searched_book = library.searchBook("The Great Gatsby");
    if (searched_book != NULL)
    std::cout << "\nBOOK FOUND";
}
