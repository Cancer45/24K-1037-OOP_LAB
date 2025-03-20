#include <iostream>

class Person
{
	protected:
	std::string name, ID, address, email;
	long phone_number;
	
	public:
	Person () {}
	Person (std::string name, std::string ID, std::string address, std::string email, long phone_number) : name(name), ID(ID), address(address), email(email), phone_number(phone_number) {}

	virtual void displayInfo ()
	{
		std::cout << "Name: " << name << "\nID: " << ID << "\nAddress: " << address << "\nEmail: " << email << "\nPhone Number: " << phone_number << std::endl;
	}

	void updateInfo ()
	{
		std::cout << "Name: ";
		std::cin >> name;

		std::cout << "ID: ";
		std::cin >> ID;

		std::cout << "Address: ";
		std::cin >> address;
		
		std::cout << "Email: ";
		std::cin >> email;

		std::cout << "Phone Number: ";
		std::cin >> phone_number;
	}

	std::string getName ()
	{
		return name;
	}
};

class Student : public Person
{
	std::string* courses_enrolled = nullptr;
	float GPA;
	int enrollment_year, num_courses;

	public:
	Student () {}
	Student (std::string name, std::string ID, std::string address, std::string email, long phone_number, std::string* courses_enrolled, float GPA, int enrollment_year, int num_courses) : Person (name, ID, address, email, phone_number), GPA(GPA), enrollment_year(enrollment_year), num_courses(num_courses)
	{
		this -> courses_enrolled = new std::string [num_courses];

		for (int i = 0; i < num_courses; i++)
			this -> courses_enrolled[i] = courses_enrolled[i];
	}

	~Student ()
	{
		delete [] courses_enrolled;
	}

	void displayInfo ()
	{
		std::cout << "Name: " << name << "\nID: " << ID << "\nGPA: " << GPA << "\nEnrollment Year: " << enrollment_year << "\nNum Courses: " << num_courses << "ENROLLED COURSES\n"<< std::endl;

		for (int i = 0; i < num_courses; i++)
			std::cout << courses_enrolled[i] << std::endl;
	}
		
};

class Professor : public Person
{
	std::string department;
	std::string* courses_taught = nullptr;
	float salary;
	int num_courses;
	
	public:
	Professor () {}
	Professor (std::string name, std::string ID, std::string address, std::string email, long phone_number, std::string department, std::string* courses_taught, float salary, int num_courses) : Person (name, ID, address, email, phone_number), department(department), salary(salary), courses_taught(courses_taught), num_courses(num_courses)
	{
		this -> courses_taught = new std::string [num_courses];

		for (int i = 0; i < num_courses; i++)
			this -> courses_taught[i] = courses_taught[i];
	}

	~Professor ()
	{
		delete [] courses_taught;
	}

	void displayInfo ()
	{
		std::cout << "Name: " << name << "\nID: " << ID << "\nSalary: " << salary << "Department: " << department << "\n Num Courses: " << num_courses << "COURSES TAUGHT\n"<< std::endl;

		for (int i = 0; i < num_courses; i++)
			std::cout << courses_taught[i] << std::endl;
	}
};

class Staff : public Person
{
	std::string department, position;
	float salary;

	public:
	Staff () {}
	Staff (std::string name, std::string ID, std::string address, std::string email, long phone_number, std::string department, std::string position, float salary) : Person (name, ID, address, email, phone_number), department(department), salary(salary), position(position) {}

	void displayInfo ()
	{
		std::cout << "Name: " << name << "\nID: " << ID << "\nSalary: " << salary << "Department: " << department << "\n Position: " << position;
	}
};

class Course
{
	std::string* registered = nullptr;
	Professor instructor;
	std::string course_ID, course_name;
	int credits, num_registered;
	
	public:
	Course () {}
	Course (Professor instructor, std::string course_ID, std::string course_name, int credits) : instructor(instructor), course_ID(course_ID), course_name(course_name), credits(credits) {}

	void registerStudent (Student& to_register)
	{
		std::string* tmpArray = new std::string [num_registered + 1];

		for (int i = 0; i < num_registered; i++)
			tmpArray[i] = registered[i];

		tmpArray[num_registered] = to_register.getName();

		delete [] registered;

		registered = tmpArray;
		num_registered++;
	}

	void calculateGrades (int credits_obtained)
	{
		if (credits_obtained / credits > 90)
			std::cout << "A" << std::endl;
		else if (credits_obtained / credits > 80)
			std::cout << "B" << std::endl;
		else if (credits_obtained / credits > 60)
			std::cout << "C" << std::endl;
		else if (credits_obtained / credits > 50)
			std::cout << "D" << std::endl;
		else
			std::cout << "E" << std::endl;
	}
};
