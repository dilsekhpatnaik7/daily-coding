// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-element-in-a-sorted-and-rotated-array

class Solution{
public:
    int binarySearch(int arr[], int low, int high) {
        int ans = INT_MAX;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]);
                low = mid + 1;
            } else {
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
    
    int findMin(int arr[], int n) {
        return binarySearch(arr, 0, n - 1);
    }
};