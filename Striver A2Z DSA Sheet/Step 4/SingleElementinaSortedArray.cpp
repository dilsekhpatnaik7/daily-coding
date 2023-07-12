// Problem Link: https://www.codingninjas.com/studio/problems/unique-element-in-sorted-array_1112654?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int binarySearch(vector<int>& arr, int low, int high) {
	while(low <= high) {
		long long mid = low + (high - low) / 2;
		if((arr[mid] != arr[mid - 1]) && (arr[mid] != arr[mid + 1])) return arr[mid];

		if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

int singleNonDuplicate(vector<int>& arr) {
	int n = arr.size();
	if(n == 1) return arr[0];
	if(arr[0] != arr[1]) return arr[0];
	if(arr[n - 1] != arr[n - 2]) return arr[n - 1];

	return binarySearch(arr, 1, n - 2);
}