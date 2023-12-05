/*
Problem Link: https://www.codingninjas.com/studio/problems/subset-sum_3843086?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N)
*/

void solve(int index, int sum, vector<int>& num, vector<int>& ans) {
	if(index == num.size()) {
		ans.push_back(sum);
		return;
	}

	solve(index + 1, sum + num[index], num, ans);
	solve(index + 1, sum, num, ans);
}

vector<int> subsetSum(vector<int> &num) {
	vector<int> ans;
	solve(0, 0, num, ans);
	sort(ans.begin(), ans.end());
	return ans;
}