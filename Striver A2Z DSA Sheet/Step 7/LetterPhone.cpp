/*
Problem Link: https://www.codingninjas.com/studio/problems/letter-phone_626178?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N + N)
Space Complexity: O(2 ^ N + N + N)
*/

void solve(int index, string str, string& s, vector<string>& map, vector<string>& ans) {
    if(index == s.length()) {
        ans.push_back(str);
        return;
    }

    int digit = s[index] - '0';

    for(auto i: map[digit]) {
        str.push_back(i);
        solve(index + 1, str, s, map, ans);
        str.pop_back();
    }
}

vector<string> letterCombinations(string s) {
    if(s.length() == 0) return {};
    vector<string> ans;
    vector<string> map = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(0, "", s, map, ans);
    return ans;
}
