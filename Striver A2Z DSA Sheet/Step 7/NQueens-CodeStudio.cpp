/*
Problem Link: https://www.codingninjas.com/studio/problems/n-queens_696453?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N!)
Space Complexity: O(N ^ 2)
*/

void add(int n, vector<vector<int>>& board, vector<vector<int>>& ans) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            v.push_back(board[i][j]);
        }
    }
    ans.push_back(v);
}

void solve(int col, int n, vector<vector<int>>& board, vector<vector<int>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal) {
    if(col == n) {
        add(n, board, ans);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 1;
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;

            solve(col + 1, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);

            board[row][col] = 0;
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);
    
    return ans;
}