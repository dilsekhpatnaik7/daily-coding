// Problem Link: https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
    int findOccurence(int arr[], int n, int target, bool findStartIndex) {
        int low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) {
                ans = mid;
                if(findStartIndex) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if(arr[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return ans;
    }
    
	int count(int arr[], int n, int x) {
	    int firstPosition = findOccurence(arr, n, x, true);
	    int lastPosition = findOccurence(arr, n, x, false);
	    if(firstPosition != -1 && lastPosition != -1) return lastPosition - firstPosition + 1;
	    else return 0;
	}
};