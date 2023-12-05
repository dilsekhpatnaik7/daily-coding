// Problem Link: https://practice.geeksforgeeks.org/problems/element-appearing-once2552/0?company[]=Qualcomm&company[]=Qualcomm&difficulty[]=1&page=1&query=company[]Qualcommdifficulty[]1page1company[]Qualcomm&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=element-appearing-once

// As the array is given in sorted fashion we use binary search to find the single element.
class Solution{
public:	
	int search(int A[], int N){
	    int left = 0, right = N - 1;
	    while(left < right) {
	        int mid = (left + right) / 2;
	        if((mid % 2 == 0 && A[mid] == A[mid + 1]) || (mid % 2 == 1 && A[mid] == A[mid - 1]))
	            left = mid + 1;
	        else right = mid;
	    }
	    return A[left];
	}
};