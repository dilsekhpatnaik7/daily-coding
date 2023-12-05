/*
Problem Link: https://www.codingninjas.com/studio/problems/longest-common-prefix_628874?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(len(arr[0]) * N)
Space Cmplexity: O(1)
*/

string commonPrefix(vector<string>& arr,int n){
	string ans = "";
	for(int i = 0; i < arr[0].length(); i++) {
		char ch = arr[0][i];
		bool match = true;

		for(int j = 1; j < n; j++) {
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
