/*
Problem Link: https://leetcode.com/problems/expression-add-operators/

Time Complexity: O(N^4)
Space Complexity: O(N)
*/

class Solution {
public:
    void solve(string& num, int target, string str, vector<string>& ans, int index, long acc, long poperand) {
        if(index == num.length()) {
            if(acc == target) ans.push_back(str);
            return;
        }

        for(int i = index; i < num.length(); i++) {
            string temp = num.substr(index, i - index + 1);
            if(temp.length() > 1 && temp[0] == '0') continue;

            long op = stoll(temp);
            if(index == 0) {
                solve(num, target, str + temp, ans, i + 1, acc + op, op);
                continue;
            }

            solve(num, target, str + "+" + temp, ans, i + 1, acc + op, op);
            solve(num, target, str + "-" + temp, ans, i + 1, acc - op, -op);
            solve(num, target, str + "*" + temp, ans, i + 1, acc - poperand + poperand * op, poperand * op);
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string str = "";
        solve(num, target, str, ans, 0, 0, 0);
        return ans;
    }
};