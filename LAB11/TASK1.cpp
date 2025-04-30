#include <iostream>

class InvalidValueException : public std::exception
{
	public:
	const char* what () const noexcept override
	{
		return "ARITHEMTIC EXCEPTION!\n";
	}
};

bool validateAge (int age)
{
	try
	{
		if (age > 120 || age < 0)
		{
			throw InvalidValueException();
		}
	}
	catch (InvalidValueException e)
	{
		std::cout << e.what();
		return false;
	}

	return true;
}

int main ()
{
	int my_nums [3] = {-3, 88, 245};
	for (int i = 0; i < 3; i++)
	{
		try
		{
			if (validateAge(my_nums[i]))
				std::cout << "VALID\n";
		}
		catch (InvalidValueException e) {std::cout << e.what();}
	}
}
	
