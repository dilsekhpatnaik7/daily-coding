// Problem Link: https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=move-all-zeroes-to-end-of-array

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int k = 0;
	    for(int i = 0; i < n; i++) {
	        if(arr[i] != 0) {
	            arr[k] = arr[i];
	            k++;
	        }
	    }
	    while(k < n) {
	        arr[k++] = 0;
	    }
	}
};