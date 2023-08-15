/*
Problem Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
public:
    int maxDepth(string s) {
        int count = 0, ans = INT_MIN;;
        for(char ch: s){
            if(ch == '(') count++;
            else if(ch == ')') count--;
            ans = max(ans, count);
        }
        return ans;
    }
};