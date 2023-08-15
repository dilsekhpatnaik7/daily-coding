/*
Problem Link: https://www.codingninjas.com/studio/problems/maximum-nesting-depth-of-the-parentheses_8144741?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

int maxDepth(string s) {
	int count = 0, ans = INT_MIN;;
	for(char ch: s){
		if(ch == '(') count++;
		else if(ch == ')') count--;
		ans = max(ans, count);
	}
	return ans;
}