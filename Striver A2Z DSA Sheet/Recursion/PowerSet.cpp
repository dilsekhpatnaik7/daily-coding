/*
Problem Link: https://practice.geeksforgeeks.org/problems/power-set4302/1

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N + N)
*/

class Solution{
	public:
	void generateAllSubsequences(int index, string temp, string s, vector<string>& ans) {
        if(index == s.length()) {
            ans.push_back(temp);
            return;
        }
        generateAllSubsequences(index + 1, temp + s[index], s, ans);
        generateAllSubsequences(index + 1, temp, s, ans);
    }
    
	vector<string> AllPossibleStrings(string s){
        vector<string> ans;
        string temp = "";
        
        generateAllSubsequences(0, temp, s, ans);
        sort(ans.begin(), ans.end());
        ans.erase(ans.begin());
        return ans;
	}
};