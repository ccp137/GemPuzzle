#pragma once

//
// Game.h - Game class declaration
//
// Written by Xiaotian Zhu
//

#include "Puzzle.h"
#include <vector>

class Game{

    public:
        // default & init constructor
        Game();

        // copy constructor
        Game(const Game& source);

        // destructor
        ~Game();

        // deep copy assignment operator
        Game& operator = (const Game& source);

        // get GameNumber
        int GetGameNumber() const;

        // get InitialPuzzle
        Puzzle* GetInitialPuzzle() const;

        // get CurrentPuzzle
        Puzzle* GetCurrentPuzzle() const;

        // get MoveHistory
        std::vector<MoveDirect> GetMoveHistory() const;

        // let user play the game
        void MoveInterface();

        // decide if user wins already
        bool IsWin() const;

        // return puzzle configuration at position in history
        Puzzle Trace(int postion) const;

        // undo numStep # of steps
        void Undo(int numStep);

        // solve it by computer
        Game SolveIt() const;

        // display info for the Game
        void Display() const;


    // member fields
    private:
        int GameNumber;
        Puzzle* InitialPuzzle;
        Puzzle* CurrentPuzzle;
        std::vector<MoveDirect> MoveHistory;

}
