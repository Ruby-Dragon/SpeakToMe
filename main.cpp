#include <iostream>
#include <string>
#include "AI.h"

int main()
{
    bool Playing = true;

    std::string Input;

    AI TheAI = AI();
    TheAI.InitializeDialogue();

    while (Playing)
    {

        TheAI.AdvanceDialogue();

        std::cin >> Input;

        if (Input == "e")
        {
            Playing = false;
        }
    }

    return 0;
}