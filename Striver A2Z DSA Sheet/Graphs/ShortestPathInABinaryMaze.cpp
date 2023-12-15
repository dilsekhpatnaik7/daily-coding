/*
Problem Link: https://www.codingninjas.com/studio/problems/shortest-path-in-a-binary-maze_893065?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

#include<bits/stdc++.h>
bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& matrix) {
    return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] == 1;
}

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest) {
    if(matrix[src.first][src.second] == 0) return -1;

    int n = matrix.size(), m = matrix[0].size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    
    q.push({0, {src.first, src.second}});
    dist[src.first][src.second] = 0;
    
    while(!q.empty()) {
        int distance = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        
        if(row == dest.first && col == dest.second) return distance;
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(isValid(nrow, ncol, n, m, matrix)) {
                if(distance + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = distance + 1;
                    q.push({distance + 1, {nrow, ncol}});
                }
            }
        }
    }
    
    return -1;
}