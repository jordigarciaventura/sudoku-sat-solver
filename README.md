# SUDOKU SAT SOLVER
## DESCRIPTION
Solve 9x9 sudokus based in the boolean satisfiability problem (SAT) using [PicoSAT](http://fmv.jku.at/picosat/#license).

## INSTRUCTIONS
### Get all sudoku possiblities
1. Go to the directory of the project `.../sudoku-sat-solver-main`.
2. Run `./picosat formula.cnf --all`

> There are 6,670,903,752,021,072,936,960 possibilites, so the process will never end. Use `Ctrl+C` to abort.

### Solve a sudoku
1. Make a copy of this [Template](https://docs.google.com/spreadsheets/d/1rd8iAS85u3_tvrnMjX1qa3-lBpkvhdP2gK_TOauqyb8/edit?usp=sharing) (File > Make a copy).
2. Fill in the template with the values you already have.
3. Copy the output command.
4. Go to the directory of the project `.../sudoku-sat-solver-main`.
5. Run the command obtained in step 3.

Now, if it is SATISFACIBLE, to see the solution:

6. Copy the solution.
7. Paste the solution inside `.../sudoku-sat-solver-main/sudoku_cnf`.
8. Run `cat ./sudoku.cnf | ./sudoku_ui`
