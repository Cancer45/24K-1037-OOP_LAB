#include <exception>
#include <iostream>

class StackOverflowException : public std::exception
{
	public:
	const char* what () const noexcept override
	{
		return "STACK OVERFLOW\n";
	}
};

class StackUnderflowException : public std::exception
{
	public:
	const char* what () const noexcept override
	{
		return "STACK UNDERFLOW\n";
	}
};

template <typename T>
class Stack
{
	int size, curr_size;
	T* stack = nullptr;

	public:
	Stack (int size = 5) : size(size), curr_size(0) {}
	void push (T to_push)
	{
		if (size == curr_size)
			throw StackOverflowException();

		T* tmp_stack = new T [curr_size + 1];

		for (int i = 0; i < curr_size; i++)
			tmp_stack[i] = stack[i];

		tmp_stack[curr_size] = to_push;
		delete [] stack;

		stack = tmp_stack;
		curr_size++;
	}

	void pop ()
	{
		if (curr_size == 0)
			throw StackUnderflowException();
		
		T* tmp_stack = new T [curr_size - 1];

		for (int i = 0; i < curr_size - 1; i++)
			tmp_stack[i] = stack[i];

		delete [] stack;

		stack = tmp_stack;
		curr_size--;
	}
};

int main ()
{
	Stack <std::string>new_stack(2);	
	std::string my_strings [3] = {"this is str 1", "this is not str1 (its str2)", "this is str3"};

	for (int i = 0; i < 3; i++)
	{
		try
		{
			new_stack.push(my_strings[i]);
			std::cout << "PUSHED\n";
		}
		catch (StackOverflowException e) {std::cout << e.what();}
	}

	for (int i = 0; i < 3; i++)
	{
		try
		{
			new_stack.pop();
			std::cout << "POPPED\n";
		}
		catch (StackUnderflowException e) {std::cout << e.what();}
	}
}
