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
    char choice;
    bool SwapSuccess;

    std::cout << "Move (w=up, a=left, s=down, d=right, 0=exit): ";
    std::cin >> choice;
    while(choice != '0')
    {
        switch(choice)
        {
        case 'w':
            SwapSuccess = CurrentPuzzle->Swap(BLANK_UP);
            break;
        case 'a':
            SwapSuccess = CurrentPuzzle->Swap(BLANK_LEFT);
            break;
        case 's':
            SwapSuccess = CurrentPuzzle->Swap(BLANK_DOWN);
            break;
        case 'd':
            SwapSuccess = CurrentPuzzle->Swap(BLANK_RIGHT);
            break;
        }
        if (SwapSuccess)
        {
            CurrentPuzzle->Display();
            switch(choice)
            {
            case 'w':
                MoveHistory.push_back(BLANK_UP);
                break;
            case 'a':
                MoveHistory.push_back(BLANK_LEFT);
                break;
            case 's':
                MoveHistory.push_back(BLANK_DOWN);
                break;
            case 'd':
                MoveHistory.push_back(BLANK_RIGHT);
                break;
            }
        }
        std::cout << "Move (w=up, a=left, s=down, d=right, 0=exit): ";
        std::cin >> choice;
    }

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
void Game::Undo(unsigned int numStep){
    if (numStep <= MoveHistory.size())
    {
        unsigned int LoopCount = 0;
        MoveDirect RevDirect;
        while (LoopCount < numStep)
        {
            RevDirect = MoveHistory.back();
            switch(RevDirect)
                {
                case BLANK_UP:
                    CurrentPuzzle->Swap(BLANK_DOWN);
                    break;
                case BLANK_DOWN:
                    CurrentPuzzle->Swap(BLANK_UP);
                    break;
                case BLANK_LEFT:
                    CurrentPuzzle->Swap(BLANK_RIGHT);
                    break;
                case BLANK_RIGHT:
                    CurrentPuzzle->Swap(BLANK_LEFT);
                    break;
                }
            CurrentPuzzle->Display();
            MoveHistory.pop_back();
            LoopCount++;
        }
    } else {
        std::cout << "Invalid undo, can only undo up to " << MoveHistory.size() << "moves" << std::endl;
    }

}

//// solve it by computer
//// let's all think about it
//Game SolveIt() const{}

// display info for the Game
// tonname please test
void Game::Display() const{
    std::cout << std::endl << "GameID:    " << GameID << std::endl;
    std::cout << std::endl << "InitialPuzzle:" << std::endl;
    InitialPuzzle -> Display();
    std::cout << std::endl << "MoveHistory (U=up,D=down,L=left,R=right):";
    if(MoveHistory.size() == 0) std::cout << "  None.";
    for(unsigned int i = 0; i < MoveHistory.size(); i++){
        switch(MoveHistory[i])
        {
        case BLANK_DOWN:
            std::cout << 'D';
            break;
        case BLANK_LEFT:
            std::cout << 'L';
            break;
        case BLANK_RIGHT:
            std::cout << 'R';
            break;
        case BLANK_UP:
            std::cout << 'U';
            break;
        }
        //std::cout << MoveHistory[i];
    }
    std::cout << std::endl;
    std::cout << std::endl << "CurrentPuzzle:" << std::endl;
    CurrentPuzzle -> Display();
}
