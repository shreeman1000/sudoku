# sudoku
A sudoku game which uses a random method to generate a random sudoku puzzle then uses the backtracking method to completely fill it to create a solved sudoku.
Then testing how many numbers removed result in what difficulty score, which is calculated by a function which checks how many minimum options the player has at any given point then fills the correct option and goes on to check for the next move how many minimum options a player has, and setting a random amount of digits to be removed for each difficulty between a given interval and generating a puzzle.
The player has 3 tries to guess the correct answer and if not the answer is revealed and the player can retry with a new puzzle and a new difficulty (easy, medium or hard) or quit.
There is also a fourth option which just showcases how backtracking works by generating a random puzzle (not hard) and solving it whihc gives a visual representation of how how backtracking goes back steps and changes its approach at each dead end.
p.s. it only generates puzzle with a single solution so as to keep track of only solution while user is trying to solve.
