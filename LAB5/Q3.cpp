#include <iostream>

class ValidateString
{
    std::string input_string;

    public:
    ValidateString (std::string input_string) : input_string(input_string) {}

    //we make a function const when we do not want it to modify any members of the class that it is contained in
    //in this case, we set it const because we do not want it to modify input_string, only validate it
    int validate () const
    {
        for (int i = 0; input_string[i] != '\0'; i++)
        {
            if (input_string[i] < 'A' || (input_string[i] > 'Z' && input_string[i] < 'a') || input_string[i] > 'z')
            return 0;
        }

        return 1;
    }
};

int main ()
{
    std::string input;

    std::cout << "Input String: ";
    std::cin >> input;

    ValidateString to_validate(input);

    if (!to_validate.validate())
        std::cout << "NOT VALID" << std::endl;

        else
        std::cout << "VALID" << std::endl;
}

