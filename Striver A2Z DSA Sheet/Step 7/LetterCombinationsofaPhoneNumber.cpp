/*
Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Time Complexity: O(2 ^ N + N)
Space Complexity: O(2 ^ N + N + N)
*/

class Solution {
public:
    void solve(int index, string temp, string& digits, vector<string>& map, vector<string>& ans) {
        if(index == digits.length()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[index] - '0';
        for(auto i: map[digit]) {
            temp.push_back(i);
            solve(index + 1, temp, digits, map, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string> ans;
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, "", digits, map, ans);
        return ans;
    }
};