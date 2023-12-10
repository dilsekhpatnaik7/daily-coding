/*
Problem Link: https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
  public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1;
    }

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(isValid(nrow, ncol, n, m, grid, vis)) dfs(nrow, ncol, grid, vis, delRow, delCol);
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        // Traversing First and Last Row
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) dfs(0, j, grid, vis, delRow, delCol);
            
            if(!vis[n - 1][j] && grid[n - 1][j] == 1) dfs(n - 1, j, grid, vis, delRow, delCol);
        }
        
        // Traversing First and Last Column
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && grid[i][0] == 1) dfs(i, 0, grid, vis, delRow, delCol);
            
            if(!vis[i][m - 1] && grid[i][m - 1] == 1) dfs(i, m - 1, grid, vis, delRow, delCol);
        }
        
        int enclaves = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) enclaves++;
            }
        }
        return enclaves;
    }
};