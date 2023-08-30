/*
Problem Link: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N)
*/

class Solution {
    public:
    void generateAllParenthesis(int open, int close, int n, string s, vector<string>& ans) {
        if(s.length() == n * 2) {
            ans.push_back(s);
            return;
        }
    
        if(open < n) {
            generateAllParenthesis(open + 1, close, n, s + '(', ans);
        }
        if(close < open) {
            generateAllParenthesis(open, close + 1, n, s + ')', ans);
        }
    }
    
    vector<string> AllParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generateAllParenthesis(0, 0, n, s, ans);
        return ans;
    }
};