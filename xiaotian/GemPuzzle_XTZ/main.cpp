//
// main.cpp -- entry point for testing GemPuzzle project
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Puzzle.h"
#include "Game.h"
#include "PuzzleSearchNode.h"
#include "tests.h"
#include <time.h>


using namespace std;

int main()
{
    try{
        //testPuzzle();

        //testGame();

        /*Puzzle myPuzzle13;
        int thatArray[]={14,9,4,3,10,7,15,2,1,0,13,12,5,11,8,6};
        myPuzzle13.SetEntries(thatArray);
        myPuzzle13.Display();
        PuzzleSearchNode myPuzzleSearchNode1(myPuzzle13,0);
        myPuzzleSearchNode1.PuzzleToSolve.Display();
        std::cout << std::endl << myPuzzleSearchNode1.G << " " << myPuzzleSearchNode1.H << " " << myPuzzleSearchNode1.F << std::endl;
        Game myGame1;
        myGame1.GetCurrentPuzzle() -> SetEntries(thatArray);
        myGame1.Display();
        PuzzleSearchNode Root(*(myGame1.GetCurrentPuzzle()), 0);
        std::cout << std::endl << Root.G << " " << Root.H << " " << Root.F << std::endl;
        Root.PuzzleToSolve.RandomSet();
        myGame1.Display();
        Root.PuzzleToSolve.Display();
        std::cout << std::endl << Root.G << " " << Root.H << " " << Root.F << std::endl;
        Root.CalcHF();
        std::cout << std::endl << Root.G << " " << Root.H << " " << Root.F << std::endl;*/

        Puzzle myPuzzle14(3,3);
        int thatArray14[] = {3,4,6,1,8,5,7,0,2};
        myPuzzle14.SetEntries(thatArray14);
        myPuzzle14.Display();
        std::cout << std::endl << myPuzzle14.IsSolvable() << std::endl;
        Game myGame14(3,3);
        myGame14.GetInitialPuzzle() -> SetEntries(thatArray14);
        myGame14.GetCurrentPuzzle() -> SetEntries(thatArray14);
        myGame14.Display();
        myGame14.SolveIt();
        myGame14.Display();

    }catch(...){
        std::cout << std::endl << "Oops, program ended due to error! Plz try again!" << std::endl;
    }

    return 0;
}
