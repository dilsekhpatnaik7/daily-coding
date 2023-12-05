/*
Problem Link: https://www.codingninjas.com/studio/problems/sorting-characters-by-frequency_1263699?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N * log(N))
Space Cmplexity: O(N)
*/

static bool comp(pair<char, int> a, pair<char, int> b) {
    return a.second > b.second;
}

string sortByFrequency(int n, string& s) {
	if(!n) return "";
	vector<pair<char, int>> v;
	unordered_map<char,int> map;
	for(int i = 0; i < s.length(); i++) {
		map[s[i]]++;
	}
	for(auto x: map) {
		v.push_back({x.first, x.second});
	}
	sort(v.begin(), v.end(), comp);
	string ans = "";
	for(auto x: v) {
		for(int i = 0; i < x.second; i++) {
			ans += x.first;
		}
	}
	return ans;
}