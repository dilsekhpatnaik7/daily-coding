/*
Problem Link: https://www.codingninjas.com/studio/problems/search-in-a-2d-matrix_980531?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
Time Complexity: O(log (M * N))
Space Cmplexity: O(1)
*/

bool searchMatrix(vector<vector<int>>& mat, int target) {
    if(!mat.size()) return false;
        
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = (n * m) - 1;
    while(low <= high) {
        int mid = (high + low) / 2;
        if(mat[mid / m][mid % m] == target) return true;
        else if(mat[mid / m][mid % m] < target) 
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}