/*
Problem Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N)
*/

class Solution {
public:
    void getSubsetSum(int index, vector<int>& arr, int sum, vector<int>& ans) {
        if(index == arr.size()) {
            ans.push_back(sum);
            return;
        }
        
        getSubsetSum(index + 1, arr, sum + arr[index], ans);
        
        getSubsetSum(index + 1, arr, sum, ans);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        getSubsetSum(0, arr, 0, ans);
        return ans;
    }
};