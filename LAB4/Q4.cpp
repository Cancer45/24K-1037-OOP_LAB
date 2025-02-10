#include <iostream>

class Car
{
    int carID, year;
    std::string model;
    bool isRented;

    public:
    Car ()
    {
        isRented = false;
    }

    Car (int carID, std::string model, int year, bool isRented)
    {
        this -> carID = carID;
        this -> model = model;
        this -> year = year;
        this -> isRented = isRented;
    }

    void rentCar ()
    {
        if (!isRented)
        {
            isRented = true;
            std::cout << "Car rented." << std::endl;
        }
        

        else
        std::cout << "Car already rented." << std::endl;
    }

    void returnCar ()
    {
        if (isRented)
        {
            isRented = false;
            std::cout << "Car returned." << std::endl;
        }

        else
        std::cout << "Car not already rented." << std::endl;
    }

    bool isVintage ()
    {
        if (year < 2000)
        return true;

        else
        return false;
    }

    std::string getModel ()
    {
        return model;
    }
};

int main ()
{
    bool isVintage;

    Car car1 (1, "Corolla", 2003, false), car2 (2, "Civic", 1995, false);

    car1.rentCar();
    car1.returnCar();

    isVintage = car1.isVintage();

    if (car1.isVintage())
    std::cout << "Car " << car1.getModel() << " is vintage." << std::endl;

    else
    std::cout << "Car " << car1.getModel() << " is not vintage." << std::endl;

    isVintage = car2.isVintage();

    if (car2.isVintage())
    std::cout << "Car " << car2.getModel() << " is vintage." << std::endl;

    else
    std::cout << "Car " << car2.getModel() << " is not vintage." << std::endl;
}