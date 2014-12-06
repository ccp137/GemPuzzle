//
// Game.cpp - Game class implementation
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Game.h"
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
            std::cout << " D";
            break;
        case BLANK_DOWN:
            std::cout << " U";
            break;
        case BLANK_LEFT:
            std::cout << " R";
            break;
        case BLANK_RIGHT:
            std::cout << " L";
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

// push to MoveHistory
void Game::PushToHistory(MoveDirect step){
    MoveHistory.push_back(step);
}

// let user play the game
void Game::MoveInterface(){
    bool exit = false;
    char choice;
    while(!exit){
        std::cout << std::endl << "Play Menu:";
        std::cout << std::endl << "A. Left; W. Up; S. Down; D. Right; F. Game Menu." << std::endl;

        for(;;){
            if (std::cin >> choice && (choice == 'A' || choice == 'W' || choice == 'S' || choice == 'D' || choice == 'F'|| choice == 'a' || choice == 'w' || choice == 's' || choice == 'd' || choice == 'f')) {
                break;
            } else {
                std::cout << std::endl << "Please enter 1, 2, 3, 4 or 5:";
                std::cout << std::endl << "A. Left; W. Up; S. Down; D. Right; F. Game Menu." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        switch(choice){
            case 'D':
			case 'd':
                CurrentPuzzle -> Swap(BLANK_LEFT);
                PushToHistory(BLANK_LEFT);
                CurrentPuzzle -> Display();
                if(CurrentPuzzle -> IsDefault()) std::cout << std::endl << "Hooray! You are at solved position :)" << std::endl;
                break;

            case 'S':
			case 's':
                CurrentPuzzle -> Swap(BLANK_UP);
                PushToHistory(BLANK_UP);
                CurrentPuzzle -> Display();
                if(CurrentPuzzle -> IsDefault()) std::cout << std::endl << "Hooray! You are at solved position :)" << std::endl;
                break;

            case 'W':
			case 'w':
                CurrentPuzzle -> Swap(BLANK_DOWN);
                PushToHistory(BLANK_DOWN);
                CurrentPuzzle -> Display();
                if(CurrentPuzzle -> IsDefault()) std::cout << std::endl << "Hooray! You are at solved position :)" << std::endl;
                break;

            case 'A':
			case 'a':
                CurrentPuzzle -> Swap(BLANK_RIGHT);
                PushToHistory(BLANK_RIGHT);
                CurrentPuzzle -> Display();
                if(CurrentPuzzle -> IsDefault()) std::cout << std::endl << "Hooray! You are at solved position :)" << std::endl;
                break;

            case 'F':
			case 'f':
                std::cout << std::endl << "Current Puzzle:" << std::endl;
                CurrentPuzzle -> Display();
                exit = true;
                break;
            default:;
        }

    }
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

// undo this numStep # of steps
// tonname
void Game::Undo(int numStep){}


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
        if(copyThisPuzzle.Swap_NoMessage(aMove)){
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
    if(!(CurrentPuzzle->IsSolvable())){
        return NOTFOUND;
    }

    PuzzleSearchNode root(*CurrentPuzzle, 0);
    PuzzleSearchNode leaf = root;
    int bound = root.H;
    int t;
    std::cout << std::endl << "Computer is thinking ...";
	std::cout << std::endl << "May take up to a couple of mins in most cases ..." << std::endl;

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
    //std::cout << std::endl << "GameID:    " << GameID << std::endl;
    std::cout << std::endl << "Initial Puzzle:" << std::endl;
    InitialPuzzle -> Display();
    std::cout << std::endl << "Move History:";
    if(MoveHistory.size() == 0) std::cout << "  None.";
    for(int i = 0; i < MoveHistory.size(); i++){
        DisplayMoveDirect(MoveHistory[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl << "Current Puzzle:" << std::endl;
    CurrentPuzzle -> Display();
}

//replay through MoveHistory
void Game::Replay() const{
	Puzzle tempPuzzle = *InitialPuzzle;
	std::cout << std::endl << "Starting Game Replay:" << std::endl;
	tempPuzzle.Display();
	std::cout << " ";
	std::cin.ignore();
	std::vector<MoveDirect> tempHistory = MoveHistory;
	std::vector<MoveDirect>::iterator it = tempHistory.begin();
	for (; it!= tempHistory.end(); ++it){
		std::cout << std::endl << "To continue, press any key ..." << std::endl;
		std::cin.ignore();
		tempPuzzle.Swap(*it);
		tempPuzzle.Display();
	}
	std::cout << std::endl << "Replay ends." << std::endl;
}
