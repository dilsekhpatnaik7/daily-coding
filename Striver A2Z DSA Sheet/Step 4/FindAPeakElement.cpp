/*
Problem Link: https://www.codingninjas.com/studio/problems/find-peak-element_7449073?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(M + N)
Space Cmplexity: O(1)
*/

vector<int> findPeakGrid(vector<vector<int>> &g){
    int M = g.size();
    int N = g[0].size();
    
    int i = 0;
    int j = 0;
    
    while (true) {
        int maxI = i;
        int maxJ = j;
        
        if (i > 0 && g[i-1][j] > g[maxI][maxJ]) {
            maxI = i-1;
            maxJ = j;
        }
        if (j > 0 && g[i][j-1] > g[maxI][maxJ]) {
            maxI = i;
            maxJ = j-1;
        }
        if (i < M-1 && g[i+1][j] > g[maxI][maxJ]) {
            maxI = i+1;
            maxJ = j;
        }
        if (j < N-1 && g[i][j+1] > g[maxI][maxJ]) {
            maxI = i;
            maxJ = j+1;
        }
        
        if (i == maxI && j == maxJ) break;
        i = maxI;
        j = maxJ;
    }
    
    return {i, j};
}