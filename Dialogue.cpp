#include <iostream>
#include <fstream>
#include "Dialogue.h"

#define DIALOGUE_INDICATOR "[DIALOGUE]"
#define ANSWER_INDICATOR "[ANSWER]"
#define ASCII_A 97

Dialogue::Dialogue()
{
    ID = 0;
    LoadDialogue();
}

Dialogue::Dialogue(int ID)
{
    this->ID = ID;
    LoadDialogue();
}

void Dialogue::LoadDialogue()
{
    Text = std::vector<std::string>();

    std::ifstream DialogueFile ("Dialogue/dialogue_" + std::to_string(ID) + ".dat", std::ios::in);

    std::string Line;

    int AnswerIndex = -1;
    int SinceAnswerTag = 0;

    while (getline(DialogueFile, Line))
    {
        SinceAnswerTag += 1;
        //std::cout << "Reading" << std::endl;
        if (Line == DIALOGUE_INDICATOR)
        {
            continue; //for now
        }

        if (Line == ANSWER_INDICATOR)
        {
            //std::cout << "hit!" << std::endl;
            SinceAnswerTag = 0;
            AnswerIndex = AnswerIndex + 1;
            PossibleAnswers.push_back(Answer());
            continue;
        }

        //std::cout << AnswerIndex << std::endl;
        if (AnswerIndex == -1)
        {
            Text.push_back(Line);
        }
        else
        {
            //std::cout << Line << " " << SinceAnswerTag << "\n";
            switch (SinceAnswerTag)
            {
                case 1:
                    PossibleAnswers[AnswerIndex].Text = Line;
                    break;
                case 2:
                    PossibleAnswers[AnswerIndex].ID = std::stoi(Line);
                    break;
                case 3:
                    PossibleAnswers[AnswerIndex].Impact = std::stof(Line);
                    break;
                default:
                    break;
            }
        }
    }


}

void Dialogue::Print()
{
    for (int i = 0; i < Text.size(); i++)
    {
        std::cout << Text[i] << std::endl;
    }

    std::cout << "\n";

    //start at a
    int character = ASCII_A;

    for (int i = 0; i < PossibleAnswers.size(); i++)
    {
        std::cout << (char) character << ". " << PossibleAnswers[i].ToString() << std::endl;
        //go through alphabet for each answer
        character++;
    }
}