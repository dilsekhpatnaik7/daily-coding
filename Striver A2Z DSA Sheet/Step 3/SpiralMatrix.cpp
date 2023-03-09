// Problem Link: https://practice.geeksforgeeks.org/problems/cd61add036272faa69c6814e34aa7007d5a25aa6/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=spiral_matrix

class Solution{
public:
	int findK(vector<vector<int>> &a, int n, int m, int k) {
	    vector<int> ans;
        int row = n;
        int col = m;
        int total = row * col, count = 0;

        int startingRow = 0, endingRow = row - 1, startingCol = 0, endingCol = col - 1;
        while(count < total) {
            // Starting Row
            for(int index = startingCol; index <= endingCol && count < total; index++) {
                ans.push_back(a[startingRow][index]);
                count++;
            }
            startingRow++;
            
            // Ending Column
            for(int index = startingRow; index <= endingRow && count < total; index++) {
                ans.push_back(a[index][endingCol]);
                count++;
            }
            endingCol--;

            // Ending Row
            for(int index = endingCol; index >= startingCol && count < total; index--) {
                ans.push_back(a[endingRow][index]);
                count++;
            }
            endingRow--;

            // Starting Column
            for(int index = endingRow; index >= startingRow && count < total; index--) {
                ans.push_back(a[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans[k - 1];
    }
};