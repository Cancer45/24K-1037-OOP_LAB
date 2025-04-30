#include <exception>
#include <fstream>
#include <iostream>

class FileException : public std::exception
{
	public:
	virtual const char* what () const noexcept override
	{
		return "FILE EXCEPTION\n";
	}
};

class FileNotFoundException : public FileException
{
	public:
	const char* what () const noexcept override
	{
		return "EXCEPTION: FILE NOT FOUND\n";
	}
};

class PermissionDeniedException : public FileException
{
	public:
	const char* what () const noexcept override
	{
		return "EXCEPTION: PERMISSION DENIED\n";
	}
};

int main ()
{
	std::string file_name;
	std::fstream new_file;
	FileException* fEptr = nullptr;

	try
	{
		std::cout << "FILE NAME: ";
		std::cin >> file_name;

		if (file_name == "secret.txt")
			throw PermissionDeniedException();

		new_file.open(file_name, std::ios::in);
		if (!new_file) throw FileNotFoundException();

		std::cout << file_name + "opened\n";
	}
	catch (FileNotFoundException e)
	{
		fEptr = &e;
		std::cout << fEptr->what();
	}

	catch (PermissionDeniedException e)
	{
		fEptr = &e;
		std::cout << fEptr->what();
	}

	new_file.close();
}
