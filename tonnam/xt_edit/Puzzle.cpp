//
// Puzzle.cpp - Puzzle class implementation
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
//#include <time.h>
#include "Puzzle.h"

// default & init constructor
Puzzle::Puzzle(int nrow, int ncol){
    Nrow = nrow;
    Ncol = ncol;

    Entries = new int*[Nrow];
    for(int i = 0; i < Nrow; i++){
        Entries[i] = new int[Ncol];
    }

    for(int i = 0; i< Nrow; i++){
        for(int j = 0; j < Ncol; j++){
            Entries[i][j] = i*Ncol + j + 1;
        }
    }

    Vblank = Nrow - 1;
    Hblank = Ncol - 1;

}

// init constructor version 2
Puzzle::Puzzle(int nrow, int ncol, int* entries){
    Nrow = nrow;
    Ncol = ncol;
    Entries = new int*[Nrow];
    for(int i = 0; i < Nrow; i++){
        Entries[i] = new int[Ncol];
    }

    int index = 0;
    for(int i = 0; i< Nrow; i++){
        for(int j = 0; j < Ncol; j++){
            Entries[i][j] = entries[index];
            if (Entries[i][j] == Nrow * Ncol){
                Vblank = i;
                Hblank = j;
            }
            index++;
        }
    }

}

// copy constructor
Puzzle::Puzzle(const Puzzle& source){
    // std::cout << std::endl << "copy constructor called" << std::endl;
    Entries = NULL;
	// Calls the assignment operator
	*this = source;
}

// destructor
Puzzle::~Puzzle(){
    // std::cout << std::endl << "destructor called" << std::endl;
    for(int i = 0; i < Nrow; i++){
        delete[] Entries[i];
    }
    delete[] Entries;
	Entries = NULL;
}

// deep copy assignment operator
Puzzle& Puzzle::operator = (const Puzzle& source){
    // std::cout << std::endl << "deep copy assignment operator called" << std::endl;

    // first we have to dispose previously allocated memory
    if(Entries != NULL){
        for(int i = 0; i < Nrow; i++){
            delete[] Entries[i];
        }
        delete[] Entries;
    }

    // copy fields
    Nrow = source.GetNrow();
    Ncol = source.GetNcol();
    Vblank = source.GetVblank();
    Hblank = source.GetHblank();

    // allocate new memory
    Entries = new int*[Nrow];
    for(int i = 0; i < Nrow; i++){
        Entries[i] = new int[Ncol];
    }

    // deep copy
    for(int i = 0; i < Nrow; i++){
        for(int j = 0; j < Ncol; j++){
            Entries[i][j] = source.GetEntries()[i][j];
        }
    }

    return
            *this;

}

// Comparison operator: Puzzles are equal when their static fields are the same
// , and they dynamic fields store the same values
bool Puzzle::operator == (const Puzzle& compareTo) const{
    if(Nrow == compareTo.GetNrow() && Ncol == compareTo.GetNcol() && Vblank == compareTo.GetVblank() && Hblank == compareTo.GetHblank()){
        bool isEqual = true;
        for(int i = 0; (i < Nrow) && (isEqual == true); i++){
            for(int j = 0; (j < Ncol) && (isEqual == true); j++){
                isEqual = (Entries[i][j] == compareTo.GetEntries()[i][j]);
            }
        }
        return isEqual;
    }else{
        return false;
    }
}

// get Nrow
int Puzzle::GetNrow() const {
    return Nrow;
}

// get Ncol
int Puzzle::GetNcol() const {
    return Ncol;
}

// get Vblank
int Puzzle::GetVblank() const {
    return Vblank;
}

// get Hblank
int Puzzle::GetHblank() const {
    return Hblank;
}

// get Entries
int** Puzzle::GetEntries() const {
    return Entries;
}

// set Entries
void Puzzle::SetEntries(int* entries){
    int index = 0;
    for(int i = 0; i < Nrow; i++){
        for(int j = 0; j < Ncol; j++){
            Entries[i][j] = entries[index];
            if (Entries[i][j] == Nrow * Ncol){
                Vblank = i;
                Hblank = j;
            }
            index++;
        }
    }
}

// randomly permute all entries
void Puzzle::RandomSet(){
    int *entries = new int[Nrow*Ncol+1];
    for(int i = 0; i < (Nrow*Ncol); i++){
        entries[i] = i + 1;
    }
    entries[Nrow*Ncol] = 0;

    /* initialize random seed: */
    srand (time(NULL));

    std::random_shuffle(entries, entries + Nrow*Ncol);
    int index = 0;
    for(int i = 0; i < Nrow; i++){
        for(int j = 0; j < Ncol; j++){
            Entries[i][j] = entries[index];
            if (Entries[i][j] == Nrow * Ncol){
                Vblank = i;
                Hblank = j;
            }
            index++;
        }
    }

    delete[] entries;
}

// let user set the entries
void Puzzle::ByUser(){
    std::cout << "Please enter the entries for this " << Nrow << " x " << Ncol << " gem puzzle." << std::endl;
    for(int i = 0; i < Nrow; i++){
        for(int j = 0; j < Ncol; j++){
            std::cout << "[" << i << "][" << j << "]:  ";
            std::cin >> Entries[i][j];
            if (Entries[i][j] == Nrow * Ncol){
                Vblank = i;
                Hblank = j;
            }

            std::cout << std::endl;
        }
    }
}

// displaying
void Puzzle::Display() const {
    int width = 4 + int(std::log10(Nrow * Ncol));
    std::cout << std::endl;
    for(int i = 0; i < Nrow; i++){
        for(int j = 0; j < Ncol; j++){
            if( (i == Vblank) && (j == Hblank) ){
                std::cout << std::setw(width) << " ";
            }else{
                std::cout << std::setw(width) << Entries[i][j];
            }
        }
        std::cout << std::endl;
    }

}

// swap blank space and a nearby entry
bool Puzzle::Swap(MoveDirect thisDirect){
    int temp;
    switch(thisDirect){
        case BLANK_UP:
            if(Vblank != 0){
                temp = Entries[Vblank-1][Hblank];
                Entries[Vblank-1][Hblank] = Nrow*Ncol;
                Entries[Vblank][Hblank] = temp;
                Vblank -= 1;
            }else{
                cout << endl << "Invalid move!" << endl;
                return false;
            }
            break;
        case BLANK_DOWN:
            if(Vblank != (Nrow-1)){
                temp = Entries[Vblank+1][Hblank];
                Entries[Vblank+1][Hblank] = Nrow*Ncol;
                Entries[Vblank][Hblank] = temp;
                Vblank += 1;
            }else{
                cout << endl << "Invalid move!" << endl;
                return false;
            }
            break;
        case BLANK_LEFT:
            if(Hblank != 0){
                temp = Entries[Vblank][Hblank-1];
                Entries[Vblank][Hblank-1] = Nrow*Ncol;
                Entries[Vblank][Hblank] = temp;
                Hblank -= 1;
            }else{
                cout << endl << "Invalid move!" << endl;
                return false;
            }
            break;
        case BLANK_RIGHT:
            if(Hblank != (Ncol-1)){
                temp = Entries[Vblank][Hblank+1];
                Entries[Vblank][Hblank+1] = Nrow*Ncol;
                Entries[Vblank][Hblank] = temp;
                Hblank += 1;
            }else{
                cout << endl << "Invalid move!" << endl;
                return false;
            }
            break;
        default:;
    }
    return true;
}

// function to determine solvability
// chengping
bool Puzzle::IsSovable(){
        // need to fill out
        return true;
}

// check if Puzzle is same as default
// chengping
bool IsDefault(){
    Puzzle tempPuzzle(Nrow, Ncol);
    return tempPuzzle == *this;
}


