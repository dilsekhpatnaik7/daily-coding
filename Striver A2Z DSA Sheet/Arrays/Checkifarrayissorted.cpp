// Problem Link: https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-if-an-array-is-sorted
/*
    GFG version of this question is slighlty different as it terminates if any element is greater than the next element.
*/
class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[i - 1]) return 0;
        }
        return 1;
    }
};