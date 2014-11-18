//
// main.cpp -- entry point for testing GemPuzzle project
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Puzzle.h"
#include "tests.h"

using namespace std;

int main()
{
    //testPuzzle();

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

    return 0;
}
