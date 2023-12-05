// Problem Link: https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row * col, count = 0;

        int startingRow = 0, endingRow = row - 1, startingCol = 0, endingCol = col - 1;
        while(count < total) {
            // Starting Row
            for(int index = startingCol; index <= endingCol && count < total; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            
            // Ending Column
            for(int index = startingRow; index <= endingRow && count < total; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

            // Ending Row
            for(int index = endingCol; index >= startingCol && count < total; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            // Starting Column
            for(int index = endingRow; index >= startingRow && count < total; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};