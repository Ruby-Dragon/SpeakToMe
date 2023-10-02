//
// Created by ruby on 9/28/23.
//

#ifndef SPEAKTOME_AI_H
#define SPEAKTOME_AI_H

#include "Dialogue.h"

class AI {

private:

    float Friendliness = 0.5;

public:

    AI();

    Dialogue CurrentDialogue;

    void AdvanceDialogue();

    void InitializeDialogue();

    bool EvaluateResponse(std::string Input);

};


#endif //SPEAKTOME_AI_H
