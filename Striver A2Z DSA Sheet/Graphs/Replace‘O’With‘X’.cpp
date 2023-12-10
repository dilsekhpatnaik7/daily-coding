/*
Problem Link: https://www.codingninjas.com/studio/problems/replace-%E2%80%98o%E2%80%99-with-%E2%80%98x%E2%80%99_630517?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

#include<bits/stdc++.h>
bool isValid(int nrow, int ncol, int n, int m, char** arr, vector<vector<int>>& vis) {
    return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && arr[nrow][ncol] == 'O';
}

void dfs(int row, int col, int n, int m, char** arr, vector<vector<int>>& vis, int delRow[], int delCol[]) {
    vis[row][col] = 1;
    
    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        
        if(isValid(nrow, ncol, n, m, arr, vis)) dfs(nrow, ncol, n, m, arr, vis, delRow, delCol);
    }
}

void replaceOWithX(char** arr, int n, int  m) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    
    // Traversing First and Last Row
    for(int j = 0; j < m; j++) {
        if(!vis[0][j] && arr[0][j] == 'O') dfs(0, j, n, m, arr, vis, delRow, delCol);
        
        if(!vis[n - 1][j] && arr[n - 1][j] == 'O') dfs(n - 1, j, n, m, arr, vis, delRow, delCol);
    }
    
    // Traversing First and Last Column
    for(int i = 0; i < n; i++) {
        if(!vis[i][0] && arr[i][0] == 'O') dfs(i, 0, n, m, arr, vis, delRow, delCol);
        
        if(!vis[i][m - 1] && arr[i][m - 1] == 'O') dfs(i, m - 1, n, m, arr, vis, delRow, delCol);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 0 && arr[i][j] == 'O') arr[i][j] = 'X'; 
        }
    }
}