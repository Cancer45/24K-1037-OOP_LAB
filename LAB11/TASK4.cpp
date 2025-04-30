#include <exception>
#include <typeinfo>
#include <cmath>
#include <iostream>

class NegativeNumberException : public std::exception
{
	public:
	const char* what () const noexcept override
	{
		return "EXCEPTION: NEGATIVE VALUE\n";
	}
};

class InvalidTypeException : public std::exception
{
	public:
	const char* what () const noexcept override
	{
		return "EXCEPTION: INVALID TYPE\n";
	}
};

template <typename T>
double sqrt (T to_sqrt)
{
	int INT = 0;
	double DOUBLE = 0.0;

	if (typeid(to_sqrt) != typeid(INT) && typeid(to_sqrt) != typeid(DOUBLE))
		throw InvalidTypeException();
	if (to_sqrt < 0)
		throw NegativeNumberException();

	return std::sqrt(to_sqrt); 
}

int main ()
{
	int my_nums [3] = {144, -39, 121};
	for (int i = 0; i < 3; i++)
	{
		try
		{
			std::cout << sqrt(my_nums[i]) << std::endl;
		}
		catch (InvalidTypeException e)
		{
			std::cout << e.what();
		}
		catch (NegativeNumberException e)
		{
			std::cout << e.what();
		}
	}

	try
	{
		std::cout << sqrt(true) << std::endl;
	}
	catch (InvalidTypeException e)
	{
		std::cout << e.what();
	}
	catch (NegativeNumberException e)
	{
		std::cout << e.what();
	}
}
