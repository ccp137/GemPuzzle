#pragma once

//
// Puzzle.h - Puzzle class declaration
//
// Written by Xiaotian Zhu
//

enum MoveDirect {BLANK_UP, BLANK_DOWN, BLANK_LEFT, BLANK_RIGHT};

// a Puzzle object stores configuration of any gem puzzle
// class Puzzle is the building block for GemPuzzle project
class Puzzle{

    public:
        // default & init constructor
        Puzzle(int nrow = 4, int ncol = 4);

        // init constructor version 2
        Puzzle(int nrow, int ncol, int* entries);

        // copy constructor
        Puzzle(const Puzzle& source);

        // destructor
        ~Puzzle();

        // deep copy assignment operator
        Puzzle& operator = (const Puzzle& source);

        // Comparison operator: Puzzles are equal when they are the same
        bool operator == (const Puzzle& compareTo) const;

        // get Nrow
        int GetNrow() const;

        // get Ncol
        int GetNcol() const;

        // get Vblank
        int GetVblank() const;

        // get Hblank
        int GetHblank() const;

        // get Entries
        int** GetEntries() const;

        // set Entries
        void SetEntries(int* entries);

        // displaying
        void Display() const;

        // swap blank space and a nearby entry
        bool Swap(MoveDirect thisDirect);

        // randomly permute all entries
        void RandomSet();

        // let user set the entries
        void ByUser();

        // count number of inversions
        int CountInversions(int irow, int icol);

        // sum number of inversions
        int SumInversions();

        // function to determine solvability
        bool IsSovable();

        // check if Puzzle is same as default
        bool IsDefault();


    private:
        // data fields
        int Nrow; // number of rows
        int Ncol; // number of columns
        int Vblank; // row index of blank space, between 0 and Nrow - 1
        int Hblank; // column index of blank space, between 0 and Ncol - 1
        int** Entries; // 2d-array for storing entries

};
