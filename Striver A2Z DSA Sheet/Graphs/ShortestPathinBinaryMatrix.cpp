/*
Problem Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& grid) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        int delRow[] = {-1, 0, +1, 0, -1, +1, +1, -1};
	    int delCol[] = {0, +1, 0, -1, +1, +1, -1, -1};
	    
	    q.push({1, {0, 0}});
	    dist[0][0] = 1;
	    
	    while(!q.empty()) {
	        int distance = q.front().first;
	        int row = q.front().second.first;
	        int col = q.front().second.second;
	        q.pop();
	        
	        if(row == n - 1 && col == m - 1) return distance;
	        for(int i = 0; i < 8; i++) {
	            int nrow = row + delRow[i];
	            int ncol = col + delCol[i];
	            if(isValid(nrow, ncol, n, m, grid)) {
	                if(distance + 1 < dist[nrow][ncol]) {
	                    dist[nrow][ncol] = distance + 1;
	                    q.push({distance + 1, {nrow, ncol}});
	                }
	            }
	        }
	    }
	    
	    return -1;
    }
};