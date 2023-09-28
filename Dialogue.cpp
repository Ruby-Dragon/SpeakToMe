#include <iostream>
#include "Dialogue.h"

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

    NewDialogue.emplace_back("Hello World!");

    return NewDialogue;
}

void Dialogue::Print()
{
    for (int i = 0; i < Text.size(); i++)
    {
        std::cout << Text[i] << std::endl;
    }
}