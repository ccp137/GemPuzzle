GemPuzzle
=========
Gem Puzzle is a sliding puzzle that consists of a frame of numbered square tiles in random order with one tile missing (from [wiki](http://en.wikipedia.org/wiki/15_puzzle)).

## Blueprint
```
  class Puzzle
    Description: define the basic data structure
    Objective:
    Variables:
      int Nrow;
      int Ncol;
      int Vblank;
      int Hblank;
      int ** Entries;
    Functions:
      Puzzle(int nrow = 4, int ncol = 4);
      Puzzle(int nrow, int ncol, int* entries);
      Puzzle(const Puzzle& source);
      ~Puzzle();
      Puzzle& operator = (const Puzzle& source);
      bool operator == (const Puzzle& compareTo) const;
      int GetNrow() const;
      int GetNcol() const;
      int GetVblank() const;
      int GetHblank() const;
      int** GetEntries() const;
      void SetEntries(int* entries);
      void Display() const;
      bool Swap(MoveDirect thisDirect);
      void RandomSet();
      void ByUser();
      bool IsSovable();
      bool IsDefault();
  class Game
    Description: Play the game and keep track of the moves
    Objective:
    Variables:
      int GameNumber;
      Puzzle* InitialPuzzle;
      Puzzle* CurrentPuzzle;
      std::vector<MoveDirect> MoveHistory;
    Functions:
      Game();
      Game(const Game& source);
      ~Game();
      Game& operator = (const Game& source);
      int GetGameNumber() const;
      Puzzle* GetInitialPuzzle() const;
      Puzzle* GetCurrentPuzzle() const;
      std::vector<MoveDirect> GetMoveHistory() const;
      void MoveInterface();
      bool IsWin() const;
      Puzzle Trace(int postion) const;
      void Undo(int numStep);
      Game SolveIt() const;
      void Display() const;
  class Menu:
    Description:
    Objective:
    Variables:
    Functions:

```

## Things to do

* class Puzzle
	1. code blank space by 0 (xiaotian)
	2. implement the IsSolvable() function (chengping)
	3. add checking to ByUser() function according to the dimensions (xiaotian)
	4. maybe later adding distance function to facilitate SolveIt() (can wait)
	5. bool IsDefault(need to be tested)
* class Game
	1. basic features (xiaotian)
	2. other staff by chengping and tonnam (please see comments)
	3. think about proving more moving options (tonnam)

* class Menu
	1. scketch up the plan for Menu (tonnam)


## Git command

Add a file or files
```
    git add FILENAME
    git add .
    git commit -m "COMMENTS"
```

Remove a file
```
    git rm FILENAME
    git commit -m "COMMENTS"
```
Edit a file
```
    git commit -a -m "COMMENTS"
```
Update changes to the server
```
    git push origin master
```

Download the current version
```
    git pull origin master
```
