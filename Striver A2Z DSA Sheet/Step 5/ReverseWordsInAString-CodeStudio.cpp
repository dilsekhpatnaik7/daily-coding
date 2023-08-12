/*
Problem Link: https://www.codingninjas.com/studio/problems/reverse-words-in-a-string_696444?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

string reverseString(string &str) {
	stringstream s(str);
	vector<string> tokens;
	string token;
	string ans;

	while(s >> token) {
		tokens.push_back(token);
	}
	reverse(tokens.begin(),tokens.end());
	for(const string & pointer:tokens) {
		if(!ans.empty()) {
			ans += " ";
		}
		ans += pointer;
	}
	return ans;
}