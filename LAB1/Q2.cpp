#include <iostream>

using namespace std;

struct Student
{
    int mathsScore, engScore, sciScore, total;
    float average;
    char grade;
};

void getMarks (struct Student& student)
{
    cout << "Mathematics Score: ";
    cin >> student.mathsScore;
    cout << "English Score: ";
    cin >> student.engScore;
    cout << "Science Score: ";
    cin >> student.sciScore;
}

void getTotal (struct Student& student)
{
    student.total = student.mathsScore + student.engScore + student.sciScore;
}

void getAvg (struct Student& student)
{
    student.average = ((float) student.total) / 3;
}

void getGrade (struct Student& student)
{
    if (student.average <= 100 && student.average >= 90)
    student.grade = 'A';

    else if (student.average <= 89 && student.average >= 80)
    student.grade = 'B';
    
    else if (student.average <= 79 && student.average >= 70)
    student.grade = 'C';
    
    else if (student.average <= 69 && student.average >= 60)
    student.grade = 'D';
    
    else
    student.grade = 'F';
}

void displayInfo (struct Student& student)
{
     cout << "Mathematics: " << student.mathsScore << endl << "English: " << student.engScore << endl << "Science: " << student.sciScore << endl << "Total: " << student.total << endl << "Average: " << student.average << endl << "Grade: " << student.grade;
}

int main ()
{
    int numStudents;
    
    cout << "Number of Students: ";
    cin >> numStudents;
    Student* students = new Student[numStudents];
    
    //get stuff
    for (int i = 0; i < numStudents; i++)
    {
        cout << "STUDENT " << i + 1 << endl;
        getMarks(students[i]);
        getTotal(students[i]);
        getAvg(students[i]);
        getGrade(students[i]);
    }
    
    //display stuff
    for (int i = 0; i < numStudents; i++)
    {
        cout << endl << "STUDENT " << i + 1 << endl;
        displayInfo(students[i]);
    }
}





