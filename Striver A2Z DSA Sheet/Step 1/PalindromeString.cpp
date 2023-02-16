// Problem Link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=palindrome-string

class Solution{
public:	
	int isPalindrome(string S) {
	    string x = S;
	    reverse(x.begin(), x.end());
	    return x == S;
	}
};