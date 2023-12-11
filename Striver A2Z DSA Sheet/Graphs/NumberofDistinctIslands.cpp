/*
Problem Link: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
  public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol];
    }
  
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& t, int row0, int col0, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        t.push_back({row - row0, col - col0});
        
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(isValid(nrow, ncol, n, m, grid, vis)) dfs(nrow, ncol, grid, vis, t, row0, col0, delRow, delCol);
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> s;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, + 1};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> t;
                    dfs(i, j, grid, vis, t, i, j, delRow, delCol);
                    s.insert(t);
                }
            }
        }
        return s.size();
    }
};