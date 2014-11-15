#include <iostream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <cstdlib>      // std::srand
#include <ctime>        // std::time

#include "puzzle.h"

Game::Game(int NDim)
{
    for(int i = 1; i < (NDim*NDim+1) ; ++i)
    {
        OneDList.push_back(i);
    };

    std::srand ( unsigned ( std::time(0) ) ); // Generate random seed
    std::random_shuffle( OneDList.begin(), OneDList.end() ); // Random shuffle OneDList

    for(int i = 0; i < NDim; ++i) // Create empty 2-d vector
    {
        std::vector<int> row;
        Box.push_back(row);
    };

    for(int i = 0; i < NDim; ++i) // Push resized 1-d list into rows of vector
    {
        for(int j = 0; j < NDim; ++j)
        {
            Box[i].push_back(OneDList[ i*NDim+j ]);
        }
    };

    Dim = NDim;
    VacCoord = SearchElement(Dim*Dim);
}

int Game::GetBoxElement(int x, int y)
{
    return Box[x][y];
}

void Game::DisplayBox()
{
    for(int i = 0; i < Dim; ++i)
    {
        for(int j = 0; j < Dim; ++j)
        {
            if(Box[i][j] == Dim*Dim) // Use last number (Dim*Dim) as vacant
            {
                std::cout << ' ' << '\t';
            } else
            {
                std::cout << Box[i][j] << '\t';
            }
        }
        std::cout << std::endl;
    }
}

std::vector<int> Game::SearchElement(int x)
{
    std::vector<int> Coord;
    for(int i = 0; i < Dim; ++i)
    {
        for(int j = 0; j < Dim; ++j)
        {
            if(Box[i][j]==x)
            {
                Coord.push_back(i);
                Coord.push_back(j);
            };
        };
    };
    return Coord;
}

bool Game::AskMove()
{
    int iMove;
    bool ExitAskMove = false;
    bool InvalidMove = true;
    while (InvalidMove)
    {
        std::cout << "Next move (0 = exit): ";
        std::cin >> iMove;
        if (iMove==0)
        {
            ExitAskMove = true;
            break;
        }
        else if (iMove >= Dim*Dim)
        {
            std::cout << "Invalid move" << std::endl;
        }
        else
        {
            std::vector<int> iMoveCoord = SearchElement(iMove);
            if( (((iMoveCoord[0]==(VacCoord[0]+1)) | (iMoveCoord[0]==(VacCoord[0]-1)))&(iMoveCoord[1]==VacCoord[1])) | (((iMoveCoord[1]==(VacCoord[1]+1)) | (iMoveCoord[1]==(VacCoord[1]-1)))&(iMoveCoord[0]==VacCoord[0])) )
            {
                // ((AdjacentRow & SameColumn) | (AdjacentColumn & SameRow))
                Box[VacCoord[0]][VacCoord[1]]=Box[iMoveCoord[0]][iMoveCoord[1]]; // Swap with vacant
                Box[iMoveCoord[0]][iMoveCoord[1]]=Dim*Dim;
                VacCoord[0]=iMoveCoord[0];
                VacCoord[1]=iMoveCoord[1];
                InvalidMove = false;
            } else
            {
                std::cout << "Invalid move" << std::endl;
            }
        }

    }
    return ExitAskMove;
}

std::vector<int> Game::GetVacCoord()
{
    return VacCoord;
}

Menu::Menu()
{

}

bool Menu::AskAction()
{
    bool ExitAskAction = false;
    bool InvalidAction = true;
    int iAction;
    int iDim;
    int iSelect;

    while(InvalidAction)
    {
        std::cout << "0 = exit, 1 = create new game, 2 = load saved game: ";
        std::cin >> iAction;
        if (iAction == 0)
        {
            ExitAskAction = true;
            break;
        }
        else if (iAction == 1)
        {
            std::cout << "Dimension of box: ";
            std::cin >> iDim;
            Game NewGame(iDim);
            GameVector.push_back(NewGame);

            std::cout << "Game start\n" << std::endl;
            bool ExitAsk = false;
            while(!ExitAsk)
            {
               NewGame.DisplayBox();
               ExitAsk = NewGame.AskMove();
            }

            InvalidAction = false;
        }
        else if (iAction == 2)
        {
            // Display all games
            std::cout << "Game list:\n" << std::endl;
            for(int i = 0; i < GameVector.size() ; ++i)
            {
                std::cout << "Game " << i << std::endl;
                GameVector[i].DisplayBox();
                std::cout << " " << std::endl;
            }

            std::cout << "Select game: ";
            std::cin >> iSelect;

            std::cout << "Game start\n" << std::endl;
            bool ExitAsk = false;
            while(!ExitAsk)
            {
               GameVector[iSelect].DisplayBox();
               ExitAsk = GameVector[iSelect].AskMove();
            }

        }
        else
        {
            std::cout << "Invalid move" << std::endl;
        }
    }

    return ExitAskAction;
}

int main()
{
    Menu TheMenu;
    bool ExitAsk = false;
    while(!ExitAsk)
    {
        ExitAsk = TheMenu.AskAction();
    }


/*
    std::cout << "0 = exit, # = make a move if valid" << std::endl;
    Game TheGame(5);
    bool ExitAsk = false;
    while(!ExitAsk)
    {
        TheGame.DisplayBox();
        ExitAsk = TheGame.AskMove();
    }
*/
}
