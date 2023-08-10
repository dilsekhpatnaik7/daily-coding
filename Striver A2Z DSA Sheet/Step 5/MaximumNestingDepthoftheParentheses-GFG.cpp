/*
Problem Link: https://practice.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
  public:
    int maxDepth(string s) {
        int ans = INT_MIN, count = 0;
        for(auto ch: s) {
            if(ch == '(') count++;
            else if(ch == ')') count--;
            
            ans = max(ans, count);
        }
        return ans;
    }
};