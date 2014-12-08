//
//  main.cpp
//  test
//
//  Created by Chengping Chai on 12/1/14.
//  Copyright (c) 2014 Chengping Chai. All rights reserved.
//
#define nx 3
#define ny 3
#include <iostream>
#include <cmath>

class eNode {
    
private:
    long puzzle;
    int iblank;
    eNode * up;
    eNode * down;
    eNode * left;
    eNode * right;
    eNode * parent;
public:
    long getPuzzle() {
        return puzzle;
    }
    int getIblank() {
        return iblank;
    }
    eNode * getUp() {
        return up;
    }
    eNode * getDown() {
        return down;
    }
    eNode * getLeft() {
        return left;
    }
    eNode * getRight() {
        return right;
    }
    eNode * getParent() {
        return parent;
    }
    void setPuzzle(long input) {
        puzzle = input;
    }
    void setIblank(int input) {
        iblank = input;
    }
    void setUp(eNode * input) {
        up = input;
    }
    void setDown(eNode * input) {
        down = input;
    }
    void setLeft(eNode * input) {
        left = input;
    }
    void setRight(eNode * input) {
        right = input;
    }
    void setParent(eNode * input) {
        parent = input;
    }
    int* convert(long input){
        int * array =  new int[nx*ny];
        long temp;
        temp = input;
        for (int i=0; i<nx*ny; i++) {
            array[nx*ny-i-1] = temp % 16+1;
            if (temp % 16+1 == 9) {
                array[nx*ny-i-1] = 0;
            }
            temp = temp / 16;
        }
        return array;
    }
    void display(long input){
        int * array;
        array = convert(input);
        for (int i=0; i<ny; i++) {
            for (int j=0; j<nx; j++) {
                std::cout << array[i*nx+j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    int findBlank(long input){
        long temp = input;
        int digit;
        int iblank=-1;
        for (int i=0; i<nx*ny; i++) {
            digit = temp % 16 + 1;
            if (digit == nx*ny) {
                iblank = i;
            }
            temp = temp / 16;
        }
        return iblank;
    }
    long moveBlank(long input, int &iblank, int direct){
        // 0: right; 1: down; 2: left; 3: up
        long result=input;
        int swapDigit;
        long power;
        long power4;
        switch (direct) {
            case 0:
                if (iblank - 1 >= nx*(iblank/nx)){
                    power = pow(16,(iblank-1));
                    swapDigit = (input / power) % 16;
                    result = input - (nx*ny-1)*power*16 + (nx*ny-1)*power;
                    result = result - swapDigit*power + swapDigit*power*16;
                    iblank = iblank - 1;
                }
                break;
            case 1:
                if (iblank - nx >= 0) {
                    power = pow(16,(iblank-nx));
                    power4 = pow(16,nx);
                    swapDigit = (input / power) % 16;
                    result = input - (nx*ny-1)*power*power4 + (nx*ny-1)*power;
                    result = result - swapDigit*power + swapDigit*power*power4;
                    iblank = iblank - nx;
                }
                break;
            case 2:
                if (iblank + 1 < nx*(iblank/nx+1)) {
                    power = pow(16,iblank);
                    swapDigit = (input / power/16) % 16;
                    result = input - (nx*ny-1)*power + (nx*ny-1)*power*16;
                    result = result - swapDigit*power*16 + swapDigit*power;
                    iblank = iblank + 1;
                }
                break;
            case 3:
                if (iblank+nx < nx*ny){
                    power = pow(16,iblank);
                    power4 = pow(16,nx);
                    swapDigit = (input / power / power4) % 16;
                    result = input - (nx*ny-1)*power + (nx*ny-1)*power*power4;
                    result = result - swapDigit*power*power4 + swapDigit*power;
                    iblank = iblank + nx;
                }
                break;
            default:
                break;
        }
        return result;
    }
};
class eTree {
private:
    eNode * sNode;
    eNode * target;
public:
    eTree (long input1, long input2) {
        sNode = new eNode;
        sNode -> setPuzzle(input1);
        sNode -> setIblank(sNode->findBlank(input1));
        sNode -> setParent(NULL);
        sNode -> setUp(NULL);
        sNode -> setDown(NULL);
        sNode -> setLeft(NULL);
        sNode -> setRight(NULL);
        target = new eNode;
        target -> setPuzzle(input2);
        target -> setIblank(target->findBlank(input2));
        target -> setParent(NULL);
        target -> setUp(NULL);
        target -> setDown(NULL);
        target -> setLeft(NULL);
        target -> setRight(NULL);
    }
    eNode * getSNode(){
        return sNode;
    }
    eNode * getTarget() {
        return target;
    }
    void setSNode(eNode * input){
        sNode = input;
    }
    void setTarget(eNode * input){
        target = input;
    }
    eNode * addNode(eNode * parent){
        eNode * upNode = NULL;
        eNode * downNode = NULL;
        eNode * leftNode = NULL;
        eNode * rightNode = NULL;
        long current;
        long moved;
        int parent_blank, child_blank;
        current= parent -> getPuzzle();
        parent_blank = parent -> getIblank();
        // up
        child_blank = parent_blank;
        moved = parent -> moveBlank(current, child_blank, 3);
        if (moved != current) {
            upNode = new eNode;
            upNode -> setPuzzle(moved);
            upNode -> setIblank(child_blank);
            upNode -> setParent(parent);
            parent -> setUp(upNode);
        }
        if (moved == target->getPuzzle()){
            return upNode;
        }
        // down
        child_blank = parent_blank;
        moved = parent -> moveBlank(current, child_blank, 1);
        if (moved != current) {
            downNode = new eNode;
            downNode -> setPuzzle(moved);
            downNode -> setIblank(child_blank);
            downNode -> setParent(parent);
            parent -> setDown(downNode);
        }
        if (moved == target->getPuzzle()){
            return downNode;
        }
        // left
        child_blank = parent_blank;
        moved = parent -> moveBlank(current, child_blank, 2);
        if (moved != current) {
            leftNode = new eNode;
            leftNode -> setPuzzle(moved);
            leftNode -> setIblank(child_blank);
            leftNode -> setParent(parent);
            parent -> setLeft(leftNode);
        }
        if (moved == target->getPuzzle()){
            return leftNode;
        }
        // right
        child_blank = parent_blank;
        moved = parent -> moveBlank(current, child_blank, 0);
        if (moved != current) {
            rightNode = new eNode;
            rightNode -> setPuzzle(moved);
            rightNode -> setIblank(child_blank);
            rightNode -> setParent(parent);
            parent -> setRight(rightNode);
        }
        if (moved == target->getPuzzle()){
            return rightNode;
        }
        return parent;
    }
    eNode * solveIt(eNode * input) {
        eNode * result= NULL;
        eNode * moved= NULL;
        if (input != NULL){
            moved = addNode(input);
        }
        if (moved == input) {
            if (input != NULL and input -> getUp() != NULL) {
                result = solveIt(input->getUp());
            }
            if (input != NULL and result == input and input -> getDown() != NULL) {
                result = solveIt(input->getDown());
            }
            if (input != NULL and result == input and input -> getLeft() != NULL) {
                result = solveIt(input->getLeft());
            }
            if (input != NULL and result == input and input -> getRight() != NULL) {
                result = solveIt(input->getRight());
            }
            return result;
        }
        else {
            return moved;
        }
    }
};

int main(int argc, const char * argv[]) {
    long start_puzzle = 0x582470361;
    long target_puzzle = 0x012345678;
    eNode * temp;
    eNode * test;
    eTree database(start_puzzle,target_puzzle);
    test = database.getSNode();
    test = test -> getDown();
    if (test != NULL) {
        test -> display(test->getPuzzle());
    }
    temp = database.solveIt(database.getSNode());
    if (temp != NULL) {
        temp -> display(temp->getPuzzle());
    }
    return 0;
}
