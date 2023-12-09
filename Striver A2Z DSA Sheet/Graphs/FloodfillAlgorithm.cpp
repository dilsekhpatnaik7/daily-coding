/*
Problem Link: https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& image, vector<vector<int>>& ans, int iniColor, int newColor) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor;
    }

    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int iniColor, int newColor, int delRow[], int delCol[]) {
        ans[row][col] = newColor;
        int n = image.size(), m = image[0].size();
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(isValid(nrow, ncol, n, m, image, ans, iniColor, newColor)) dfs(nrow, ncol, ans, image, iniColor, newColor, delRow, delCol);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        dfs(sr, sc, ans, image, iniColor, newColor, delRow, delCol);
        return ans;
    }
};