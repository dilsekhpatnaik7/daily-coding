/*
Problem Link: https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
  public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& grid) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1;
    }
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        int delRow[] = {-1, 0, +1, 0};
	    int delCol[] = {0, +1, 0, -1};
	    
	    q.push({0, {source.first, source.second}});
	    dist[source.first][source.second] = 0;
	    
	    while(!q.empty()) {
	        int distance = q.front().first;
	        int row = q.front().second.first;
	        int col = q.front().second.second;
	        q.pop();
	        
	        if(row == destination.first && col == destination.second) return distance;
	        for(int i = 0; i < 4; i++) {
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