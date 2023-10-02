//
// Created by ruby on 9/28/23.
//

#ifndef SPEAKTOME_ANSWER_H
#define SPEAKTOME_ANSWER_H

#define ASCII_A 97

#include <string>

class Answer {

public:

    Answer();
    Answer(std::string Text, int ID, float Impact);

    std::string ToString();

    std::string Text;
    float Impact = 0.0f;
    int ID = 0;
};


#endif //SPEAKTOME_ANSWER_H
