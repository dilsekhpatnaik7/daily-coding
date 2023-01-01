// Problem Link: https://leetcode.com/problems/unique-paths-iii/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public: 

    int dx[4]= {1,-1,0,0};
    int dy[4]= {0,0,-1,1};
    int total, n, m, a;
    
    void dfs(vector<vector<int>> &grid,  int i ,int j, int curr) {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==-1) return;
        if(grid[i][j]==2)
        {
            if(a==curr) total++;
            return;
        }
        
        grid[i][j] = -1;
        for(int a=0; a<4; a++)  dfs(grid, i + dx[a], j + dy[a], curr+1);
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        a = 0;
        int x,y;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                   x=i, y=j;
                }
                else if(grid[i][j]==2 or grid[i][j]==0) a++;
            }
        }
        total = 0;
        int curr = 0;
        dfs(grid,x,y,curr);
        return total;
    }
};