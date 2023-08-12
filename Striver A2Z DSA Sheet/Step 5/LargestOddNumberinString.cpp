/*
Problem Link: https://leetcode.com/problems/largest-odd-number-in-string/

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.length() - 1; i >= 0; i--) {
           if(num[i] % 2 != 0) return num.substr(0, i + 1);
        } 
        return "";   
    }
};