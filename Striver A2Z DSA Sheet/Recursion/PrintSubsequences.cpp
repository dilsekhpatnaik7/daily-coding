/*
Problem Link: https://www.codingninjas.com/studio/problems/print-subsequences_8416366?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N + N)
*/

void generateAllSubsequences(int index, string temp, string s, vector<string>& ans) {
    if(index == s.length()) {
        ans.push_back(temp);
        return;
    }
    generateAllSubsequences(index + 1, temp + s[index], s, ans);
    generateAllSubsequences(index + 1, temp, s, ans);
}

vector<string> generateSubsequences(string s) {
    vector<string> ans;
    string temp = "";
    generateAllSubsequences(0, temp, s, ans);
    return ans;
}