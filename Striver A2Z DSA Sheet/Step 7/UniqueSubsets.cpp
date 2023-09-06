/*
Problem Link: https://practice.geeksforgeeks.org/problems/subsets-1587115621/1

Time Complexity: O(2 ^ N + N * log(N))
Space Complexity: O(2 ^ N + N + N ^ 2)
*/

class Solution {
    public:
    void solve(int index, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);
    
        for(int i = index; i < arr.size(); i++) {
            if(i > index && arr[i] == arr[i - 1]) continue;
            ds.push_back(arr[i]);
            solve(i + 1, arr, ds, ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n) {
        sort(arr.begin(), arr.end());
        vector<int> ds;
        vector<vector<int>> ans;
        
        solve(0, arr, ds, ans);
        return ans;
    }
};