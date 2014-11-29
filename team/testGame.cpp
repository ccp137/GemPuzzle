//
// testGame.cpp -- function definition for testing the class Game
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Game.h"

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

}
