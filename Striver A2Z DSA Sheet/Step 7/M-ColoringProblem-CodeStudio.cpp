/*
Problem Link: https://www.codingninjas.com/studio/problems/m-coloring-problem_981273?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

bool isSafe(int col, int node, int n, int color[], vector<vector<int>>& graph) {
    for(int k = 0; k < n; k++) {
        if(k != node && graph[k][node] == 1 && color[k] == col) return false;
    }
    return true;
}

bool solve(int node, int n, int m, int color[], vector<vector<int>>& graph) {
    if(node == n) return true;
    
    for(int i = 1; i <= m; i++) {
        if(isSafe(i, node, n, color, graph)) {
            color[node] = i;
            if(solve(node + 1, n, m, color, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    int color[n] = {0};
    if(solve(0, n, m, color, mat)) return "YES";
    return "NO";
}