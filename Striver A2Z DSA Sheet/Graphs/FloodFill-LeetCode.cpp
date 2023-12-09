/*
Problem Link: https://leetcode.com/problems/flood-fill/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& image, vector<vector<int>>& ans, int iniColor, int color) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color;
    }

    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int iniColor, int color, int delRow[], int delCol[]) {
        ans[row][col] = color;
        int n = image.size(), m = image[0].size();
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(isValid(nrow, ncol, n, m, image, ans, iniColor, color)) dfs(nrow, ncol, ans, image, iniColor, color, delRow, delCol);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        dfs(sr, sc, ans, image, iniColor, color, delRow, delCol);
        return ans;
    }
};