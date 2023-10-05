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
#include <fstream>

#include "Dialogue.h"
#include <ncurses.h>

#define DIALOGUE_INDICATOR "[DIALOGUE]"
#define ANSWER_INDICATOR "[ANSWER]"

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
        if (Line == DIALOGUE_INDICATOR)
        {
            continue; //for now
        }

        if (Line == ANSWER_INDICATOR)
        {
            SinceAnswerTag = 0;
            AnswerIndex = AnswerIndex + 1;
            PossibleAnswers.push_back(Answer());
            continue;
        }

        if (AnswerIndex == -1)
        {
            Text.push_back(Line);
        }
        else
        {

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
                case 4:
                    PossibleAnswers[AnswerIndex].RequiredFriendliness = std::stof(Line);
                default:
                    break;
            }
        }
    }
}

void Dialogue::Print()
{
    int row, col;

    for (int i = 0; i < Text.size(); i++)
    {
        getyx(stdscr, row, col);
        move(row+1, 0);
        printw("%s", Text[i].c_str());
    }

    //start at a
    int character = ASCII_A;

    for (int i = 0; i < PossibleAnswers.size(); i++)
    {
        getyx(stdscr, row, col);
        move(row+1, 0);
        printw("%c. %s", (char) character, PossibleAnswers[i].ToString().c_str());
        //go through alphabet for each answer
        character++;
    }
}