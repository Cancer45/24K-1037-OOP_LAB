#include <exception>
#include <iostream>

class InsufficientFundsException : public std::exception
{
	public: const char* what () const noexcept override
	{
		return "EXCEPTION: INSUFFICIENT FUNDS\n";
	}
};

template <typename T>
class BankAccount
{
	T balance;

	public:
	BankAccount (T balance) : balance(balance) {}
	void withdraw (T to_withdraw)
	{
		T B_D = balance - to_withdraw;
		if (to_withdraw > balance)
		{
			std::cout << "\nDEFICIT: " << B_D << "\n";
			throw InsufficientFundsException();
		}


		balance -= to_withdraw;
		std::cout << to_withdraw << " WITHDRAWN\n";
		std::cout << "BALANCE: " << B_D << "\n";
	}
};

int main ()
{
	try
	{
		BankAccount account(2000);
		account.withdraw(1000);

		account.withdraw(1500);
	} catch (InsufficientFundsException e) {std::cout << e.what();}
}
