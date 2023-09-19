/*
Problem Link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution{
public:
    bool isSafe(int col, int node, int n, int color[], bool graph[101][101]) {
        for(int k = 0; k < n; k++) {
            if(k != node && graph[k][node] == 1 && color[k] == col) return false;
        }
        return true;
    }

    bool solve(int node, int n, int m, int color[], bool graph[101][101]) {
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

    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        if(solve(0, n, m, color, graph)) return true;
        return false;
    }
};