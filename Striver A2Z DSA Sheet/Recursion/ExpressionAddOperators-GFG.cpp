/*
Problem Link: https://practice.geeksforgeeks.org/problems/expression-add-operators/1

Time Complexity: O(N^4)
Space Complexity: O(N)
*/


#include <bits/stdc++.h>
using namespace std;

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
  
    vector<string> addOperators(string S, int target) {
        vector<string> ans;
        string str = "";
        solve(S, target, str, ans, 0, 0, 0);
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}