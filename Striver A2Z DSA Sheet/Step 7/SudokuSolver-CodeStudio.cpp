/*
Problem Link: https://www.codingninjas.com/studio/problems/sudoku-solver_8416969?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

bool isValid(int board[][9], int row, int col, int c) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
    }
    return true;
}

bool solve(int board[][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == 0) {
                for(int c = 1; c <= 9; c++) {
                    if(isValid(board, i, j, c)) {
                        board[i][j] = c;

                        if(solve(board)) return true;
                        else board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int board[][9]) {
    return solve(board);
}