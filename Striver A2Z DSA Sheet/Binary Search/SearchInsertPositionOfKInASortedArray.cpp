// Problem Link: https://practice.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-insert-position-of-k-in-a-sorted-arrayhttps://practice.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-insert-position-of-k-in-a-sorted-array

class Solution{
public:
    int searchInsertK(vector<int>Arr, int N, int k) {
        int low = 0, high = N - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(Arr[mid] == k) return mid;
            else if(Arr[mid] < k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};