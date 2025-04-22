#include <iostream>
#include <fstream>
//#include <ifstream>

typedef struct Student
{
    int id;
    std::string name;
    float gpa;

    Student (int id = 0, std::string name = "default", float gpa = 0) : id(id), name(name), gpa(gpa) {}

    void displayStudent ()
    {
        std::cout << "Name: " + name << std::endl;
        std::cout << "ID: " << id << std::endl;
        std::cout << "GPA: " << gpa << std::endl;
    }
} Student;

int main ()
{
    Student* students = new Student [6];

    std::string name;
    int id;
    float gpa;

    std::cout << "WRITING\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Student " << i + 1 << std::endl;

        std::cout << "ID: ";
        std::cin >> id;

        std::cout << "Name: ";
        std::cin >> name;

        std::cout << "GPA: ";
        std::cin >> gpa;

        students[i] = Student (id, name, gpa);
    }

    std::ofstream students_file_out("students.txt", std::ios::out|std::ios::app) ;

    for (int i = 0; i < 5; i++)
    {
        students_file_out << students[i].id;
        students_file_out << " ";

        students_file_out << students[i].name;
        students_file_out << " ";

        students_file_out << students[i].gpa;
        students_file_out << " ";
    }

    std::cout << "Student " << 6 << std::endl;

    std::cout << "ID: ";
    std::cin >> id;

    std::cout << "Name: ";
    std::cin >> name;

    std::cout << "GPA: ";
    std::cin >> gpa;

    students[5] = Student (id, name, gpa);

    students_file_out << students[5].id;
    students_file_out << " ";

    students_file_out << students[5].name;
    students_file_out << " ";

    students_file_out << students[5].gpa;
    students_file_out << " ";

    delete [] students;
    students_file_out.close();

    std::ifstream students_file_in ("students.txt", std::ios::in);

    std::cout << "READING\n";

    while (!students_file_in.eof())
    {
        students_file_in >> id;
        students_file_in >> name;
        students_file_in >> gpa;

        std::cout << "Name: " + name << std::endl;
        std::cout << "ID: " << id << std::endl;
        std::cout << "GPA: " << gpa << std::endl;
    }

    students_file_in.close();
}

