/*
Problem Link: https://www.codingninjas.com/studio/problems/matrix-traps_8365440?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& Matrix, vector<vector<int>>& vis) {
    return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && Matrix[nrow][ncol] == 0;
}

void dfs(int row, int col, vector<vector<int>>& Matrix, vector<vector<int>>& vis, int delRow[], int delCol[]) {
    vis[row][col] = 1;
    
    int n = Matrix.size(), m = Matrix[0].size();
    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        
        if(isValid(nrow, ncol, n, m, Matrix, vis)) dfs(nrow, ncol, Matrix, vis, delRow, delCol);
    }
}

int matrixTraps(int N,int M,vector<vector<int>> &Matrix) {
    vector<vector<int>> vis(N, vector<int>(M, 0));
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    
    // Traversing First and Last Row
    for(int j = 0; j < M; j++) {
        if(!vis[0][j] && Matrix[0][j] == 0) dfs(0, j, Matrix, vis, delRow, delCol);
        
        if(!vis[N - 1][j] && Matrix[N - 1][j] == 0) dfs(N - 1, j, Matrix, vis, delRow, delCol);
    }
    
    // Traversing First and Last Column
    for(int i = 0; i < N; i++) {
        if(!vis[i][0] && Matrix[i][0] == 0) dfs(i, 0, Matrix, vis, delRow, delCol);
        
        if(!vis[i][M - 1] && Matrix[i][M - 1] == 0) dfs(i, M - 1, Matrix, vis, delRow, delCol);
    }
    
    int enclaves = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(vis[i][j] == 0 && Matrix[i][j] == 0) enclaves++;
        }
    }
    return enclaves;
}