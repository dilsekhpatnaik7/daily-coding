/*
Problem Link: https://www.codingninjas.com/studio/problems/get-all-unique-subsets_624393?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N + N * log(N))
Space Complexity: O(2 ^ N + N + N ^ 2)
*/

void solve(int index, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    ans.push_back(ds);

    for(int i = index; i < arr.size(); i++) {
        if(i > index && arr[i] == arr[i - 1]) continue;
        ds.push_back(arr[i]);
        solve(i + 1, arr, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> ans;

    solve(0, arr, ds, ans);
    return ans;
}