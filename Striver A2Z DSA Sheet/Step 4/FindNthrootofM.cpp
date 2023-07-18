// Problem Link: https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

class Solution{
public:
    int func(long long mid, int n, int m) {
      long long ans = 1;
      for(int i = 1; i <= n; i++) {
        ans = ans * mid;
        if(ans > m) return 2;
      }
      if(ans == (long long)(m)) return 1;
      return 0;
    }

    int binarySearch(int n, int m, int low, int high) {
      while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long val = func(mid, n, m);
        if(val == 1) return mid;
        
        if(val == 0) low = mid + 1;
        else high = mid - 1; 
      }
      return -1;
    }
	
	int NthRoot(int n, int m) {
	    return binarySearch(n, m, 0, m);
	}  
};