GemPuzzle
=========
Gem Puzzle is a sliding puzzle that consists of a frame of numbered square tiles in random order with one tile missing (from [wiki](http://en.wikipedia.org/wiki/15_puzzle)).

## Blueprint
```
  class Puzzle
    Description: define the basic data tructure 
    Objective:
    Variables:
    Functions:

  class Game
    Description:
    Objective:
    Variables:
    Functions:

  class Solution:
    Description:
    Objective:
    Variables:
    Functions:

```

## Things to do

* class Puzzle
	a) code blank space by 0 (xiaotian)
	b) implement the IsSolvable() function (chengping)
	c) add checking to ByUser() function according to the dimensions (xiaotian)
	d) maybe later adding distance function to facilitate SolveIt() (can wait)
	e) bool IsDefault(need to be tested)
* class Game
	a) basic features (xiaotian)
	b) other staff by chengping and tonnam (please see comments)
	c) think about proving more moving options (tonnam)
	
* class Menu
	a) scketch up the plan for Menu (tonnam)
	

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
