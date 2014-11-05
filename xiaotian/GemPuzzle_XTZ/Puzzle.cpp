//
// Puzzle.cpp - Puzzle class implementation
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Puzzle.h"

// default & init constructor
Puzzle::Puzzle(int nrow, int ncol, bool randomSet){
    Nrow = nrow;
    Ncol = ncol;

    Entries = new int*[Nrow];
    for(int i = 0; i < Nrow; i++){
        Entries[i] = new int[Ncol];
    }

    if(randomSet == false){

        for(int i = 0; i< Nrow; i++){
            for(int j = 0; j < Ncol; j++){
                Entries[i][j] = i*Ncol + j + 1;
            }
        }

        Vblank = Nrow - 1;
        Hblank = Ncol - 1;

    } else {
        // to be implemented soon
    }


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
    Entries = NULL;
	// Calls the assignment operator
	*this = source;
}

// destructor
Puzzle::~Puzzle(){
    for(int i = 0; i < Nrow; i++){
        delete[] Entries[i];
    }
    delete[] Entries;
	Entries = NULL;
}

// assignment operator
Puzzle& Puzzle::operator = (const Puzzle& source){

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
void Puzzle::Swap(MoveDirect thisDirect){
    int temp;
    switch(thisDirect){
        case BLANK_UP:
            if(Vblank != 0){
                temp = Entries[Vblank-1][Hblank];
                Entries[Vblank-1][Hblank] = Nrow*Ncol;
                Entries[Vblank][Hblank] = temp;
                Vblank -= 1;
            }else{}
            break;
        case BLANK_DOWN:
            if(Vblank != (Nrow-1)){
                temp = Entries[Vblank+1][Hblank];
                Entries[Vblank+1][Hblank] = Nrow*Ncol;
                Entries[Vblank][Hblank] = temp;
                Vblank += 1;
            }else{}
            break;
        case BLANK_LEFT:
            if(Hblank != 0){
                temp = Entries[Vblank][Hblank-1];
                Entries[Vblank][Hblank-1] = Nrow*Ncol;
                Entries[Vblank][Hblank] = temp;
                Hblank -= 1;
            }else{}
            break;
        case BLANK_RIGHT:
            if(Hblank != (Ncol-1)){
                temp = Entries[Vblank][Hblank+1];
                Entries[Vblank][Hblank+1] = Nrow*Ncol;
                Entries[Vblank][Hblank] = temp;
                Hblank += 1;
            }else{}
            break;
        default:;
    }
}


