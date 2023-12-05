/*
Problem Link: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
    public:
    string reverseWords(string S) { 
        string ans = "";
        int i = 0, n = S.length();

        while(i < n) {
            while(i < n && S[i] == '.') i++;
            if(i >= n) break;

            int j = i + 1;
            while(j < n && S[j] != '.') j++;
            string sub = S.substr(i, j - i);
            if(!ans.length()) ans = sub;
            else ans = sub + "." + ans;

            i = j + 1;
        }
        return ans;
    } 
};