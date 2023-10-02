#include <iostream>
#include <string>
#include "AI.h"

int main()
{
    //not used yet, but could be used for more interesting effects later...
    bool Playing = true;

    std::string Input;

    AI TheAI = AI();

    while (Playing)
    {

        TheAI.AdvanceDialogue();

        std::cout << "Select Response: ";
        std::cin >> Input;

        if (Input == "e")
        {
            break;
        }

        while (!TheAI.EvaluateResponse(Input))
        {
            std::cout << "YOU CANNOT ANSWER AS SUCH. PLEASE SELECT A VALID RESPONSE: ";
            std::cin >> Input;
        }

    }

    return 0;
}