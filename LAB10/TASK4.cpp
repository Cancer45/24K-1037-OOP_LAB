#include <iostream>
#include <fstream>

void displayContents (std::ifstream& read_from)
{
	char ch;

	while (read_from.get(ch))
	{
		std::cout << ch;
	}

	read_from.clear();
	read_from.seekg(std::ios::beg);
}

void displayContents (std::fstream& read_from)
{
	char ch;

	while (read_from.get(ch))
	{
		std::cout << ch;
	}

	read_from.clear();
	read_from.seekg(std::ios::beg);
}

int main ()
{
	std::ofstream info_out("info.txt", std::ios::out);
	info_out << "C++ is a powerful programming language\n";

	info_out.close();
	std::fstream info("info.txt", std::ios::in | std::ios::out);

	std::cout << "BEFORE CHANGE\n";
	displayContents(info);

	std::cout << info.tellg() << std::endl;

	std::string word;

	info.seekg(9);
	info >> word;
	std::cout << word;

	info.seekp(9);
	info << "dynamic ";

	std::cout << "\nGet Ptr: " << info.tellg() << "\nPut Ptr: " << info.tellp() << std::endl;

	info.seekg(std::ios::beg);

	std::cout << "AFTER CHANGE\n";
	displayContents(info);

	info.close();
}
