//
// testMoveGame.cpp -- Game::MoveInterface()
//
// Written by Tonnam Balankura
//

#include <iostream>
#include "Game.h"

void testMoveGame(){
    std::cout << "Tests for MoveInterface():" << std::endl;
    Game firstGame(3,3);
    firstGame.Display();
    firstGame.MoveInterface();
    firstGame.Display();
    std::cout << "Undo by 1 move" << std::endl;
    firstGame.Undo(1);
    firstGame.Display();
    std::cout << "Undo by 2 moves" << std::endl;
    firstGame.Undo(2);
    firstGame.Display();
    std::cout << "Undo by 10 moves (beyond MoveHistory)" << std::endl;
    firstGame.Undo(10);
    firstGame.Display();
}
