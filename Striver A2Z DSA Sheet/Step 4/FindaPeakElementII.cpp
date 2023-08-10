/*
Problem Link: https://leetcode.com/problems/find-a-peak-element-ii/

Time Complexity: O(M + N)
Space Cmplexity: O(1)
*/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        
        int i = 0;
        int j = 0;
        
        while (true) {
            int maxI = i;
            int maxJ = j;
            
            if (i > 0 && mat[i-1][j] > mat[maxI][maxJ]) {
                maxI = i-1;
                maxJ = j;
            }
            if (j > 0 && mat[i][j-1] > mat[maxI][maxJ]) {
                maxI = i;
                maxJ = j-1;
            }
            if (i < M-1 && mat[i+1][j] > mat[maxI][maxJ]) {
                maxI = i+1;
                maxJ = j;
            }
            if (j < N-1 && mat[i][j+1] > mat[maxI][maxJ]) {
                maxI = i;
                maxJ = j+1;
            }
            
            if (i == maxI && j == maxJ) break;
            i = maxI;
            j = maxJ;
        }
        
        return {i, j};
    }
}; 