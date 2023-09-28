#include <iostream>
#include <string>

int main()
{
    bool Playing = true;

    std::string Input;

    while (Playing)
    {
        std::cin >> Input;

        if (Input == "e")
        {
            Playing = false;
        }
    }

    return 0;
}