/*
Problem Link: https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

Time Complexity: O(len(arr[0]) * N)
Space Cmplexity: O(1)
*/

class Solution {
  public:
    string longestCommonPrefix (string arr[], int N) {
        string ans = "";
    	for(int i = 0; i < arr[0].length(); i++) {
    		char ch = arr[0][i];
    		bool match = true;
    
    		for(int j = 1; j < N; j++) {
    			if(arr[j].length() < i || ch != arr[j][i]) {
    				match = false;
    				break;
    			}
    		}
    		if(match == false) break;
    		else ans.push_back(ch);
    	}
    	return ans != "" ? ans : "-1";
    }
};