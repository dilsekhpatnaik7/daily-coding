/*
Exactly Same As: Allocate Books
Problem Link: https://www.codingninjas.com/studio/problems/largest-subarray-sum-minimized_7461751?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N * log(N))
Space Cmplexity: O(1)
*/

bool canSplit(vector<int>& a, long long maxCapacity, int ways) {
    int n = a.size(), capacity = 0, calculatingWays = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] + capacity <= maxCapacity) capacity += a[i];
        else {
            calculatingWays++;
            capacity = a[i];
        }
        if(calculatingWays > ways) return true;
    }
    return false;
}

int largestSubarraySumMinimized(vector<int> a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(canSplit(a, mid, k)) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}