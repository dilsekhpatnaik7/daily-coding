/*
Problem Link: https://www.codingninjas.com/studio/problems/distinct-islands_630460?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

#include<bits/stdc++.h>
bool isValid(int nrow, int ncol, int n, int m, int** arr, vector<vector<int>> &vis) {
    return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && arr[nrow][ncol] == 1 && !vis[nrow][ncol];
}

void dfs(int row, int col, int** arr, vector<vector<int>>& vis, vector<pair<int, int>>& t, int row0, int col0, int delRow[], int delCol[], int n, int m) {
    vis[row][col] = 1;
    t.push_back({row - row0, col - col0});

    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        
        if(isValid(nrow, ncol, n, m, arr, vis)) dfs(nrow, ncol, arr, vis, t, row0, col0, delRow, delCol, n, m);
    }
}

int distinctIslands(int** arr, int n, int m) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> s;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, -1, 0, + 1};
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && arr[i][j] == 1) {
                vector<pair<int, int>> t;
                dfs(i, j, arr, vis, t, i, j, delRow, delCol, n, m);
                s.insert(t);
            }
        }
    }
    return s.size();
}