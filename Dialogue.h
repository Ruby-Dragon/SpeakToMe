//
// Created by ruby on 9/28/23.
//

#ifndef SPEAKTOME_DIALOGUE_H
#define SPEAKTOME_DIALOGUE_H

#include <string>
#include <vector>
#include "Answer.h"

class Dialogue {

private:

    void LoadDialogue();

public:

    Dialogue();

    explicit Dialogue(int ID);

    void Print();

    int ID;

    std::vector<std::string> Text;

    std::vector<Answer> PossibleAnswers;
};


#endif //SPEAKTOME_DIALOGUE_H
