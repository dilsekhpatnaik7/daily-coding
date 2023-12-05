/*
Problem Link: https://www.codingninjas.com/studio/problems/combination-sum_981296?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N + N ^ 2)
*/

void solve(int index, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    if(index == arr.size()) {
        if(target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    if(arr[index] <= target) {
        ds.push_back(arr[index]);
        solve(index, target - arr[index], arr, ds, ans);
        ds.pop_back();
    }
    solve(index + 1, target, arr, ds, ans);
}

vector<vector<int>> combSum(vector<int> &ARR, int B) {
    sort(ARR.begin(), ARR.end());
    vector<int> ds;
    vector<vector<int>> ans;
    solve(0, B, ARR, ds, ans);

    return ans;
}