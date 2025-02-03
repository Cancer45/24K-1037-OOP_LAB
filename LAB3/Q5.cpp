#include <iostream>

using namespace std;

class Calendar
{
    string details;
    string** months;

    public:
    Calendar()
    {
        months = new string* [12];

        for (int i = 0; i < 12; i++) 
        {
            months[i] = new string[31];
            
            for (int j = 0; j < 31; j++) 
            {
                months[i][j] = "";
            }
        }
    }

    //method 1
    void addTask (int month, int day)
    {
        while (month < 1 || month > 12)
        {
            cout << "Try Again, Month: ";
            cin >> month; 
        }

        while (day < 1 || day > 31)
        {
            cout << "Try Again, Day: ";
            cin >> day; 
        }
    
        cout << "Details: ";
        cin >> months[month - 1][day - 1];

        cout << "ADDED" << endl;
    }

    //method 2
    void removeTask (int month, int day)
    {
        while (month < 1 || month > 12)
        {
            cout << "Try Again, Month: ";
            cin >> month; 
        }

        while (day < 1 || day > 31)
        {
            cout << "Try Again, Day: ";
            cin >> day; 
        }
    
        months[month - 1][day - 1] = "";
        cout << "REMOVED" << endl;
    }

    //method 3
    void displayTasks ()
    {
        unsigned int counter = 0;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                if (months[i][j] != "")
                {
                    counter++;
                    cout << "TASK " << counter << ": " << months[i][j] << endl;
                }
            }
        }
    }

};

int main ()
{
    Calendar calendar;

    calendar.addTask(3, 1);
    calendar.addTask(5, 17);
    calendar.addTask(11, 25);
    calendar.addTask(4, 8);
    calendar.addTask(1, 17);
    calendar.addTask(3, 21);

    calendar.removeTask(11, 25);
    calendar.removeTask(4, 8);
    calendar.removeTask(1, 17);

    calendar.displayTasks();
}