/*
Problem Link: https://www.codingninjas.com/studio/problems/search-in-a-sorted-2d-matrix_6917532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf 

Time Complexity: O(log (M * N))
Space Cmplexity: O(1)
*/

bool searchElement(vector<vector<int>> &MATRIX, int target) {
    int n = MATRIX.size();
    int m = MATRIX[0].size();

    int low = 0, high = (n * m) - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(MATRIX[mid / m][mid % m] == target) return true;
        if(target > MATRIX[mid / m][mid % m]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}