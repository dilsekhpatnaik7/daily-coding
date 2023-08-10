/*
Problem Link: https://www.interviewbit.com/problems/matrix-median/

Time Complexity: O(N * log(M))
Space Cmplexity: O(1)
*/

int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < n; i++) {
        low = min(low, A[i][0]);
        high = max(high, A[i][m - 1]);
    }
        
    int desiredAns = (n * m + 1) / 2;
    while(low < high) {
        int mid = low + (high - low) / 2;
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if(count < desiredAns) low = mid + 1;
        else high = mid;
    }
    return low;
}

