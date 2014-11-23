class Game
{
public:
    Game(int NDim); // Default constructor
    int GetBoxElement(int x,int y);
    void DisplayBox();
    std::vector<int> SearchElement(int x); // Search for x in Box
    bool AskMove(); // Ask for next move, check if valid, move
    std::vector<int> GetVacCoord();

private:
    std::vector< std::vector< int > > Box;
    std::vector< int > OneDList;
    std::vector<int> VacCoord;
    int Dim;
};

class Menu
{
public:
    Menu(); // Default constructor
    bool AskAction();

private:
    std::vector< Game > GameVector;
};
