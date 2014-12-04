//
// tests.cpp -- functions for testing
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Game.h"

void testPuzzle(){
    std::cout << "Tests for Puzzle:" << std::endl;
    // testing IsDefault()
    std::cout << "0. testing IsDefault():" << std::endl;
    Puzzle myPuzzleNeg1(3,3);
    myPuzzleNeg1.Display();
    std::cout << std::endl << myPuzzleNeg1.IsDefault() << std::endl;
    myPuzzleNeg1.RandomSet();
    myPuzzleNeg1.Display();
    std::cout << std::endl << myPuzzleNeg1.IsDefault() << std::endl;
    int resetArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    myPuzzleNeg1.SetEntries(resetArray);
    myPuzzleNeg1.Display();
    std::cout << std::endl << myPuzzleNeg1.IsDefault() << std::endl;
    std::cin.ignore();

    // testing default constructor
    std::cout << "1. testing default constructor:" << std::endl;
    Puzzle myPuzzle0;
    myPuzzle0.Display();
    std::cin.ignore();

    // testing init constructor
    std::cout << "2. testing init constructor:" << std::endl;
    Puzzle myPuzzle1(3,5);
    myPuzzle1.Display();
    std::cin.ignore();

    // testing init constructor version 2
    std::cout << "3. testing init constructor versioin 2:" << std::endl;
    int thisArray[] = {2, 1, 7, 13, 12, 11, 16, 15, 3, 4, 5, 6, 8, 9, 10, 14, 17, 18, 19, 0, 20, 21, 22, 23};
    Puzzle myPuzzle2(4,6,thisArray);
    myPuzzle2.Display();
    std::cin.ignore();

    // testing copy constructor
    std::cout << "4. testing copy constructor:" << std::endl;
    Puzzle myPuzzle3 = myPuzzle2;
    myPuzzle3.Display();
    std::cin.ignore();

    // testing deep copy assignment operator and RandomSet()
    std::cout << "5. testing deep copy assignment operator:" << std::endl;
    myPuzzle3 = myPuzzle1;
    myPuzzle3.Display();
    myPuzzle3.RandomSet();
    myPuzzle3.Display();
    myPuzzle1.Display();
    std::cin.ignore();

    // testing GetNrow(), GetNcol(), GetVblank(), GetHblank()
    std::cout << "6. testing GetNrow(), GetNcol(), GetVblank(), GetHblank():" << std::endl;
    std::cout << "myPuzzle3.GetNrow() -- " << myPuzzle3.GetNrow() << std::endl;
    std::cout << "myPuzzle3.GetNcol() -- " << myPuzzle3.GetNcol() << std::endl;
    std::cout << "myPuzzle3.GetVblank() -- " << myPuzzle3.GetVblank() << std::endl;
    std::cout << "myPuzzle3.GetHblank() -- " << myPuzzle3.GetHblank() << std::endl;
    std::cin.ignore();

    // testing SetEntries()
    std::cout << "7. testing SetEntries():" << std::endl;
    Puzzle myPuzzle4(3,2);
    myPuzzle4.Display();
    int thatArray[] = {5, 0, 1, 4, 3, 2};
    myPuzzle4.SetEntries(thatArray);
    myPuzzle4.Display();
    std::cin.ignore();

    // testing Swap()
    std::cout << "8. testing Swap():" << std::endl;
    Puzzle myPuzzle6(6,6);
    myPuzzle6.RandomSet();
    myPuzzle6.Display();
    std::cin.ignore();
    myPuzzle6.Swap(BLANK_DOWN);
    myPuzzle6.Display();
    std::cin.ignore();
    myPuzzle6.Swap(BLANK_LEFT);
    myPuzzle6.Display();
    std::cin.ignore();
    myPuzzle6.Swap(BLANK_UP);
    myPuzzle6.Display();
    std::cin.ignore();
    myPuzzle6.Swap(BLANK_RIGHT);
    myPuzzle6.Display();
    std::cin.ignore();
    for(int i = 0; i < 6; i++){
        myPuzzle6.Swap(BLANK_RIGHT);
        myPuzzle6.Display();
        std::cin.ignore();
    }
    for(int i = 0; i < 6; i++){
        myPuzzle6.Swap(BLANK_DOWN);
        myPuzzle6.Display();
        std::cin.ignore();
    }
    for(int i = 0; i < 6; i++){
        myPuzzle6.Swap(BLANK_LEFT);
        myPuzzle6.Display();
        std::cin.ignore();
    }
    for(int i = 0; i < 6; i++){
        myPuzzle6.Swap(BLANK_UP);
        myPuzzle6.Display();
        std::cin.ignore();
    }

    // testing ByUser();
    std::cout << "9. testing ByUser():" << std::endl;
    Puzzle myPuzzle5;
    myPuzzle5.ByUser();
    myPuzzle5.Display();
    std::cout << std::endl;
    std::cin.ignore();
    Puzzle myPuzzle5b(3,3);
    myPuzzle5b.ByUser();
    myPuzzle5b.Display();
    std::cout << std::endl;
    std::cin.ignore();
    std::cin.get();

    // testing Puzzle::operator ==
    std::cout << "10. testing Puzzle::operator ==" << std::endl;
    Puzzle myPuzzle7(2,2);
    int tempArray1[] = {3,0,1,2};
    myPuzzle7.SetEntries(tempArray1);
    myPuzzle7.Display();

    Puzzle myPuzzle8(2,2);
    int tempArray2[] = {0,3,1,2};
    myPuzzle8.SetEntries(tempArray2);
    myPuzzle8.Display();

    std::cout << std::endl << (myPuzzle7 == myPuzzle8) << std::endl;

    myPuzzle7.Swap(BLANK_LEFT);
    std::cout << std::endl << (myPuzzle7 == myPuzzle8) << std::endl;


    // testing functions used in determining solvability
    std::cout << "11. testing functions used in determining solvability" << std::endl;
    // testing CountInversions
    Puzzle myPuzzle9(4,4);
    //int thatArray3[] = {8,13,1,4,2,14,0,5,3,12,10,7,11,6,9,15};
    //int thatArray3[] = {6,1,10,2,7,11,4,14,5,0,9,15,8,12,13,3};
    int thatArray3[] = {12,1,10,2,7,11,4,14,5,0,9,15,8,13,6,3};
    int temp;
    myPuzzle9.SetEntries(thatArray3);
    myPuzzle9.Display();
    temp = myPuzzle9.CountInversions(0, 0);
    std::cout << std::endl << temp << std::endl;
    // testing SumInversions
    temp = myPuzzle9.SumInversions();
    std::cout << std::endl << temp << std::endl;
    Puzzle myPuzzle10(4,4);
    //int thatArray4[] = {8,13,1,4,2,14,10,5,3,12,0,7,11,6,9,15};
    //int thatArray4[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,15,14,0};
    int thatArray4[] = {12,1,10,2,7,0,4,14,5,11,9,15,8,13,6,3};
    myPuzzle10.SetEntries(thatArray4);
    myPuzzle10.Display();
    temp = myPuzzle10.SumInversions();
    std::cout << std::endl << temp << std::endl;
    // testing IsSolvable
    bool temp2,temp3;
    temp2 = myPuzzle9.IsSolvable();
    std::cout << std::endl << temp2 << std::endl;
    temp3 = myPuzzle10.IsSolvable();
    std::cout << std::endl << temp3 << std::endl;
    Puzzle myPuzzle11;
    int thatArray5[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
    myPuzzle11.SetEntries(thatArray5);
    myPuzzle11.Display();
    std::cout << std::endl << myPuzzle11.IsSolvable() << std::endl;
    int thatArray6[] = {1,2,4,3,5,0,6,7,8,10,9,11,12,13,15,14};
    myPuzzle11.SetEntries(thatArray6);
    myPuzzle11.Display();
    std::cout << std::endl << myPuzzle11.IsSolvable() << std::endl;
    int thatArray7[] = {2,10,4,8,9,6,14,12,1,5,0,15,13,7,3,11};
    myPuzzle11.SetEntries(thatArray7);
    myPuzzle11.Display();
    std::cout << std::endl << myPuzzle11.IsSolvable() << std::endl;
    int thatArray8[] = {15,12,9,14,8,2,0,4,13,1,6,11,5,10,7,3};
    myPuzzle11.SetEntries(thatArray8);
    myPuzzle11.Display();
    std::cout << std::endl << myPuzzle11.IsSolvable() << std::endl;

    // testing Huristic()
    std::cout << std::endl << "testing Huristic()" << std::endl;
    Puzzle myPuzzle12;
    int thatArray12[] = {2,10,4,8,9,6,14,12,1,0,5,15,13,7,3,11};
    myPuzzle12.SetEntries(thatArray12);
    myPuzzle12.Display();
    std::cout << std::endl << myPuzzle12.Heuristic() << std::endl;

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

}


void testGame(){
    std::cout << "Tests for Game:" << std::endl;
    // testing constructors etc.
    std::cout << "0. testing constructors etc.:" << std::endl;
    Game firstGame(3,3);
    Game secondGame = firstGame;
    Game thirdGame(3,3);
    firstGame.Display();
    secondGame.Display();
    thirdGame.Display();
    Game fourthGame(3,3);
    secondGame = fourthGame;
    thirdGame = fourthGame;
    firstGame.Display();
    secondGame.Display();
    thirdGame.Display();
    thirdGame.Display();
    Game fifthGame;
    std::cout << std::endl << fifthGame.IsWin() << std::endl;

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

}

