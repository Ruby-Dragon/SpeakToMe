//
// Created by ruby on 9/28/23.
//

#include "Answer.h"

Answer::Answer()
{
    Text = "";
    ID = 0;
    Impact = 0.0f;
}

Answer::Answer(std::string Text, int ID, float Impact)
{
    this->Text = Text;
    this->ID = ID;
    this->Impact = Impact;
}

std::string Answer::ToString()
{
    return Text;
}