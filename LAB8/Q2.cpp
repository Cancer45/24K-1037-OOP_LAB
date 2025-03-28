#include <iostream>

class Account
{
	std::string accountNumber, accountHolder;
	double balance;

	public:
	Account () {}
	Account (std::string accountNumber, std::string accountHolder, double balance) : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance) {}

	Account operator+ (const Account& other)
	{
		if (this != &other)
		{
			this -> balance += other.balance;
		}

		return (*this);
	}

	Account& operator= (double amount)
	{
		this -> balance = amount;

		return *(this);
	}

	bool operator> (const Account& other)
	{
		if (other.balance > this -> balance)
			return true;
		return false;
	}

	bool operator< (const Account& other)
	{
		if (other.balance < this -> balance)
			return true;
		return false;
	}

	friend std::ostream& operator<< (std::ostream& output_stream, const Account& to_output);

	std::string getHolder ()
	{
		return accountHolder;
	}
};

	std::ostream& operator<< (std::ostream& output_stream, const Account& to_output)
	{
		output_stream << "\nAccount Number: " << to_output.accountNumber << "\nAccount Holder: " << to_output.accountHolder << "\nBalance: " << to_output.balance << std::endl;

		return output_stream;
	}

int main ()
{
	Account acc1("1934830923", "Abdul Samad", 2011238);
	Account acc2("1203499904", "Shabbir Ghauri", 8472018);

	std::cout << "\nBEFORE CHANGE";
	std::cout << acc1;
	std::cout << acc2;

	std::cout << "\nADD ACC1 TO ACC1; NO CHANGE EXPECTED";
	acc1 = acc1 + acc1;
	std::cout << acc1;

	if (acc1 > acc2)
		std::cout << acc1.getHolder() << " is richer" << std::endl;

	if (acc1 < acc2)
		std::cout << acc2.getHolder() << " is richer" << std::endl;

	std::cout << "\nADD ACC2 TO ACC1";
	acc1 = acc1 + acc2;
	std::cout << acc1;

	if (acc1 > acc2)
		std::cout << acc1.getHolder() << " is richer" << std::endl;

	if (acc1 < acc2)
		std::cout << acc2.getHolder() << " is richer" << std::endl;
}
