GemPuzzle
=========
Gem Puzzle is a game that consists of a matrix of numbered tiles with one tile missing, allowing the player to move the numbered tiles to the empty space one at a time. The objective of the game is to arrange the numbered tiles into ascending order. Our program allows the user to play a 3­by­3 Gem Puzzle that can be entered manually or randomly generated. We have also included the options to check if the puzzle is solvable and have the program solve the puzzle with minimal moves required.

## Compile and Run
Download all the files from the **team** folder to a local directory, for example **GEM**. Open the **Terminal** on you machine, go to the **GEM** folder. Use command
```
  g++ *.cpp
```  
or
```
  g++ main.cpp menu.cpp Game.cpp Puzzle.cpp
```
Type in the following command, the game is ready for fun. For Linux and Mac,
```
  ./a.out
```
or for Windows
```
  a.exe
```
You will see an interface like this in your terminal
```
####################################################
## AERSP 424 Final Project, Fall 2014, Penn State ##
## Chengping Chai, Tonnam Balankuru, Xiaotian Zhu ##
####################################################

Welcome to GemPuzzle :)
This program allows you to play a 3x3 GemPuzzle.
The goal is to place the 8 tiles in order,
by sliding tiles adjacent to the empty space.
The program is also able to find a shortest solution.

Diagram of solved 8-Puzzle:
1   2   3
4   5   6
7   8

Main Menu:
1. New Game; 2. Exit.
```
## Example
```
####################################################
## AERSP 424 Final Project, Fall 2014, Penn State ##
## Chengping Chai, Tonnam Balankuru, Xiaotian Zhu ##
####################################################

Welcome to GemPuzzle :)
This program allows you to play a 3x3 GemPuzzle.
The goal is to place the 8 tiles in order,
by sliding tiles adjacent to the empty space.
The program is also able to find a shortest solution.

Diagram of solved 8-Puzzle:
1   2   3
4   5   6
7   8

Main Menu:
1. New Game; 2. Exit.
1

Initialize Game: 1. Sorted; 2. Randomly; 3. By User.
2

Current Puzzle:

7   1   8
2   6
3   4   5

Game Menu:
1. Play; 2. Solve for Me; 3. Game Info; 4. Replay; 5. Main Menu.
1

Current Puzzle:

7   1   8
2   6
3   4   5

Play Menu:
A. Left; W. Up; S. Down; D. Right; F. Game Menu.
Note, for example, Left means moving the cell to the right of the empty space to the left, etc.
w

7   1   8
2   6   5
3   4

Play Menu:
A. Left; W. Up; S. Down; D. Right; F. Game Menu.
Note, for example, Left means moving the cell to the right of the empty space to the left, etc.
d

7   1   8
2   6   5
3       4

Play Menu:
A. Left; W. Up; S. Down; D. Right; F. Game Menu.
Note, for example, Left means moving the cell to the right of the empty space to the left, etc.
s

7   1   8
2       5
3   6   4

Play Menu:
A. Left; W. Up; S. Down; D. Right; F. Game Menu.
Note, for example, Left means moving the cell to the right of the empty space to the left, etc.
d

7   1   8
2   5
3   6   4

Play Menu:
A. Left; W. Up; S. Down; D. Right; F. Game Menu.
Note, for example, Left means moving the cell to the right of the empty space to the left, etc.
f

Current Puzzle:

7   1   8
2   5
3   6   4

Game Menu:
1. Play; 2. Solve for Me; 3. Game Info; 4. Replay; 5. Main Menu.
2

Computer is thinking ...
May take up to a couple of mins in most cases ...

Got it :) Shortest solution found & appended to Move History. Solved game:

Initial Puzzle:

7   1   8
2   6
3   4   5

Move History: (L means Left, etc.)
U R D R D L U U L D D R U U R D L U L D R D L U R U L

Current Puzzle:

1   2   3
4   5   6
7   8

Game Menu:
1. Play; 2. Solve for Me; 3. Game Info; 4. Replay; 5. Main Menu.
4

Starting Game Replay:

7   1   8
2   6
3   4   5

To continue, press Enter ...


7   1   8
2   6   5
3   4

To continue, press Enter ...


7   1   8
2   6   5
3       4

To continue, press Enter ...


7   1   8
2       5
3   6   4

To continue, press Enter ...


7   1   8
2   5
3   6   4

To continue, press Enter ...


1   8
7   2   5
3   6   4

To continue, press Enter ...


1       8
7   2   5
3   6   4

To continue, press Enter ...


1   2   8
7       5
3   6   4

To continue, press Enter ...


1   2   8
7   6   5
3       4

To continue, press Enter ...


1   2   8
7   6   5
3   4

To continue, press Enter ...


1   2   8
7   6
3   4   5

To continue, press Enter ...


1   2
7   6   8
3   4   5

To continue, press Enter ...


1       2
7   6   8
3   4   5

To continue, press Enter ...


1   6   2
7       8
3   4   5

To continue, press Enter ...


1   6   2
7   4   8
3       5

To continue, press Enter ...


1   6   2
7   4   8
3   5

To continue, press Enter ...


1   6   2
4   8
7   3   5

To continue, press Enter ...


1   6   2
4       8
7   3   5

To continue, press Enter ...


1   6   2
4   3   8
7       5

To continue, press Enter ...


1   6   2
4   3   8
7   5

To continue, press Enter ...


1   6   2
4   3
7   5   8

To continue, press Enter ...


1   6   2
4       3
7   5   8

To continue, press Enter ...


1       2
4   6   3
7   5   8

To continue, press Enter ...


1   2
4   6   3
7   5   8

To continue, press Enter ...


1   2   3
4   6
7   5   8

To continue, press Enter ...


1   2   3
4       6
7   5   8

To continue, press Enter ...


1   2   3
4   5   6
7       8

To continue, press Enter ...


1   2   3
4   5   6
7   8

Replay ends.

Game Menu:
1. Play; 2. Solve for Me; 3. Game Info; 4. Replay; 5. Main Menu.

5

Main Menu:
1. New Game; 2. Exit.
2

Byebye!

```


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
