/*
Problem Link: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/

class Solution {
  public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1';
    }
  
    void solve(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size(), m = grid[0].size();
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int delrow = -1; delrow <= 1; delrow++) {
                for(int delcol = -1; delcol <= 1; delcol++) {
                    int nrow = r + delrow;
                    int ncol = c + delcol;
                    
                    if(isValid(nrow, ncol, n, m, vis, grid)) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
  
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int islands = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    solve(i, j, vis, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};