// Problem Link: https://practice.geeksforgeeks.org/problems/quick-left-rotation3806/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-left-rotation
/*
    In left rotation we do not use the array length while calling reverse function.
*/
class Solution{
public:
    void reverse(int arr[], int low, int high) {
        while(low < high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
	void leftRotate(int arr[], int k, int n) {
	  k = k % n;
	  if(k < 0) {
	      k += n;
	  }
	  reverse(arr, 0, k - 1);
	  reverse(arr, k, n - 1);
	  reverse(arr, 0, n - 1);
	} 
};