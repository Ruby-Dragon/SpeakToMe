/*

Copyright 2023, Ruby-Dragon

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
 files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy,
 modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
 is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */

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