/*
Problem Link: https://leetcode.com/problems/surrounded-regions/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<char>>& board, vector<vector<int>>& vis) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O';
    }

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(isValid(nrow, ncol, n, m, board, vis)) dfs(nrow, ncol, board, vis, delRow, delCol);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        // Traversing First and Last Row
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && board[0][j] == 'O') dfs(0, j, board, vis, delRow, delCol);
            
            if(!vis[n - 1][j] && board[n - 1][j] == 'O') dfs(n - 1, j, board, vis, delRow, delCol);
        }
        
        // Traversing First and Last Column
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && board[i][0] == 'O') dfs(i, 0, board, vis, delRow, delCol);
            
            if(!vis[i][m - 1] && board[i][m - 1] == 'O') dfs(i, m - 1, board, vis, delRow, delCol);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && board[i][j] == 'O') board[i][j] = 'X'; 
            }
        }
    }
};