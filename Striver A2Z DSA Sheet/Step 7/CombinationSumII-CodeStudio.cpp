/*
Problem Link: https://www.codingninjas.com/studio/problems/combination-sum-ii_1112622?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N + N * log(N) )
Space Complexity: O(2 ^ N + N + N ^ 2)
*/

#include<bits/stdc++.h>

void getUniqueCombinations(int index, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans) {
    if(index == candidates.size()) {
        if(target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    if(candidates[index] <= target) {
        ds.push_back(candidates[index]);
        getUniqueCombinations(index + 1, candidates, target - candidates[index], ds, ans);
        ds.pop_back();
    }

    while(index + 1 < candidates.size() && candidates[index + 1] == candidates[index]) index++;

    getUniqueCombinations(index + 1, candidates, target, ds, ans);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
    sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> ans;

    getUniqueCombinations(0, arr, target, ds, ans);
    return ans;
}