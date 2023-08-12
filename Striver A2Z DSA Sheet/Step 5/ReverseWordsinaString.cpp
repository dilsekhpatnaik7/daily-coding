/*
Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0, n = s.length();

        while(i < n) {
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;

            int j = i + 1;
            while(j < n && s[j] != ' ') j++;
            string sub = s.substr(i, j - i);
            if(!ans.length()) ans = sub;
            else ans = sub + " " + ans;

            i = j + 1;
        }
        return ans;
    }
};