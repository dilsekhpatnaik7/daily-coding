// Problem Link: https://practice.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest
/*
    Taking two variables and checking the max. value in the array between the values.
*/
class Solution{
public:
	int print2largest(int arr[], int n) {
	    // code here
	    int largest = INT_MIN;
	    int secondLargest = INT_MIN;
	    for(int i = 0; i < n; i++){
	        if(arr[i] > largest){
	            secondLargest = largest;
	            largest = arr[i];
	        }
	        else{
	            if(arr[i] > secondLargest and arr[i] < largest){
	                secondLargest = arr[i];
	            }
	        }
	        
	    }
	    return secondLargest > 0 ? secondLargest : -1;
	}
};