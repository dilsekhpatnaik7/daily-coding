// Problem Link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/0?qa-rewrite=3336/print-all-valid-combinations-of-ip-address&show=3350&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-product-subarray

class Solution{
public:
	long long maxProduct(vector<int> arr, int n) {
	    long long ans = INT_MIN, currentProduct = 1;
        for(int i = 0; i < n; i++) {
            currentProduct *= arr[i];
            ans = max(ans, currentProduct);
            if(currentProduct == 0) currentProduct = 1;
        }
        currentProduct = 1;
        for(int i = n - 1; i >= 0; i--) {
            currentProduct *= arr[i];
            ans = max(ans, currentProduct);
            if(currentProduct == 0) currentProduct = 1;
        }
        return ans;
	}
};