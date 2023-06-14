// Problem Link: https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

class Solution{
public:
    int binarySearch(int arr[], int n, int x, bool findStartIndex) {
        int low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == x) {
                ans = mid;
                if(findStartIndex) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if(arr[mid] < x) low = mid + 1;
                else high = mid - 1;
            }
        }
        return ans;
    }
    
	int count(int arr[], int n, int x) {
	    int startingIndex = binarySearch(arr, n, x, true);
        int endingIndex = binarySearch(arr, n, x, false);
        if(arr[startingIndex] != x || arr[endingIndex] != x) return 0;
        return endingIndex - startingIndex + 1;
	}
};