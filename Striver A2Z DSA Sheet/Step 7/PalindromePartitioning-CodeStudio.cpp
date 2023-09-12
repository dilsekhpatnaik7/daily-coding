/*
Problem Link: https://www.codingninjas.com/studio/problems/palindrome-partitioning_626181?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N + N)
Space Complexity: O(2 ^ N + N + N ^ 2)
*/

bool isPalindrome(string& s, int low, int high) {
    while(low <= high) {
        if(s[low++] != s[high--]) return false;
    }
    return true;
}

void solve(int index, string s, vector<string>& temp, vector<vector<string>>& ans) {
    if(index == s.length()) {
        ans.push_back(temp);
    }

    for(int i = index; i < s.length(); i++) {
        if(isPalindrome(s, index, i)) {
            temp.push_back(s.substr(index, i - index + 1));
            solve(i + 1, s, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> temp;
    vector<vector<string>> ans;
    solve(0, s, temp, ans);
    return ans;
}