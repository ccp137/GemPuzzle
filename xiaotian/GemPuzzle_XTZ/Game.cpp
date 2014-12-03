//
// Game.cpp - Game class implementation
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Game.h"
#include "PuzzleSearchNode.h"
#include <limits>

#define FOUND -100
#define NOTFOUND -200
#define MAXBOUND std::numeric_limits<int>::max()

int Game::TotalNumber=0; // initialization of Game::TotalNumber
int Game::EverCreated=0; // initialization of Game::EverCreated

// Global output for enum MoveDirect
void DisplayMoveDirect(MoveDirect myMove)
{
	switch(myMove){
        case BLANK_UP:
            std::cout << "U ";
            break;
        case BLANK_DOWN:
            std::cout << "D ";
            break;
        case BLANK_LEFT:
            std::cout << "L ";
            break;
        case BLANK_RIGHT:
            std::cout << "R ";
            break;
        default:;
	}

}

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


// search function for IDA*
int Game::Search(PuzzleSearchNode& thisNode, int boundValue, PuzzleSearchNode& leafNode){
    if(thisNode.F > boundValue){
        return thisNode.F;
    }
    if(thisNode.PuzzleToSolve.IsDefault()){
        leafNode = thisNode;

        //need to backtrack here!
        std::vector<MoveDirect> tempHistory;
        while(thisNode.Parent != NULL){
            tempHistory.push_back(thisNode.GetHere);
            thisNode = *(thisNode.Parent);
        }
        std::vector<MoveDirect>::reverse_iterator rit = tempHistory.rbegin();
        for (; rit!= tempHistory.rend(); ++rit) MoveHistory.push_back(*rit);

        return FOUND;
    }
    int minBound = MAXBOUND, redundant = 0;
    MoveDirect aMove;
    for(redundant = 0 ; redundant < 4; redundant++)
    {
        aMove = MoveDirect(redundant);
        Puzzle copyThisPuzzle = thisNode.PuzzleToSolve;
        if(copyThisPuzzle.Swap(aMove)){
            PuzzleSearchNode nextNode(copyThisPuzzle, thisNode.G+1);
            nextNode.Parent = &thisNode;
            nextNode.GetHere = aMove;
            int thisT = Search(nextNode, boundValue, leafNode);
            if (thisT == FOUND){
                return FOUND;
            }
            if (thisT < minBound){
                minBound = thisT;
            }
        }
    }
    return minBound;
}

// solve it by computer
// let's all think about it
int Game::SolveIt() {
    PuzzleSearchNode root(*CurrentPuzzle, 0);
    PuzzleSearchNode leaf = root;
    int bound = root.H;
    int t;
    while(true){
        t = Search(root, bound, leaf);
        if(t == FOUND) {
            *CurrentPuzzle = leaf.PuzzleToSolve;
            // also will need to backtrack(where?) to get the steps
            // later ...
            return FOUND;
        }
        if(t == MAXBOUND) return NOTFOUND;
        bound = t;
    }
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
        DisplayMoveDirect(MoveHistory[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl << "CurrentPuzzle:" << std::endl;
    CurrentPuzzle -> Display();
}
