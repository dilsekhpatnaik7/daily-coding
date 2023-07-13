// Problem Link: https://www.codingninjas.com/studio/problems/find-peak-element_1081482?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int binarySearch(vector<int>& arr, int low, int high) {
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid + 1])) return mid;

        if(arr[mid] > arr[mid - 1]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    if(n <= 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n - 1] > arr[n - 2]) return n - 1;

    return binarySearch(arr, 1, n - 2);
}