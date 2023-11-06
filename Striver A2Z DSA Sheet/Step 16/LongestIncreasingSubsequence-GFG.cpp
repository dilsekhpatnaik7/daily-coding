/*
Problem Link: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/0

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    int longestSubsequence(int n, int a[]) {
        vector<int> temp;
        temp.push_back(a[0]);
        for(int i = 1; i < n; i++) {
            if(a[i] > temp.back()) temp.push_back(a[i]);
            else {
                int index = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
                temp[index] = a[i];
            }
        }
        return temp.size();
    }
};