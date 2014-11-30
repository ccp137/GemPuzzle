//
// main.cpp -- entry point for testing GemPuzzle project
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Puzzle.h"
#include "Game.h"
#include "tests.h"
#include <time.h>

using namespace std;

int main()
{
    try{
        //testPuzzle();

        //testGame();

        Puzzle myPuzzle11;
        int thatArray7[] = {2,10,4,8,9,6,14,12,1,5,0,15,13,7,3,11};
        myPuzzle11.SetEntries(thatArray7);
        myPuzzle11.Display();
        std::cout << std::endl << myPuzzle11.IsSovable() << std::endl;
        int thatArray8[] = {15,12,9,14,8,2,0,4,13,1,6,11,5,10,7,3};
        myPuzzle11.SetEntries(thatArray8);
        myPuzzle11.Display();
        std::cout << std::endl << myPuzzle11.IsSovable() << std::endl;

    }catch(...){
        std::cout << std::endl << "Oops, program ended due to error! Plz try again!" << std::endl;
    }

    return 0;
}
