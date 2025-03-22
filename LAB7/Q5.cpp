#include <iostream>

class Date
{
	public:
	int day, month, year;

	bool operator== (Date &other)
	{
		if (day == other.day && month == other.month && year == other.year)
			return true;

		return false;
	}
};

class Media
{
	protected:
	std::string title, unique_ID, publisher;
	Date publication_date;
	bool available;
	public:
	Media () {}
	Media (std::string title, std::string unique_ID, std::string publisher, Date publication_date) : title(title), unique_ID(unique_ID), publisher(publisher), publication_date(publication_date), available(true) {}

	virtual void displayInfo ()
	{
		std::cout << "Title: " << title << "\nID: " << unique_ID << "\nPublisher: " << publisher << "Publication Date: " << publication_date.day << "." << publication_date.month << "." << publication_date.year << std::endl;
	}

	bool checkOut ()
	{
		if (available)
		{
			available = false;
			return true;
		}

		return false;
	}

	bool returnItem ()
	{
		if (!available)
		{
			available = true;
			return true;
		}

		return false;
	}

	//search by title
	void search (std::string title, Media** all_media, int num_media) const
	{
		for (int i = 0; i < num_media; i++)
		{
			if (all_media[i] -> title == title)
				std::cout << all_media[i] -> unique_ID << std::endl;
		}
	}

	//search by publication_date
	void search (Date publication_date, Media** all_media, int num_media) const
	{
		for (int i = 0; i < num_media; i++)
		{
			if (all_media[i] -> publication_date == publication_date)
				std::cout << all_media[i] -> unique_ID << std::endl;
		}
	}

	//search by availability
	void search (bool availability, Media** all_media, int num_media) const
	{
		for (int i = 0; i < num_media; i++)
		{
			if (all_media[i] -> available == availability)
				std::cout << all_media[i] -> unique_ID << std::endl;
		}
	}

};

class Book : public Media
{
	std::string author;
	long ISBN;
	int num_pages;

	public:
	Book () {}
	Book (std::string author, long ISBN, int num_pages, std::string title, std::string unique_ID, std::string publisher, Date publication_date) : ISBN(ISBN), num_pages(num_pages), Media(title, unique_ID, publisher, publication_date)
	{
		this -> author = author;
	}

	void displayInfo ()
	{
		std::cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << ISBN << "\nNumber of Pages: " << num_pages << "\nID: " << unique_ID << "\nPublisher: " << publisher << "Publication Date: " << publication_date.day << "." << publication_date.month << "." << publication_date.year << std::endl;
	}
};

class DVD : public Media
{
	std::string director;
	int duration, rating;

	public:
	DVD () {}
	DVD (std::string director, int duration, int rating, std::string title, std::string unique_ID, std::string publisher, Date publication_date) : director(director), duration(duration), rating(rating), Media(title, unique_ID, publisher, publication_date) {}
	void displayInfo ()
	{
		std::cout << "Title: " << title << "\nDirector: " << director << "\nDuration: " << duration << "\nRating: " << rating << "\nID: " << unique_ID << "\nPublisher: " << publisher << "Publication Date: " << publication_date.day << "." << publication_date.month << "." << publication_date.year << std::endl;
	}
};

class CD : public Media
{
	std::string artist, genre;
	int num_tracks;
	public:
	CD () {}
	CD (std::string artist, std::string genre, int num_tracks, std::string title, std::string unique_ID, std::string publisher, Date publication_date) : artist(artist), genre(genre), num_tracks(num_tracks), Media(title, unique_ID, publisher, publication_date) {}

	void displayInfo ()
	{
		std::cout << "Title: " << title << "\nArtist: " << artist << "\nGenre: " << genre << "\nNumber of Tracks: " << num_tracks << "\nID: " << unique_ID << "\nPublisher: " << publisher << "Publication Date: " << publication_date.day << "." << publication_date.month << "." << publication_date.year << std::endl;
	}
};

int main() {
    // Create Date instances
    Date date1 = {1, 1, 2020};
    Date date2 = {15, 7, 2021};
    Date date3 = {1, 1, 2020}; // Same as date1 to test equality

    // Test operator==
    std::cout << "Testing Date equality: ";
    if (date1 == date3) {
        std::cout << "date1 == date3 (PASS)\n";
    } else {
        std::cout << "date1 != date3 (FAIL)\n";
    }

    // Create Media objects (Books, DVDs, and CDs)
    Book book1("J.K. Rowling", 1234567890, 500, "Harry Potter", "B001", "Bloomsbury", date1);
    DVD dvd1("Christopher Nolan", 120, 5, "Inception", "D001", "Warner Bros", date2);
    CD cd1("Coldplay", "Rock", 12, "A Rush of Blood to the Head", "C001", "Parlophone", date3);

    // Array of media objects for searching
    Media* library[] = {&book1, &dvd1, &cd1};
    int num_media = 3;

    // Display information
    std::cout << "\n=== Displaying Media Info ===\n";
    book1.displayInfo();
    std::cout << "----------------------\n";
    dvd1.displayInfo();
    std::cout << "----------------------\n";
    cd1.displayInfo();

    // Test checkOut and returnItem
    std::cout << "\n=== Checking Out Items ===\n";
    std::cout << "Checking out 'Harry Potter': " << (book1.checkOut() ? "Success" : "Failed") << std::endl;
    std::cout << "Checking out 'Inception': " << (dvd1.checkOut() ? "Success" : "Failed") << std::endl;
    
    std::cout << "\n=== Returning Items ===\n";
    std::cout << "Returning 'Harry Potter': " << (book1.returnItem() ? "Success" : "Failed") << std::endl;
    std::cout << "Returning 'Inception': " << (dvd1.returnItem() ? "Success" : "Failed") << std::endl;

    // Test searching functionality
    std::cout << "\n=== Searching for Media ===\n";

    Media media;
    
    std::cout << "\nSearching by title (Harry Potter):\n";
    media.search("Harry Potter", library, num_media);

    std::cout << "\nSearching by publication date (1.1.2020):\n";
    media.search(date1, library, num_media);

    std::cout << "\nSearching by availability (true - available):\n";
    media.search(true, library, num_media);

    return 0;
}
