// Problem Link: https://www.codingninjas.com/studio/problems/rose-garden_2248080?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

bool isPossible(vector<int>& arr, int day, int k, int m) {
	int count = 0, noOfBouquets = 0;
	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] <= day) count++;
		else {
			noOfBouquets += (count / k);
			count = 0;
		}
	}
	noOfBouquets += (count / k);
	return noOfBouquets >= m;
}

int roseGarden(vector<int> arr, int k, int m) {
	if((k * m) > arr.size()) return -1;
	int minimum = INT_MAX, maximum = INT_MIN;
	for(int i = 0; i < arr.size(); i++) {
		minimum = min(minimum, arr[i]);
		maximum = max(maximum, arr[i]);
	}

	int low = minimum, high = maximum;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(isPossible(arr, mid, k , m)) high = mid - 1;
		else low = mid + 1; 
	}
	return low;
}