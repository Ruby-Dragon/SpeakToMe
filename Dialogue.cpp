#include <iostream>
#include <fstream>
#include "Dialogue.h"

#define DIALOGUE_INDICATOR "[DIALOGUE]"
#define ANSWER_INDICATOR "[ANSWER]"

Dialogue::Dialogue()
{
    ID = 0;
    Text = LoadDialogue();
}

Dialogue::Dialogue(int ID)
{
    this->ID = ID;
    Text = LoadDialogue();
}

std::vector<std::string> Dialogue::LoadDialogue()
{
    std::vector<std::string> NewDialogue = std::vector<std::string>();

    std::ifstream DialogueFile ("Dialogue/dialogue_" + std::to_string(ID) + ".dat", std::ios::in);

    std::string Line;

    while (getline(DialogueFile, Line))
    {
        //std::cout << "Reading" << std::endl;
        if (Line == DIALOGUE_INDICATOR)
        {
            continue; //for now
        }

        if (Line == ANSWER_INDICATOR)
        {
            break; //for now
        }

        NewDialogue.push_back(Line);
    }

    return NewDialogue;
}

void Dialogue::Print()
{
    for (int i = 0; i < Text.size(); i++)
    {
        std::cout << Text[i] << std::endl;
    }
}