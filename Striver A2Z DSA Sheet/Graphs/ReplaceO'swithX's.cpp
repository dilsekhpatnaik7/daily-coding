/*
Problem Link: https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution{
public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<char>>& mat, vector<vector<int>>& vis) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O';
    }

    void dfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& vis, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(isValid(nrow, ncol, n, m, mat, vis)) dfs(nrow, ncol, mat, vis, delRow, delCol);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        // Traversing First and Last Row
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && mat[0][j] == 'O') dfs(0, j, mat, vis, delRow, delCol);
            
            if(!vis[n - 1][j] && mat[n - 1][j] == 'O') dfs(n - 1, j, mat, vis, delRow, delCol);
        }
        
        // Traversing First and Last Column
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && mat[i][0] == 'O') dfs(i, 0, mat, vis, delRow, delCol);
            
            if(!vis[i][m - 1] && mat[i][m - 1] == 'O') dfs(i, m - 1, mat, vis, delRow, delCol);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && mat[i][j] == 'O') mat[i][j] = 'X'; 
            }
        }
        
        return mat;
    }
};