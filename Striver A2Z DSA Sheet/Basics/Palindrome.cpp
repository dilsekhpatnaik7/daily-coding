// Problem Link: https://practice.geeksforgeeks.org/problems/palindrome0746/1

class Solution {
public:
	string is_palindrome(int n) {
	    string s1 = to_string(n);
	    string s2 = s1;
	    reverse(s2.begin(), s2.end());
	    return s1 == s2 ? "Yes" : "No";
	}
};