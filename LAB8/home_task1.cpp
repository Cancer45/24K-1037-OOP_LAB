#include <iostream>

using namespace std;

class BankAccount 
{
protected:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
    
    virtual double calculateInterest() = 0;
    virtual void withdraw(double amount) = 0;
    
    void deposit(double amount) {
        balance += amount;
    }
    
    void deposit(double amount, string type) {
        balance += amount;
    }
    
    BankAccount operator+(const BankAccount& other) {
        return BankAccount(accountNumber, balance + other.balance);
    }
    
    BankAccount operator-(double amount) {
        return BankAccount(accountNumber, balance - amount);
    }
    
    BankAccount operator*(double rate) {
        return BankAccount(accountNumber, balance * rate);
    }
    
    BankAccount operator/(int installments) {
        return BankAccount(accountNumber, balance / installments);
    }
    
    double getBalance() {
        return balance;
    }
};

class SavingsAccount : public BankAccount 
{
public:
    SavingsAccount(int accNum, double bal) : BankAccount(accNum, bal) {}
    
    double calculateInterest() override {
        return balance * 0.05;
    }
    
    void withdraw(double amount) override {
        if (balance - amount >= 500) {
            balance -= amount;
        }
    }
};

class CurrentAccount : public BankAccount 
{
public:
    CurrentAccount(int accNum, double bal) : BankAccount(accNum, bal) {}
    
    double calculateInterest() override {
        return 0;
    }
    
    void withdraw(double amount) override {
        if (balance - amount >= -1000) {
            balance -= amount;
        }
    }
};

int main() 
{
    SavingsAccount sa(101, 1000);
    CurrentAccount ca(102, 500);
    
    sa.deposit(200);
    ca.deposit(300, "online");
    
    sa.withdraw(700);
    ca.withdraw(1200);
    
    BankAccount totalBalance = sa + ca;
    
    cout << "Total Balance: " << totalBalance.getBalance() << endl;
    
    return 0;
}