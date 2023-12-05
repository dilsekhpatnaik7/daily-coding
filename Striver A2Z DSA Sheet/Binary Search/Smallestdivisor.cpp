// Problem Link: https://www.codingninjas.com/studio/problems/smallest-divisor-with-the-given-limit_1755882?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

bool sumByDiv(vector<int>& arr, long long mid, int limit) {
	if(mid == 0) return false;
	int sum = 0, n = arr.size();
	for(int i = 0; i < n; i++) {
		sum += (arr[i] + mid - 1) / mid;
		if(sum > limit) return false;
	}
	return true;
}

int smallestDivisor(vector<int>& arr, int limit) {
	if(arr.size() > limit) return -1;
	int low = 0, high = *max_element(arr.begin(), arr.end());
	while(low <= high) {
		long long mid = low + (high - low) / 2;
		if(sumByDiv(arr, mid, limit)) high = mid - 1;
		else low = mid + 1;
	}
	return low;
}