#include <iostream>

using namespace std;

typedef struct
{
    int day, month, year;
} Date;

typedef struct
{
   string name, venue, organizer;
   Date date;
   
} Event;

int main ()
{
    int numEvents;
    
    cout << "Number of Events: ";
    cin >> numEvents;
    
    Event* event = new Event [numEvents];
    Date tmpdate;
    
    for (int i = 0; i < numEvents; i++)
    {
        cout << endl << "EVENT " << i + 1 << endl;
        
        cout << "Day: ";
        cin >> event[i].date.day;
        cout << "Month: ";
        cin >> event[i].date.month;
        cout << "Year: ";
        cin >> event[i].date.year;
        cout << "Event Name: ";
        cin >> event[i].name;
        cout << "Venue: ";
        cin >> event[i].venue;
        cout << "Organizer: ";
        cin >> event[i].organizer;
    }
    
        cout << endl << "Day: ";
        cin >> tmpdate.day;
        cout << "Month: ";
        cin >> tmpdate.month;
        cout << "Year: ";
        cin >> tmpdate.year;

        for (int i = 0; i < numEvents; i++)
        {
            if (tmpdate.day == event[i].date.day && tmpdate.month == event[i].date.month && tmpdate.year == event[i].date.year)
            {   
                cout << endl << "EVENT " << i + 1 << endl;
                cout << "Date: " << event[i].date.day << "." << event[i].date.month << "." << event[i].date.year << endl;
                cout << "Event Name: " << event[i].name << endl;
                cout << "Venue: " << event[i].venue << endl;
                cout << "Organizer: " << event[i].organizer << endl;
            }
        }
    
}
