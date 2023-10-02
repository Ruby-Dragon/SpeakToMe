//
// Created by ruby on 9/28/23.
//

#include <iostream>
#include "AI.h"

AI::AI()
{
    InitializeDialogue();
}

void AI::AdvanceDialogue()
{
    
    CurrentDialogue.Print();
}

void AI::InitializeDialogue()
{
    CurrentDialogue = Dialogue(0);
}

bool AI::EvaluateResponse(std::string Input)
{
    int InputValue = (int) Input.front();
    //std::cout << InputValue;

    if (InputValue >= ASCII_A && InputValue < (ASCII_A + CurrentDialogue.PossibleAnswers.size()))
    {
        //std::cout << CurrentDialogue.PossibleAnswers[InputValue - ASCII_A].Text << std::endl;
        Friendliness += CurrentDialogue.PossibleAnswers[InputValue - ASCII_A].Impact;
        CurrentDialogue = Dialogue(CurrentDialogue.PossibleAnswers[InputValue - ASCII_A].ID);
    }
    else
    {
        return false;
    }

    //std::cout << Friendliness << std::endl;

    return true;
}