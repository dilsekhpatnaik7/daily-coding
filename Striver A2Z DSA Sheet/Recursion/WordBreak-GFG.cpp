/*
Problem Link: https://practice.geeksforgeeks.org/problems/word-break1352/1

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution {
public:
    int solve(int index, string& s, set<string>& set, vector<int>& dp) {
        if(index == s.length()) return 1;
        if(dp[index] != -1) return dp[index];

        string temp = "";
        for(int i = index; i < s.length(); i++) {
            temp += s[i];
            if(set.find(temp) != set.end()) {
                if(solve(i + 1, s, set, dp)) return dp[i] = 1;
            }
        }
        return dp[index] = 0;
    }
    
    int wordBreak(string A, vector<string> &B) {
        int n = A.length();
        vector<int> dp(n, -1);
        set<string> set;
        for(auto i: B) {
            set.insert(i);
        }
        return solve(0, A, set, dp);
    }
};