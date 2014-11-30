//
// Game.cpp - Game class implementation
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Game.h"
#include <limits>

int Game::TotalNumber=0; // initialization of Game::TotalNumber
int Game::EverCreated=0; // initialization of Game::EverCreated

// default & init constructor
// xiaotian
Game::Game(int nrow, int ncol){
    TotalNumber += 1;
    EverCreated += 1;
    GameID = 10000+EverCreated;
    InitialPuzzle = new Puzzle(nrow, ncol);
    CurrentPuzzle = new Puzzle(nrow, ncol);
    int choice;
    for(;;){
        std::cout << std::endl << "Initialize Game: 1. Sorted; 2. Randomly; 3. By User." << std::endl;
        if (std::cin >> choice && choice > 0 && choice < 4) {
            break;
        } else {
            std::cout << std::endl << "Please enter 1, 2 or 3" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    switch(choice){
        case 1:
            break;
        case 2:
            InitialPuzzle -> RandomSet();
            break;
        case 3:
            InitialPuzzle -> ByUser();
            break;
        default:;
    }
    *CurrentPuzzle = *InitialPuzzle;
}

// copy constructor
// xiaotian
Game::Game(const Game& source){
        InitialPuzzle = NULL;
        CurrentPuzzle = NULL;

    // Calls the assignment operator
    GameID = source.GetGameID();
	*this = source;
}

// destructor
// xiaotian
Game::~Game(){
    delete InitialPuzzle;
    InitialPuzzle = NULL;

    delete CurrentPuzzle;
    CurrentPuzzle = NULL;

    TotalNumber -= 1;
}

// deep copy assignment operator
// xiaotian
Game& Game::operator = (const Game& source){

    // first we have to dispose previously allocated memory
    if(InitialPuzzle != NULL){
        delete InitialPuzzle;
        InitialPuzzle = NULL;
    }

    if(CurrentPuzzle != NULL){
        delete CurrentPuzzle;
        CurrentPuzzle = NULL;
    }

    // copy fields
    MoveHistory = source.GetMoveHistory();

    // allocate new memory
    InitialPuzzle = new Puzzle;
    CurrentPuzzle = new Puzzle;

    // deep copy
    *InitialPuzzle = *(source.GetInitialPuzzle());
    *CurrentPuzzle = *(source.GetCurrentPuzzle());

    return
            *this;
}

// get GameID
// xiaotian
int Game::GetGameID() const{ return GameID;}

// get InitialPuzzle
// xiaotian
Puzzle* Game::GetInitialPuzzle() const{ return InitialPuzzle;}

// get CurrentPuzzle
// xiaotian
Puzzle* Game::GetCurrentPuzzle() const{ return CurrentPuzzle;}

// get TotalNumber
int Game::GetTotalNumber() const {return TotalNumber;}

// get EverCreated
int Game::GetEverCreated() const {return EverCreated;}

// get MoveHistory
// xiaotian
std::vector<MoveDirect> Game::GetMoveHistory() const{ return MoveHistory;}

// let user play the game
// tonnam
void Game::MoveInterface(){
//    int choice;
//    // a menu to let the user choose moving the blank
//    // up, down, right, or left
//    // or exit
//    while(choice != 0){
//            // call swap function
//
//            // if swap returns ture
//            // update the MoveHistory
//            // update CurrentPuzzle
//            // check if the Puzzle has been solved
//
//            // a menu to let the user choose moving the blank
//            // up, down, right, or left
//            // or exit
//    }
}

// decide if user wins already
// chengping please test
bool Game::IsWin() const{
    return
        CurrentPuzzle -> IsDefault();
}

//// return puzzle configuration at position in history
//// chengping
//Puzzle Game::Trace(int postion) const{}

//// undo this numStep # of steps
//// tonname
//void Game::Undo(int numStep){}

// solve it by computer
// let's all think about it
void Game::SolveIt() {

}

// display info for the Game
// tonname please test
void Game::Display() const{
    std::cout << std::endl << "GameID:    " << GameID << std::endl;
    std::cout << std::endl << "InitialPuzzle:" << std::endl;
    InitialPuzzle -> Display();
    std::cout << std::endl << "MoveHistory:";
    if(MoveHistory.size() == 0) std::cout << "  None.";
    for(int i = 0; i < MoveHistory.size(); i++){
        std::cout << MoveHistory[i];
    }
    std::cout << std::endl;
    std::cout << std::endl << "CurrentPuzzle:" << std::endl;
    CurrentPuzzle -> Display();
}
