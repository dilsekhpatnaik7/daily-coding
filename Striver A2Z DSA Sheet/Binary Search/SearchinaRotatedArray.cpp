// Problem Link: https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-a-rotated-array

class Solution {
public:
    int search(int A[], int low, int high, int key) {
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(A[mid] == key) return mid;
            if(A[low] <= A[mid]) {\
                if(A[low] <= key && key <= A[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if(A[mid] <= key && key <= A[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};