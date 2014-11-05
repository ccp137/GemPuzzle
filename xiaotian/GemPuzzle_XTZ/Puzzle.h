//
// Puzzle.h - Puzzle class declaration
//
// Written by Xiaotian Zhu
//

#pragma once

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

        // assignment operator
        Puzzle& operator = (const Puzzle& source);

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
        void Swap(MoveDirect thisDirect);

        // randomly permute all entries
        void RandomSet();


    private:
        // data fields
        int Nrow; // number of rows
        int Ncol; // number of columns
        int Vblank; // row index of blank space, between 0 and Nrow - 1
        int Hblank; // column index of blank space, between 0 and Ncol - 1
        int** Entries; // 2d-array for storing entries

};
