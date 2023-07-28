/*
Problem Link: https://practice.geeksforgeeks.org/problems/k-th-missing-element3635/1

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

bool howManyMissing(int value, int index, int startingIndexValue, int k) {
    return (value - index - startingIndexValue) >= k;
}

int KthMissingElement(int a[], int n, int k) {
    int low = 0, high = n - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(howManyMissing(a[mid], mid, a[0], k)) high = mid - 1;
        else low = mid + 1;
    }
    return low != n ? k + low + a[0] - 1 : -1;
}