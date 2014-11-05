//
// main.cpp -- entry point for testing GemPuzzle project
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Puzzle.h"

using namespace std;

int main()
{
    Puzzle myPuzzle0(4, 4);
    Puzzle myPuzzle1 = myPuzzle0;
    Puzzle myPuzzle;
    myPuzzle = myPuzzle1;
    myPuzzle.Display();
    cin.ignore();

    int thisArray[] = {2, 1, 7, 13, 12, 11, 16, 15, 3, 4, 5, 6, 8, 9, 10, 14};
    myPuzzle.SetEntries(thisArray);
    myPuzzle.Display();
    cin.ignore();

    myPuzzle.Swap(BLANK_DOWN);
    myPuzzle.Display();
    cin.ignore();
    myPuzzle.Swap(BLANK_LEFT);
    myPuzzle.Display();
    cin.ignore();
    myPuzzle.Swap(BLANK_UP);
    myPuzzle.Display();
    cin.ignore();
    myPuzzle.Swap(BLANK_RIGHT);
    myPuzzle.Display();
    cin.ignore();
    myPuzzle.Swap(BLANK_RIGHT);
    myPuzzle.Display();
    cin.ignore();
    myPuzzle.Swap(BLANK_RIGHT);
    myPuzzle.Display();
    cin.ignore();
    myPuzzle.Swap(BLANK_RIGHT);
    myPuzzle.Display();
    cin.ignore();

    myPuzzle0.Display();
    cin.ignore();

    myPuzzle0.RandomSet();
    myPuzzle0.Display();


    return 0;
}
