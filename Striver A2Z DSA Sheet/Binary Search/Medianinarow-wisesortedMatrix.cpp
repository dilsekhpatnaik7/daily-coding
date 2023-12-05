/*
Problem Link: https://www.codingninjas.com/studio/problems/median-of-a-row-wise-sorted-matrix_1115473?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N * log(M))
Space Cmplexity: O(1)
*/

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int desiredAnswer = (m * n) / 2;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        for(int i = 0; i < m; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count <= desiredAnswer) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}