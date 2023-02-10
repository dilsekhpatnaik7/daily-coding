// Problem Link: https://leetcode.com/problems/as-far-from-land-as-possible/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 1) continue;
                grid[i][j] = 201;
                if (i > 0) grid[i][j] = min(grid[i][j], grid[i-1][j] + 1);
                if (j > 0) grid[i][j] = min(grid[i][j], grid[i][j-1] + 1);
            }
        }
        
        for(int i = n-1; i > -1; i--) {
            for(int j = m-1; j > -1; j--) {
                if (grid[i][j] == 1) continue;
                if (i < n-1) grid[i][j] = min(grid[i][j], grid[i+1][j] + 1);
                if (j < m-1) grid[i][j] = min(grid[i][j], grid[i][j+1] + 1);
                res = max(res, grid[i][j]);
            }
        }
        return res == 201 ? -1 : res - 1;
    }
};