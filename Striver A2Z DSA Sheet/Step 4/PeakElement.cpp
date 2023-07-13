// Problem Link: https://practice.geeksforgeeks.org/problems/peak-element/1

class Solution {
public:
    int binarySearch(int arr[], int low, int high) {
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid  + 1])) return mid;
            
            if(arr[mid] > arr[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    
    int peakElement(int arr[], int n) {
        if(n <= 1) return 0;
        if(arr[0] >= arr[1]) return 0;
        if(arr[n - 1] > arr[n - 2]) return n - 1;
        
        return binarySearch(arr, 1, n - 2);
    }
};