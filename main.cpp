#include <iostream>
#include <string>
#include "AI.h"
#include <ncurses.h>

//may increase depending on dialogue line length
#define ROW_MIN 12
#define COLUMN_MIN 20

int main()
{
    initscr();
    cbreak();

    //Clear screen in preparation
    clear();

    //not used yet, but could be used for more interesting effects later...
    bool Playing = true;

    char Input;

    AI TheAI = AI();

    int row, col;

    getmaxyx(stdscr, row, col);

    if (row <= ROW_MIN || col <= COLUMN_MIN)
    {
        endwin();
        std::cout << "Increase the size of the window";
        return 0;
    }

    row = 0;
    col = 0;

    //god knows why this has to be here
    scanw("%c", &Input);

    while (Playing)
    {
        move(0,0);

        if (!TheAI.AdvanceDialogue())
        {
            getch();
            break;
        }

        getyx(stdscr, row, col);

        move(row + 1,0);
        addstr("Select Response: ");
        scanw("%c", &Input);

        std::string InputString = std::string();

        InputString.push_back(Input);

        if (InputString == "e")
        {
            break;
        }

        while (!TheAI.EvaluateResponse(InputString))
        {
            getyx(stdscr, row, col);
            move(row + 1,0);
            addstr("YOU CANNOT ANSWER AS SUCH. PLEASE SELECT A VALID RESPONSE: ");
            scanw("%c", &Input);

            InputString[0] = Input;

            if (InputString == "e")
            {
                break;
            }
        }

        //have to check again
        if (InputString == "e")
        {
            break;
        }

        //clear screen for next loop
        clear();
    }

    endwin();
    return 0;
}