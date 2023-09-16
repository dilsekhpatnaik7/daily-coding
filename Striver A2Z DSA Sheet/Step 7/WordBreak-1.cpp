/*
Problem Link: https://www.codingninjas.com/studio/problems/word-break-1_758963?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

void solve(int index, string& s, set<string>& st,string& cur, vector<string>& ans, int n) {
    if(index == s.length()) {
        cur.pop_back();
        ans.push_back(cur);
        return;
    }

    string temp = "";
    for(int i = index; i < n; i++) {
        temp += s[i];
        if(st.find(temp)!=st.end()) {
            string temp2 = cur + temp + " ";
            solve(i + 1, s, st, temp2, ans, n);
        }
    }
}

vector<string> getAllValidSentences(string &s, vector<string> &dict) {
    set<string> st(dict.begin(), dict.end());
    vector<string> ans;
    string cur = "";
    int n = s.size();
    solve(0, s, st, cur, ans, n);
    return ans;
}