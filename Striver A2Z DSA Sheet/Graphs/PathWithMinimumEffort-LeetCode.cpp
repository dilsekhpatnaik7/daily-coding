/*
Problem Link: https://leetcode.com/problems/path-with-minimum-effort/description/

Time Complexity: O(V*log(E))
Space Complexity: O(N*M)
*/

class Solution {
public:
    bool isValid(int nrow, int ncol, int n, int m) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()) {
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;;
            pq.pop();
            
            if(row == n - 1 && col == m - 1) return effort;
            for(int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(isValid(nrow, ncol, n, m)) {
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), effort);
                    if(newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};