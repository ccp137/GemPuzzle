//
// main.cpp -- entry point for testing GemPuzzle project
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Game.h"
#include "tests.h"
#include <time.h>
#include "menu.h"


using namespace std;

int main()
{
    try{

        welcomeMenu();

        mainMenu();

        /*Puzzle myPuzzle14(3,3);
    int thatArray14[] = {4,0,5,8,3,2,1,6,7};
    myPuzzle14.SetEntries(thatArray14);
    myPuzzle14.Display();
    std::cout << std::endl << myPuzzle14.IsSolvable() << std::endl;
    Game myGame14(3,3);
    myGame14.GetInitialPuzzle() -> SetEntries(thatArray14);
    myGame14.GetCurrentPuzzle() -> SetEntries(thatArray14);
    myGame14.Display();
    myGame14.SolveIt();
    myGame14.Display();*/

        //testPuzzle();

        //testGame();

    }catch(...){
        std::cout << std::endl << "Oops, program ended due to error! Plz try again!" << std::endl;
    }

    return 0;
}
