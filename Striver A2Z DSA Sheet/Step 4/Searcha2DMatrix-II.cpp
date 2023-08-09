/*
Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

Time Complexity: O(M + N)
Space Cmplexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0) {
            if(matrix[i][j] == target) return true;
            if(target > matrix[i][j]) i++;
            else j--;
        }
        return false;
    }
};