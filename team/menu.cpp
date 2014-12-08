//
// Menu.cpp -- function definition for menus
//
// Written by Xiaotian Zhu
//

#include <iostream>
#include "Game.h"
#include <limits>

#define FOUND -100
#define NOTFOUND -200

void welcomeMenu(){
    std::cout << std::endl << "####################################################";
    std::cout << std::endl << "## AERSP 424 Final Project, Fall 2014, Penn State ##";
    std::cout << std::endl << "## Chengping Chai, Tonnam Balankuru, Xiaotian Zhu ##";
    std::cout << std::endl << "####################################################" << std::endl;
    std::cout << std::endl << "Welcome to GemPuzzle :)";
    std::cout << std::endl << "This program allows you to play a 3x3 GemPuzzle.";
    std::cout << std::endl << "The goal is to place the 8 tiles in order,";
    std::cout << std::endl << "by sliding tiles adjacent to the empty space.";
    std::cout << std::endl << "The program is also able to find a shortest solution." << std::endl;
    Puzzle solvedEightPuzzle(3,3);
    std::cout << std::endl << "Diagram of solved 8-Puzzle:";
    solvedEightPuzzle.Display();
}

void gameMenu(){
    Game aNewGame(3, 3);
    std::cout << std::endl << "Current Puzzle:" << std::endl;
    aNewGame.GetCurrentPuzzle() -> Display();
    bool exit = false;
    int choice;
    while(!exit){
        std::cout << std::endl << "Game Menu:";
        std::cout << std::endl << "1. Play; 2. Solve for Me; 3. Game Info; 4. Replay; 5. Main Menu." << std::endl;

        for(;;){
            if (std::cin >> choice && choice > 0 && choice < 6) {
                break;
            } else {
                std::cout << std::endl << "Please enter 1, 2, 3, 4 or 5:";
                std::cout << std::endl << "1. Play; 2. Solve for Me; 3. Game Info; 4. Replay; 5. Main Menu." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        switch(choice){
            case 1:
                std::cout << std::endl << "Current Puzzle:" << std::endl;
                aNewGame.GetCurrentPuzzle() -> Display();
                aNewGame.MoveInterface();
                break;

            case 2:
                if(aNewGame.SolveIt() == NOTFOUND){
                    std::cout << std::endl << "This is NOT solvable :(" << std::endl;
                }else{
                    std::cout << std::endl << "Got it :) Shortest solution found & appended to Move History. Solved game:" << std::endl;
                    aNewGame.Display();
                }
                break;

            case 3:
                std::cout << std::endl << "Game Info:" << std::endl;
                aNewGame.Display();
                break;

			case 4:
				aNewGame.Replay();
				break;

            case 5:
                exit = true;
                break;
            default:;
        }

    }

}

void mainMenu(){
    bool exit = false;
    int choice;
    while (!exit){
        std::cout << std::endl << "Main Menu:";
        std::cout << std::endl << "1. New Game; 2. Exit." << std::endl;

        for(;;){
            if (std::cin >> choice && choice > 0 && choice < 3) {
                break;
            } else {
                std::cout << std::endl << "Please enter 1 or 2:";
                std::cout << std::endl << "1. New Game; 2. Exit." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        switch(choice){
            case 1:
                gameMenu();
                break;
            case 2:
                exit = true;
                std::cout << std::endl << "Byebye!" << std::endl;
                break;
            default:;
        }

    }
}
