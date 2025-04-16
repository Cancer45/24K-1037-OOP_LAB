#include <iostream>

class PaymentMethod
{
	public:
	virtual void processPayment (double amount) = 0;
};

class CreditCard : public PaymentMethod
{
	std::string card_number;
	double balance;

	public:
	CreditCard (std::string card_number = "0", double balance = 0) : card_number(card_number), balance(balance) {}

	void processPayment (double amount) override
	{
		if (amount <= balance)
		{
			balance -= amount;
			std::cout << "Validated and Processed (CREDIT CARD)\nBalance: " << balance << std::endl;
		}

		else
			std::cout << "Invalid Amount (CREDIT CARD)\n";
	}
};

class DigitalWallet : public PaymentMethod
{
	std::string wallet_ID;
	double balance;

	public:
	DigitalWallet (std::string wallet_ID = "0", double balance = 0) : wallet_ID(wallet_ID), balance(balance) {}

	void processPayment (double amount) override
	{
		if (amount <= balance)
		{
			balance -= amount;
			std::cout << "Validated and Processed (DIGITAL WALLET)\nBalance: " << balance << std::endl;
		}

		else
			std::cout << "Invalid Amount (DIGITIAL WALLET)\n";
	}
};

int main ()
{
	CreditCard cc_obj("0394 2930 1733 4468", 7532);
	DigitalWallet sw_obj("19438202", 9874);

	PaymentMethod* pm_ptr = &cc_obj;

	pm_ptr->processPayment(44);
	pm_ptr->processPayment(10000);

	pm_ptr = &sw_obj;
	std::cout << std::endl;

	pm_ptr->processPayment(9090);
	pm_ptr->processPayment(10000);
}
