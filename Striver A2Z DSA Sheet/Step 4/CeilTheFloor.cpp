// Problem Link: https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr, arr + n);
    int low = 0, high = n - 1, flooor = -1, ceilll = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) return make_pair(arr[mid], arr[mid]);
        else if(arr[mid] < x) low = mid + 1, flooor = mid;
        else high = mid - 1, ceilll = mid;
    }
    if(ceilll != -1) ceilll = arr[ceilll];
    if(flooor != -1) flooor = arr[flooor];
    return make_pair(flooor, ceilll);
}