// Problem Link: https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);
        string b = a;
        reverse(b.begin(), b.end());
        return a == b;
    }
};