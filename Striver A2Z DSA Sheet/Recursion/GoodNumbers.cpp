/*
Problem Link: https://www.codingninjas.com/studio/problems/good-numbers_625508?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(log(N))
Space Cmplexity: O(N)
*/

bool isGood(int x, int D, int sum){
	if(x == 0)
		return true;
	int temp = x % 10;
	if(temp <= sum or temp == D)
		return false;
	
	return isGood( x/10, D, sum+temp );
}

vector<int> goodNumbers(int a, int b, int digit) {
	vector<int> ans;
	for(int i = a; i <= b; i++){
		if(i % 10 == digit)   
			continue;
		if(isGood(i / 10, digit, i % 10))
			ans.push_back(i);
	}
	return ans;
}