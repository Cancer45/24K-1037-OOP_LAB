#include <iostream>
#include <fstream>
#include <string>

int main ()
{
    std::string word;

    std::ifstream user_resume_in("resume.txt", std::ios::in);

    while (user_resume_in >> word)
    {
        std::cout << word << std::endl;
    }

    user_resume_in.close();
    
    std::string name, email, summary;
    int years_of_experience;

    std::cout << "Name: ";
    std::cin >> name;

    std::cout << "Email: ";
    std::cin >> email;

    std::cout << "Summary: ";
    std::getline(std::cin, summary);

    std::cin.ignore();
    std::cout << "Experience (Years): ";
    std::cin >> years_of_experience;

    std::ofstream user_resume_trunc("resume.txt", std::ios::trunc);

    user_resume_trunc << name;
    user_resume_trunc << "\n";

    user_resume_trunc << email;
    user_resume_trunc << "\n";

    user_resume_trunc << summary;
    user_resume_trunc << "\n";

    user_resume_trunc << years_of_experience;
    user_resume_trunc << "\n";

    user_resume_trunc.close();
}