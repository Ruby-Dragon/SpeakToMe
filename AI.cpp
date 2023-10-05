//
// Created by ruby on 9/28/23.
//

#include <iostream>
#include "AI.h"

#define FRIENDLINESS_THRESHOLD 0.0

#define END_GAME_ID 666

AI::AI()
{
    InitializeDialogue();
}

bool AI::AdvanceDialogue()
{
    FilterResponses();
    CurrentDialogue.Print();

    if (CurrentDialogue.ID == END_GAME_ID)
    {
        return false;
    }
    return true;
}

void AI::InitializeDialogue()
{
    CurrentDialogue = Dialogue(0);
}

bool AI::EvaluateResponse(std::string Input)
{
    int InputValue = (int) Input.front();

    if (InputValue >= ASCII_A && InputValue < (ASCII_A + CurrentDialogue.PossibleAnswers.size()))
    {
        Friendliness += CurrentDialogue.PossibleAnswers[InputValue - ASCII_A].Impact;

        if (Friendliness <= FRIENDLINESS_THRESHOLD)
        {
            CurrentDialogue = Dialogue(END_GAME_ID);
            return true;
        }

        CurrentDialogue = Dialogue(CurrentDialogue.PossibleAnswers[InputValue - ASCII_A].ID);
    }
    else
    {
        return false;
    }

    return true;
}

void AI::FilterResponses()
{
    std::vector<Answer> NewList = std::vector<Answer>();
    for (int i = 0; i < CurrentDialogue.PossibleAnswers.size(); i++)
    {
        if (CurrentDialogue.PossibleAnswers[i].RequiredFriendliness <= Friendliness)
        {
            NewList.push_back(CurrentDialogue.PossibleAnswers[i]);
        }
    }

    CurrentDialogue.PossibleAnswers = NewList;
}