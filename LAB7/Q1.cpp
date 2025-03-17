#include <iostream>
#include <cmath>

class Account
{
    protected:
    int accountNumber; 
    double balance;
    std::string accountHolderName, accountType;
    double* transactions = nullptr;
    int numTrans;

    public:
    Account () : accountNumber(0), balance(0), accountHolderName("default"), accountType("default")
    {
        numTrans = 0;
        transactions = new double [numTrans + 1];
    }
    Account (int accountNumber, double balance, std::string accountHolderName, std::string accountType) : accountNumber(accountNumber), balance(balance), accountHolderName(accountHolderName), accountType(accountType) 
    {
        numTrans = 0;
        transactions = new double [numTrans + 1];
    }

    void deposit (double amount)
    {
        balance += amount;
        
        transactions[numTrans] = amount;
        numTrans++;
        
        double* tmpArray = new double [numTrans + 1];
        for (int i = 0; i < numTrans; i++)
        {
            tmpArray[i] = transactions[i];
        }

        delete [] transactions;
        transactions = tmpArray;
    }

    bool withdraw (double amount)
    {
        if (amount > balance)
        {
            std::cout << "INSUFFICIENT FUNDS" << std::endl;
            return false;
        }

        balance -= amount;

        transactions[numTrans] = -amount;
        numTrans++;
        
        double* tmpArray = new double [numTrans + 1];
        for (int i = 0; i < numTrans; i++)
        {
            tmpArray[i] = transactions[i];
        }

        delete [] transactions;
        transactions = tmpArray;
        return true;
    }

    double calculateInterest (int interestRatePercentage)
    {
        return (interestRatePercentage / 100) * balance;
    }

    void printStatement ()
    {
        for (int i = 0; i < numTrans; i++)
        {
            std::cout << i + 1 << ". " << transactions[i] << std::endl;
        }
    }

    void getAccountInfo ()
    {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Name: " << accountHolderName << std::endl;
        std::cout << "Account Type: " << accountType << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }
};

class CheckingAccount : public Account
{
    public:
    CheckingAccount () : Account () {}
    CheckingAccount (int accountNumber, double balance, std::string accountHolderName, std::string accountType) : Account(accountNumber, balance, accountHolderName, accountType) {} 
};

class SavingsAccount : public Account
{
    int interestRatePercentage;
    double minimumBalance, principal;

    public:
    SavingsAccount () : interestRatePercentage(5), minimumBalance(5000) {}
    SavingsAccount (int interestRatePercentage, double minimumBalance, int accountNumber, double balance, std::string accountHolderName, std::string accountType) : Account(accountNumber, balance, accountHolderName, accountType), interestRatePercentage(interestRatePercentage), minimumBalance(minimumBalance), principal(balance) {} 

    int getInterestRate ()
    {
        return interestRatePercentage;
    }

    double getMinimumBalance ()
    {
        return minimumBalance;
    }

    double calculateInterest (int age /*in days*/)
    {
        return principal * pow(1 + interestRatePercentage / 4, 4 * age);
    }

    void printStatement (int age /*in days*/)
    {
        for (int i = 0; i < numTrans; i++)
        {
            std::cout << i + 1 << ". " << transactions[i] << std::endl;
        }

        std::cout << "Interest Earned: " << calculateInterest(age) << std::endl;
    }
};

class FixedDepositAccount : public Account
{
    int fixedInterestRatePercentage;
    int maturityRate; //in months
    double principal;

    public:
    FixedDepositAccount () : fixedInterestRatePercentage(5), maturityRate(18) {}
    FixedDepositAccount (int fixedInterestRatePercentage, int maturityRate, int accountNumber, double balance, std::string accountHolderName, std::string accountType) : Account(accountNumber, balance, accountHolderName, accountType), fixedInterestRatePercentage(fixedInterestRatePercentage), maturityRate(maturityRate), principal(balance) {} 

    int getInterestRate ()
    {
        return fixedInterestRatePercentage;
    }

    double getMaturityRate ()
    {
        return maturityRate;
    }

    double calculateInterest (int age /*in days*/)
    {
        return principal * (fixedInterestRatePercentage / 100);
    }

    void printStatement (int age /*in days*/)
    {
        for (int i = 0; i < numTrans; i++)
        {
            std::cout << i + 1 << ". " << transactions[i] << std::endl;
        }

        std::cout << "Interest Earned: " << calculateInterest(age) << std::endl;
    }

    bool withdraw (double amount)
    {
        std::cout << "CANNOT WITHDRAW FROM FIXED DEPOSIT ACCOUNT" << std::endl;
    }
};

int main() 
{
    SavingsAccount savings(5, 5000, 1001, 10000, "John Doe", "Savings");
    savings.deposit(2000);
    savings.deposit(1500);

    CheckingAccount checking(2001, 5000, "Jane Doe", "Checking");
    checking.deposit(1000);

    FixedDepositAccount fd(6, 18, 3001, 10000, "Alice", "Fixed Deposit");

    savings.printStatement(365);
    checking.printStatement();
    fd.printStatement(540);

    return 0;
}