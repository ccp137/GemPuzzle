#pragma once

//
// PuzzleSearchNode.h - PuzzleSearchNode class declaration
//
// Written by Xiaotian Zhu
//

// a Puzzle object stores configuration of any gem puzzle
// class Puzzle is the building block for GemPuzzle project
struct PuzzleSearchNode{

    Puzzle PuzzleToSolve;
    int G;  // past path-cost
    int H;  // heuristic future path-cost
    int F;  // total cost
    PuzzleSearchNode* Parent;

};
