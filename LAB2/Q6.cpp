#include <iostream>

using namespace std;

typedef struct 
{
	string courseID, courseName;
} Register;

typedef struct
{
	string studentID, firstName, lastName, cellNo, email;
	Register courses;
} Student;

int main ()
{
	Student* student = new Student [5];
	
	for (int i = 0; i < 5; i++)
	{
		cout << endl << "STUDENT " << i + 1 << endl << "Full Name: ";
		cin >> student[i].firstName >> student[i].lastName;
		cout << "ID: ";
		cin >> student[i].studentID;
		cout << "Phone Number: ";
		cin >> student[i].cellNo;
		cout << "Email: ";
		cin >> student[i].email;
		cout << "Course Name: ";
		cin >> student[i].courses.courseName;
		cout << "Course ID: ";
		cin >> student[i].courses.courseID;
	}
	
	for (int i = 0; i < 5; i++)
	{
		cout << endl << "STUDENT " << i + 1 << endl;
		cout << "Name: " << student[i].firstName << " " << student[i].lastName << endl << "ID: " << student[i].studentID << endl << "Phone Number: " << student[i].cellNo << endl << "Email: " << student[i].email << endl << "Course Name: " << student[i].courses.courseName << endl << "Course ID: " << student[i].courses.courseID << endl;
	}
		
	delete [] student;
}
