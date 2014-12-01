#pragma once

//
// Game.h - Game class declaration
//
// Written by Xiaotian Zhu
//

#include "Puzzle.h"
#include <vector>
#include "PuzzleSearchNode.h"

class Game{

    public:
        // default & init constructor
        Game(int nrow = 4, int ncol = 4);

        // copy constructor
        Game(const Game& source);

        // destructor
        ~Game();

        // deep copy assignment operator
        Game& operator = (const Game& source);

        // get GameNumber
        int GetGameID() const;

        // get InitialPuzzle
        Puzzle* GetInitialPuzzle() const;

        // get CurrentPuzzle
        Puzzle* GetCurrentPuzzle() const;

        // get MoveHistory
        std::vector<MoveDirect> GetMoveHistory() const;

        // get TotalNumber
        int GetTotalNumber() const;

        // get EverCreated
        int GetEverCreated() const;

        // let user play the game
        void MoveInterface();

        // decide if user wins already
        bool IsWin() const;

        // return puzzle configuration at position in history
        Puzzle Trace(int postion) const;

        // undo numStep # of steps
        void Undo(int numStep);

        // search function for IDA*
        int Search(PuzzleSearchNode& thisNode, int boundValue, PuzzleSearchNode& leafNode);

        // solve it by computer
        int SolveIt();

        // display info for the Game
        void Display() const;


    // member fields
    private:
        int GameID;
        Puzzle* InitialPuzzle;
        Puzzle* CurrentPuzzle;
        std::vector<MoveDirect> MoveHistory;
        static int TotalNumber;
        static int EverCreated;

};
