/*
Problem Link: https://www.codingninjas.com/studio/problems/longest-string-chain_3752111?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

bool check(string& s, string& t) {
    if(s.size() != t.size() + 1) return false;

    int first = 0, second = 0;
    while(first < s.size()) {
        if(second < t.size() && s[first] == t[second]) {
            first++;
            second++;
        } else {
            first++;
        }
    }
    if(first == s.size() && second == t.size()) return true;
    return false;
}

bool comp(string& s, string& t) {
    return s.size() < t.size();
}

int longestStrChain(vector<string> &arr){
    sort(arr.begin(), arr.end(), comp);

    int n = arr.size();
    vector<int> dp(n, 1);
	int maxi = 1;
	for(int i = 0; i < n; i++) {
		for (int prev = 0; prev < i; prev++) {
			if(check(arr[i], arr[prev]) && dp[prev] + 1 > dp[i]) {
				dp[i] = dp[prev] + 1;
			}
		}
		if(dp[i] > maxi) {
			maxi = dp[i];
		}
	}
    return maxi;
}