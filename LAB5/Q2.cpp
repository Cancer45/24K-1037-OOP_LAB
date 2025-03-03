#include <iostream>

class LoanHelper
{
    const float interest_rate, amount_taken;
    const int repay_period;

    public:
    //parameterized constructor
    LoanHelper (const float interest_rate, const float amount_taken, const int repay_period) : interest_rate(interest_rate), amount_taken(amount_taken), repay_period(repay_period) {}

    void helpMe ()
    {
        float per_month = amount_taken / repay_period;

        per_month *= 1 + (interest_rate / 100);

        std::cout << "You have to pay " << per_month << " every month for " << repay_period << " months  to repay your loan." << std::endl;
    }
};

int main ()
{
    LoanHelper myLoan(6.5, 1200, 27);

    myLoan.helpMe();
}