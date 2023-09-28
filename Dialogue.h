//
// Created by ruby on 9/28/23.
//

#ifndef SPEAKTOME_DIALOGUE_H
#define SPEAKTOME_DIALOGUE_H

#include <string>
#include <vector>

class Dialogue {

private:

    std::vector<std::string> LoadDialogue();

public:

    Dialogue();

    explicit Dialogue(int ID);

    void Print();

    int ID;

    std::vector<std::string> Text;
};


#endif //SPEAKTOME_DIALOGUE_H
