#include <iostream>
#include <string>
#include "AI.h"
#include <ncurses.h>

//may increase depending on dialogue line length
#define ROW_MIN 12
#define COLUMN_MIN 20

#define EXIT_GAME "e"
#define TERMINAL_SYMBOL "~ "

void PrintTitleScreen()
{
    int row, col;
    getyx(stdscr, row, col);

    //quite jank, may make a function to move cursor to next line
    move(row, 0);
    addstr("Speak To Me");
    move(row+1, 0);
    addstr("Type \"a\" to Start");
    move(row+2, 0);
    addstr("Type \"b\" for Tutorial");
    move (row+3, 0);
    addstr(TERMINAL_SYMBOL);
}

void Tutorial(char Input)
{
    //if the user exited on the title screen
    if (Input == 'e')
    {
        endwin();
        exit(0);
    }
    if (Input != 'b')
    {
        return;
    }

    clear();

    int row, col;
    move(0,0);
    getyx(stdscr, row, col);

    char Answer;

    addstr("This game is played by reading dialogue, and picking a response.");
    move(row+1, row);
    addstr("You will be conversing with an... intelligence. Remember, it has feelings too!");
    move(row+2, row);
    addstr("There will be responses labeled with letters, type the letter of the response you would like to say! Responding with \"e\" will exit the game.");
    move(row+3, row);
    addstr("Do you understand?");
    move(row+4, row);
    addstr("a. Yes!");
    move(row+5, row);
    addstr("b. No!");
    move(row+6, row);
    addstr(TERMINAL_SYMBOL);
    scanw("%c", &Answer);

    if (Answer == 'a')
    {
        return;
    }
    if (Answer == 'e')
    {
        endwin();
        exit(0);
    }

    clear();
    move(0,0);
    addstr("Well that is too bad, the game will begin anyway once you press any key.");
    getch();
}

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
        std::cout << "Please increase the size of the terminal in order to play.";
        return 0;
    }

    row = 0;
    col = 0;

    //god knows why this has to be here
    scanw("%c", &Input);

    PrintTitleScreen();
    scanw("%c", &Input);
    Tutorial(Input);

    clear();

    while (Playing)
    {
        move(0,0);

        if (!TheAI.AdvanceDialogue())
        {
            getyx(stdscr, row, col);
            move(row + 1,0);
            addstr("Press any key to exit.");
            getch();
            break;
        }

        getyx(stdscr, row, col);

        move(row + 1,0);
        addstr(TERMINAL_SYMBOL);
        scanw("%c", &Input);

        std::string InputString = std::string();

        InputString.push_back(Input);

        if (InputString == EXIT_GAME)
        {
            break;
        }

        while (!TheAI.EvaluateResponse(InputString))
        {
            getyx(stdscr, row, col);
            move(row + 1,0);
            addstr("Please enter a valid option.");
            getyx(stdscr, row, col);
            move(row + 1,0);
            addstr(TERMINAL_SYMBOL);
            scanw("%c", &Input);

            InputString[0] = Input;

            if (InputString == EXIT_GAME)
            {
                break;
            }
        }

        //have to check again
        if (InputString == EXIT_GAME)
        {
            break;
        }

        //clear screen for next loop
        clear();
    }

    endwin();
    return 0;
}