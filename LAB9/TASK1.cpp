#include <iostream>

class Vehicle
{
    protected:
    std::string model_name;
    double rate;

    public:
    Vehicle () {}
    Vehicle (std::string model_name, double rate) : model_name(model_name), rate(rate) {}

    virtual double getDailyRate () = 0;
    virtual void displayDetails () = 0;
};

class Car : public Vehicle
{
    public:
    Car () {}
    Car (std::string model_name, double rate) : Vehicle (model_name, rate) {} 
    
    double getDailyRate () override
    {
        return rate;
    }

    void displayDetails () override
    {
        std::cout << "Car Model: " + model_name + "\nRate: ";
        std::cout << rate << std::endl;
    }
};

class Bike : public Vehicle
{
    public:
    Bike () {}
    Bike (std::string model_name, double rate) : Vehicle (model_name, rate) {} 
    
    double getDailyRate () override
    {
        return rate;
    }

    void displayDetails () override
    {
        std::cout << "Bike Model: " + model_name + "\nRate: ";
        std::cout << rate << std::endl;
    }
};

int main ()
{
    Vehicle* vptr;
    Car obj1("Honda Civic", 25);
    Bike obj2("Honda 70cc", 12);

    vptr = &obj1;
    std::cout << "\n" << vptr -> getDailyRate() << std::endl;
    vptr -> displayDetails();

    vptr = &obj2;
    std::cout << "\n" << vptr -> getDailyRate() << std::endl;
    vptr -> displayDetails();
}