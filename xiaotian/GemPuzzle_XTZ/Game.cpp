//
// Game.cpp - Game class implementation
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Game.h"

// default & init constructor
// xiaotian
Game::Game(){}

//// init constructor version 2
// xiaotian
//Game();

// copy constructor
// xiaotian
Game::Game(const Game& source){}

// destructor
// xiaotian
Game::~Game(){}

// deep copy assignment operator
// xiaotian
Game& Game::operator = (const Game& source);

// get GameNumber
// xiaotian
int Game::GetGameNumber() const;

// get MyPuzzle
// xiaotian
//...

// get MoveHistory
// xiaotian
// ...

// get CurrentPosition
// xiaotian
// ...

// let user play the game
// tonnam
void MoveInterface(){
    int choice;
    // a menu to let the user choose moving the blank
    // up, down, right, or left
    // or exit
    while(choice != 0){
            // call swap function

            // if swap returns ture
            // update the MoveHistory
            // update CurrentPuzzle
            // check if the Puzzle has been solved

            // a menu to let the user choose moving the blank
            // up, down, right, or left
            // or exit
    }
}

// decide if user wins already
// chengping
bool IsWin() const{
    return
        CurrentPuzzle.IsDefault();
}

// return puzzle configuration at position in history
// chengping
Puzzle Trace(int postion) const{}

// undo this numStep # of steps
// tonname
void Undo(int numStep){}

// solve it by computer
// let's all think about it
Game SolveIt() const;

// display info for the Game
// tonname
void Display() const;
