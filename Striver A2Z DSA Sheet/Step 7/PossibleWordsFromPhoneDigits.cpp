/*
Problem Link: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1

Time Complexity: O(2 ^ N + N)
Space Complexity: O(2 ^ N + N + N)
*/

class Solution {
    public:
    void solve(int index, string str, int a[], int N, vector<string>& map, vector<string>& ans) {
        if(index ==  N){
            ans.push_back(str);
            return;
        }
    
        int digit = a[index];
    
        for(auto i: map[digit]) {
            str.push_back(i);
            solve(index + 1, str, a, N, map, ans);
            str.pop_back();
        }
    }
    
    vector<string> possibleWords(int a[], int N) {
        if(N == 0) return {};
        vector<string> ans;
        vector<string> map = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, "", a, N, map, ans);
        return ans;
    }
};