#include <iostream>

class BankAccount
{
    int acc_num;
    std::string acc_hold_name;
    double balance;

    public:
    BankAccount (int acc_num, std::string acc_hold_name, double balance) : acc_num(acc_num), acc_hold_name(acc_hold_name), balance(balance) {}

    void deposit (double amount)
    {
        balance += amount;
        std::cout << amount <<" DEPOSITED\n" << "BALANCE: " << balance << std::endl;
    }

    int withdraw (double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;

            std::cout << amount <<" WITHDRAWN\n" << "BALANCE: " << balance << std::endl;
            return 1;
        }

        std::cout <<"INSUFFICIENT FUNDS" << std::endl;
        return 0;    
    }

    void display ()
    {
        std::cout << "\nAccount Holder: " << acc_hold_name << "    | Account Number: " << acc_num << "    | Balance: " << balance << std::endl;
    }
};

int main ()
{
    BankAccount* accounts[3];

    accounts[0] = new BankAccount (61759, "Saqib", 2234.31);
    accounts[1] = new BankAccount (60982, "Ammar", 99385.253);
    accounts[2] = new BankAccount (21940, "Rubab", 23632.245);

    for (int i = 0; i < 3; i++)
    {
        std::cout << "ACCOUNT " << i + 1 << std::endl;

        accounts[i] -> display();

        accounts[i] -> deposit(500);
        accounts[i] -> display();
        
        accounts[i] -> withdraw(200);
        accounts[i] -> display();
    }
}