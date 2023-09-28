//
// Created by ruby on 9/28/23.
//

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