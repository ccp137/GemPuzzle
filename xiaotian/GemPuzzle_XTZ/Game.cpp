////
//// Game.cpp - Game class implementation
////
//// Written by Xiaotian Zhu
////
//
//#include <iostream>
//#include "Game.h"
//
//// default & init constructor
//// xiaotian
//Game::Game(){}
//
//// copy constructor
//// xiaotian
//Game::Game(const Game& source){}
//
//// destructor
//// xiaotian
//Game::~Game(){}
//
//// deep copy assignment operator
//// xiaotian
//Game& Game::operator = (const Game& source){}
//
//// get GameNumber
//// xiaotian
//int Game::GetGameNumber() const{}
//
//// get InitialPuzzle
//// xiaotian
//Puzzle* Game::GetInitialPuzzle() const{}
//
//// get CurrentPuzzle
//// xiaotian
//Puzzle* Game::GetCurrentPuzzle() const{}
//
//// get MoveHistory
//// xiaotian
//std::vector<MoveDirect> Game::GetMoveHistory() const{}
//
//
//// let user play the game
//// tonnam
//void Game::MoveInterface(){
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
//}
//
//// decide if user wins already
//// chengping
//bool Game::IsWin() const{
//    return
//        CurrentPuzzle -> IsDefault();
//}
//
//// return puzzle configuration at position in history
//// chengping
//Puzzle Game::Trace(int postion) const{}
//
//// undo this numStep # of steps
//// tonname
//void Game::Undo(int numStep){}
//
//// solve it by computer
//// let's all think about it
//Game SolveIt() const{}
//
//// display info for the Game
//// tonname
//void Display() const{}
