//
// testPuzzle.cpp -- function definition for testing the class Puzzle
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Puzzle.h"

void testPuzzle(){
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
    int thisArray[] = {2, 1, 7, 13, 12, 11, 16, 15, 3, 4, 5, 6, 8, 9, 10, 14, 17, 18, 19, 24, 20, 21, 22, 23};
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
    int thatArray[] = {5, 6, 1, 4, 3, 2};
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

    // testing Puzzle::operator ==
    std::cout << "10. testing Puzzle::operator ==" << std::endl;
    Puzzle myPuzzle7(2,2);
    int tempArray1[] = {3,4,1,2};
    myPuzzle7.SetEntries(tempArray1);
    myPuzzle7.Display();

    Puzzle myPuzzle8(2,2);
    int tempArray2[] = {4,3,1,2};
    myPuzzle8.SetEntries(tempArray2);
    myPuzzle8.Display();

    std::cout << std::endl << (myPuzzle7 == myPuzzle8) << std::endl;

    myPuzzle7.Swap(BLANK_LEFT);
    std::cout << std::endl << (myPuzzle7 == myPuzzle8) << std::endl;


}
