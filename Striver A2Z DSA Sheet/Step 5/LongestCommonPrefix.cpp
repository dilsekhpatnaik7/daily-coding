/*
Problem Link: https://leetcode.com/problems/longest-common-prefix/

Time Complexity: O(len(strs[0]) * N)
Space Cmplexity: O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            bool match = true;

            for(int j = 1; j < strs.size(); j++) {
                if(strs[j].length() < i || ch != strs[j][i]) {
                    match = false;
                    break;
                }
            }
            if(match == false) break;
            else ans.push_back(ch);
        }
        return ans;
    }
};