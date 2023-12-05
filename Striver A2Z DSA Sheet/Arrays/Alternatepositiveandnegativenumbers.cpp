// Problem Link: https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=array-of-alternate-ve-and-ve-nos

class Solution{
public:
	void rearrange(int arr[], int n) {
	    queue<int>a, b;
	    for(int i=0;i<n;i++) {
	        if(arr[i] >= 0){
	            a.push(arr[i]);
	        }
	        else{
	            b.push(arr[i]);
	        }
	    }
	    for(int i = 0; i < n;) {
	        if(!a.empty()){
	            arr[i++] = a.front();
	            a.pop();
	        }
	        if(!b.empty()) {
	            arr[i++] = b.front();
	            b.pop();
	        }
	    }
	}
};