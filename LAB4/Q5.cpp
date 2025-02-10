#include <iostream>

class Employee
{
    int employeeID;
    std::string name, department;
    double salary;

    public:
    Employee () : salary (0.0) {}

    Employee (int employeeID, std::string name, std::string department, double salary) 
    {
        this -> employeeID = employeeID;
        this -> name = name;
        this -> department = department;
        this -> salary = salary;
    }

    void giveBonus (double amount)
    {
        salary += amount;
    }

    bool isManager ()
    {
        if (department == "Management")
        return true;

        return false;
    }

    void displayDetails ()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << employeeID << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Salary: " << salary << std::endl;

        std::cout << std::endl;
    }
};

int main ()
{
    Employee emp1, emp2 (1001, "Farhad", "Management", 120000);

    emp2.giveBonus(1000);

    if (emp2.isManager())
    std::cout << "Is Manager" << std::endl;

    else
    std::cout << "Is Not Manager" << std::endl;

    emp2.displayDetails();

    //will be garbage except salary
    std::cout << "Garbage: " << std::endl;
    emp1.displayDetails();
}