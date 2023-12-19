/*
Problem Link: https://www.codingninjas.com/studio/problems/floyd-warshall_2041979?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N^3)
Space Complexity: O(N*N)
*/

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));

    for(int i = 0; i < n; i++) matrix[i][i] = 0;
    for(auto i: edges) {
        int u = i[0] - 1;
        int v = i[1] - 1;
        int wt = i[2];
        matrix[u][v] = wt;
    }

    for(int via = 0; via < n; via++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }

    return matrix[src - 1][dest - 1] > 1e5 ? 1e9 : matrix[src - 1][dest - 1];
}