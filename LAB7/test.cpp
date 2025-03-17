#include <iostream>
#include <ctime>

int main ()
{
   time_t now;
   
    char* dt = ctime(&now);

    std::cout << dt << std::endl;
}