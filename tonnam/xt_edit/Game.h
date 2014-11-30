//
// Game.h - Game class declaration
//
// Written by Xiaotian Zhu
//

#include "Puzzle.h"
#include <vector>

#pragma once

class Game{

    public:
        // default & init constructor
        Game();

        //// init constructor version 2
        //Game();

        // copy constructor
        Game(const Game& source);

        // destructor
        ~Game();

        // deep copy assignment operator
        Game& operator = (const Game& source);

        // get GameNumber
        int GetGameNumber() const;

        // get MyPuzzle
        //...

        // get MoveHistory
        // ...

        // get CurrentPosition
        // ...

        // let user play the game
        void MoveInterface();

        // decide if user wins already
        bool IsWin() const;

        // save to the MoveHistory
        void SaveHistory();

        // return puzzle configuration at position in history
        Puzzle Trace(int postion) const;

        // undo this numStep # of steps
        void Undo(int numStep);

        // solve it by computer
        Game SolveIt() const;

        // display info for the Game
        void Display() const;





    // member fields
    private:
        int GameNumber;
        Puzzle InitialPuzzle;
        Puzzle CurrentPuzzle;
        std::vector<MoveDirect> MoveHistory;
        //int CurrentPosition; // total number of effective elements in MoveHistory

}
