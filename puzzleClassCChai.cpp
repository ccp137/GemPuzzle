//
//  puzzleClassCChai.cpp
//  GemPuzzle
//
//  Created by Chengping Chai on 11/3/14.
//  Copyright (c) 2014 Chengping Chai. All rights reserved.
//

#define NX 4
#define NY 4
#include <iostream>
#include  <iomanip>
using namespace std;

class puzzle {
protected:
    int data[NX][NY];
public:
    puzzle(){
        int ix,iy;
        for (iy=0; iy<NY; iy++) {
            for (ix=0; ix<NX; ix++) {
                data[iy][ix] = iy*NX+ix+1;
            }
        }
        data[NX-1][NY-1] = 0;
    }
    int ** createData(){
        int** data = new int*[NY];
        int ix;
        for (ix=0; ix<NX; ix++) {
            data[ix] = new int[NX];
        }
        return data;
    }
    int ** getData(){
        int** copyData;
        int ix,iy;
        copyData = createData();
        for (iy=0; iy<NY; iy++) {
            for (ix=0; ix<NX; ix++) {
                copyData[iy][ix] = data[iy][ix];
            }
        }
        return copyData;
    }
    void setData(int ix, int iy, int value){
        if (ix >= 0 and ix < NX and iy >=0 and iy < NY){
            data[iy][ix] = value;
        }
        else{
            cout << "Index in setData not correct!"<<endl;
        }
    }
    void switchValue(int ix1, int iy1, int ix2, int iy2){
        int temp;
        temp = data[iy1][ix1];
        data[iy1][ix1] = data[iy2][ix2];
        data[iy2][ix2] = temp;
    }
    void searchLoc(int &i, int &j, int value){
        int ix=-1,iy=-1;
        for (iy=0; iy<NY; iy++) {
            for (ix=0; ix<NX; ix++) {
                if (data[iy][ix]==value) {
                    i = ix;
                    j = iy;
                }
            }
        }
        if (ix==-1 or iy==-1){
            cout << "Value not found!" <<endl;
        }
    }
    void moveData(int value){
        int izx, izy;
        int ivx, ivy;
        searchLoc(izx, izy, 0);
        searchLoc(ivx, ivy, value);
        switchValue(izx, izy, ivx, ivy);
    }
    void printData(){
        int ix,iy;
        for (iy=0; iy<NY; iy++) {
            for (ix=0; ix<NX; ix++) {
                if (data[iy][ix] > 0 and data[iy][ix] < NX*NY){
                    cout << setw(2) << data[iy][ix] << "   ";
                }
                else if (data[iy][ix] == 0){
                    cout << "  ";
                }
                
            }
            cout << endl;
        }
    }
};


int main(int argc, const char * argv[]) {
    puzzle a;
    a.printData();
    a.moveData(12);
    a.printData();
    return 0;
}
