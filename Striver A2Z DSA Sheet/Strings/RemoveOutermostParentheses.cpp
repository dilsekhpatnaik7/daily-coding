/*
Problem Link: https://leetcode.com/problems/remove-outermost-parentheses/description/

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for(char ch: s){
            if(ch == '(' && count == 0){
                count++;
            }else if(ch == '(' && count >= 1){
                ans += ch;
                count++;
                
            }else if(ch == ')' && count > 1){
                ans += ch;
                count--;
            }else if(ch == ')' && count == 1){
                count--;
            }
        }
        return ans;
    }
};