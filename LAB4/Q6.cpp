#include <iostream>

class Account
{
    std::string accNum, accHolderName;
    double balance;

    public:
    //default constructor
    Account () : balance(0.0) {}

    Account (std::string accNum, std::string accHolderName, double balance)
    {
        this -> accNum = accNum;
        this -> accHolderName = accHolderName;
        this -> balance = balance;
    }

    //method 1
    void deposit (double amount)
    {
        balance += amount;
        std::cout << amount << " added" << std::endl;
    }

    //method 2
    void withdraw (double amount)
    {
        if (amount <= balance)
        balance -= amount;
        return;

        std::cout << amount << " deducted" << std::endl;
    }

    //method 3
    void displayDetails ()
    {
        std::cout << "Name: " << accHolderName << std::endl;
        std::cout << "Acc No: " << accNum << std::endl;
        std::cout << "Balance: " << balance << std::endl << std::endl;
    }
};

int main ()
{
    Account acc1 ("001071391", "Zulfiqar", 102345), acc2;

    acc1.displayDetails();

    acc2.deposit(100);
    acc2.withdraw(17);

    acc2.displayDetails();
}
