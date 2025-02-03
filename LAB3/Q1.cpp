#include <iostream>

using namespace std;

class Time
    {   
        unsigned int hours, minutes, seconds;

        public:   
        //constructor 1
        Time ()
        {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        
        //constructor 2
        Time (int hrs, int mins, int secs)
        {
            hours = hrs;
            minutes = mins;
            seconds = secs;
        }
        
        //method 1
        void display () const
        {
            cout << hours << ":" << minutes << ":" << seconds << endl;
        }
        
        //method 2
        Time add (Time t1, Time t2) const
        {
            Time tmp;
            tmp.hours = t1.hours + t2.hours;
            tmp.minutes = t1.minutes + t2.minutes;
            tmp.seconds = t1.seconds + t2.seconds;
            
            if (tmp.seconds > 60)
            {
                tmp.seconds -= 60;
                ++tmp.minutes;
            }
            
            if (tmp.minutes > 60)
            {
                tmp.minutes -= 60;
                ++tmp.hours;
            }
            
            if (tmp.hours > 12)
            tmp.hours -= 12;
            
            return tmp;
        }
    };

int main ()
{
    Time t1(11, 3, 27);
    Time t2(6, 13, 59);
    Time t3;
    
    t3 = t3.add(t1, t2);
    
    t3.display();
}