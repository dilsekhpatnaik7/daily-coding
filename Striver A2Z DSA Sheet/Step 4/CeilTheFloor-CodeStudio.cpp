// Problem Link: https://www.codingninjas.com/codestudio/problems/ceiling-in-a-sorted-array_1825401?leftPanelTab=0

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	sort(arr, arr + n);
	int low = 0, high = n - 1, ceilll = -1, flooor = -1;
	while(low <= high) {
		long long mid = low + (high - low) / 2;
		if(arr[mid] == x) return {arr[mid], arr[mid]};
		else if(arr[mid] < x) {
			ceilll = arr[mid];
			low = mid + 1;
		} else if(arr[mid] > x) {
			flooor = arr[mid];
			high = mid - 1;
		}
	}
	return {ceilll, flooor};
}
