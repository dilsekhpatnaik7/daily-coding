/*
Problem Link: https://leetcode.com/problems/kth-missing-positive-number/

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
public:
    bool howManyMissing(int value, int index, int k) {
        return value - (index + 1) < k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (howManyMissing(arr[mid], mid, k)) low = mid + 1;
            else high = mid - 1;
        }
        return low + k;
    }
};