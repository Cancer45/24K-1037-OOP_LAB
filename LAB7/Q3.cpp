#include <iostream>

// BASE CURRENCY IS DOLLAR
class Dollar;

class Currency
{
	protected:
	float amount, exchange_rate; // exchange rate is set with base currency and is equal to this_currency_rate / base_currency_rate
	std::string name, currency_code, currency_symbol;

	public:
	Currency () {}
	Currency (float amount, std::string currency_code, std::string currency_symbol, float exchange_rate, std::string name) : amount(amount), currency_code(currency_code), currency_symbol(currency_symbol), exchange_rate(exchange_rate), name(name) {}

	float convertToBase ()
	{
		return amount / exchange_rate; 
	}

	void convertTo (Currency& target_currency)
	{
		std::cout << "Original Amount: " << amount << std::endl << "Amount in " << target_currency.getName() << " : " << convertToBase() * target_currency.getERate() << std::endl;
	}

	void displayCurrency ()
	{
		std::cout << "Name: " + name << std::endl << "Code: " + currency_code << std::endl << "Symbol: " << currency_symbol << std::endl << "Amount: " << amount << std::endl << "Exchange Rate: " << exchange_rate << std::endl;
	}

	float getERate () const
	{
		return exchange_rate;
	}
	
	std::string getName () const
	{
		return name;
	}
};

class Dollar : public Currency
{
	public:
	Dollar () {}
	Dollar (float amount, std::string currency_code, std::string currency_symbol, float exchange_rate, std::string name) : Currency(amount, currency_code, currency_symbol, exchange_rate, name) {}
};

class Euro : public Currency
{
	public:
	Euro () {}
	Euro (float amount, std::string currency_code, std::string currency_symbol, float exchange_rate, std::string name) : Currency(amount, currency_code, currency_symbol, exchange_rate, name) {}
};

class Rupee : public Currency
{
	public:
	Rupee () {}
	Rupee (float amount, std::string currency_code, std::string currency_symbol, float exchange_rate, std::string name) : Currency(amount, currency_code, currency_symbol, exchange_rate, name) {}
};

int main()
{
    // Create different currency objects
    Dollar usd(100, "USD", "$", 1.0, "US Dollar");
    Euro eur(100, "EUR", "€", 0.85, "EURO"); // 1 USD = 0.85 EUR
    Rupee inr(100, "INR", "₹", 74.5, "Indian Rupee"); // 1 USD = 74.5 INR

    // Display their details
    std::cout << "\nCurrency Details:\n";
    usd.displayCurrency();
    std::cout << "\n";
    eur.displayCurrency();
    std::cout << "\n";
    inr.displayCurrency();
    std::cout << "\n";

    // Convert between currencies
    std::cout << "Conversions:\n";
    usd.convertTo(eur);
    std::cout << "\n";
    eur.convertTo(inr);
    std::cout << "\n";
    inr.convertTo(usd);
    std::cout << "\n";

    return 0;
}
