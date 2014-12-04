#pragma once

#include "Puzzle.h"

//
// PuzzleSearchNode.h - PuzzleSearchNode class declaration
//
// Written by Xiaotian Zhu
//

// a Puzzle object stores configuration of any gem puzzle
// class Puzzle is the building block for GemPuzzle project
struct PuzzleSearchNode{

    // init constructor
    PuzzleSearchNode(const Puzzle& thisPuzzle, int g){
        PuzzleToSolve = thisPuzzle;
        G = g;

        CalcHF();

        Parent = NULL;
        GetHere = BLANK_UP;

    }

    // re-calcuate H, F
    void CalcHF(){
        H = PuzzleToSolve.Heuristic();
        F = G + H;
    }

    Puzzle PuzzleToSolve;
    int G;  // past path-cost
    int H;  // heuristic future path-cost
    int F;  // total cost
    PuzzleSearchNode* Parent;
    MoveDirect GetHere;

};
