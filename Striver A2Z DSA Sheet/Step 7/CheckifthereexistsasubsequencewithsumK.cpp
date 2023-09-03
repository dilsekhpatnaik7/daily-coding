/*
Problem Link:  https://practice.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1?page=1&sortBy=newest&query=page1sortBynewest

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N)
*/

class Solution{
    public:
    bool subsetSum(int index, int sum, int k, vector<int>& a) {
        if(index == a.size()) {
            if(sum == k) return true;
            else return false;
        }
    
        if(sum <= k) {
            sum += a[index];
            if(subsetSum(index + 1, sum, k, a)) return true;
            sum -= a[index];
        }
        if(subsetSum(index + 1, sum, k, a)) return true;
    
        return false;
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return subsetSum(0, 0, k, arr);
    }
};