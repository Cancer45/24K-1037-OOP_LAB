#include <fstream>
#include <iostream>

int main ()
{
	std::ifstream read_from;
	std::ofstream book_out("book.txt", std::ios::out | std::ios::app);

	read_from.open("chapter1.txt", std::ios::in);

	std::string word, str1, str2;

	while(read_from >> word)
	{
		str1 = str1 + word + " ";
	}

	read_from.close();
	read_from.open("chapter2.txt", std::ios::in);

	while(read_from >> word)
	{
		str2 = str2 + word + " ";
	}

	book_out << str1 + "\n" << std::endl << str2 << std::endl;
	book_out.close();

	std::ifstream book_in("book.txt", std::ios::in);
	std::string all_book;

	char ch;
	while(!book_in.eof())
	{
		book_in.get(ch);
		all_book = all_book + ch;
	}

	book_in.close();
	std::cout << all_book;
}
