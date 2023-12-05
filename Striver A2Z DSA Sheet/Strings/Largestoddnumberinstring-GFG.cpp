/*
Problem Link: https://practice.geeksforgeeks.org/problems/largest-odd-number-in-string/1

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
  public:
    string maxOdd(string s) {
        for(int i = s.length() - 1; i >= 0; i--) {
           if (s[i] % 2 != 0) return s.substr(0, i + 1);
        } 
        return "";   
    }
};