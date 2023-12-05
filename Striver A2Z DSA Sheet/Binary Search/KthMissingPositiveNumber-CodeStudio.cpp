/*
Problem Link: https://www.codingninjas.com/studio/problems/kth-missing-element_893215?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

bool howManyMissing(int value, int index, int k) {
    return value - (index + 1) < k;
}

int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(howManyMissing(vec[mid], mid, k)) low = mid + 1;
        else high = mid - 1;
    }
    return low + k;
}
