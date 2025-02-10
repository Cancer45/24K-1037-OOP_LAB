#include <iostream>

class Student
{
    int studentID, age;
    std::string name;
    char grade;

    public:
    //constructor 1 (default)
    Student ()
    {
        grade = 'N';
    }

    //constructor 2 (parameterized)
    Student (int studentID, int age, std::string name, char grade)
    {
        this -> studentID = studentID;
        this -> age = age;
        this -> name = name;
        this -> grade = grade;
    }

    //method 1
    void promoteStudent ()
    {
        if (grade == 'A')
        {
            std::cout << "Student already has highest available grade." << std::endl;
            return;
        }
    
        else if (grade == 'N')
        {
            grade = 'F';
            std::cout << "Grade '" << grade << "' asigned." << std::endl;
            return;
        }

        grade--;
        std::cout << "Grade promoted to '" << grade << "'." << std::endl;
    }

    bool isEligibleForScholarship ()
    {
        if (grade == 'A')
        return true;

        return false;
    }

    void displayDetails ()
    {
        std::cout << "ID: " << studentID << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Grade: " << grade << std::endl;
    }
};

int main ()
{
    Student stdnt1;

    //display details with default constructor
    stdnt1.displayDetails();

    //initialize second obj with parameterized constructor
    Student stdnt2(9051, 17, "Shazeb", 'B');
    
    //check eligibility before promotion
    if (stdnt2.isEligibleForScholarship())
    std::cout << "Eligible for scholarship." << std::endl;

    else
    std::cout << "Not eligible for scholarship." << std::endl;

    stdnt2.displayDetails();

    stdnt2.promoteStudent();

    //check eligibility before promotion
    if (stdnt2.isEligibleForScholarship())
    std::cout << "Eligible for scholarship." << std::endl;

    else
    std::cout << "Not eligible for scholarship." << std::endl;
}