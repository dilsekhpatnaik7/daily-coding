/*
Problem Link: https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution {
    public:
    bool isValid(int grid[N][N], int row, int col, int c) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(grid[i][col] == c) return false;
                if(grid[row][i] == c) return false;
                if(grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
            }
        }
        return true;
    }
    
    bool solve(int grid[N][N]) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == 0) {
                    for(int c = 1; c <= 9; c++) {
                        if(isValid(grid, i, j, c)) {
                            grid[i][j] = c;
    
                            if(solve(grid)) return true;
                            else grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool SolveSudoku(int grid[N][N]) { 
        return solve(grid);
    }
    
    void printGrid (int grid[N][N]) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
        }
    }
};