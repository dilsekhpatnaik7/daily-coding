/*
Exactly Same As: Allocate Books (https://www.geeksforgeeks.org/allocate-minimum-number-pages/)
Problem Link: https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

Time Complexity: O(N * log(N))
Space Cmplexity: O(1)
*/

class Solution {
public:
    long long max(long long a, int b) {
        return a >= b ? a : b;
    }
  
    long long findMax(int arr[], int n) {
        long long maximum = INT_MIN;
        for(int i = 0; i < n; i++) {
            maximum = max(maximum, arr[i]);
        }
        return maximum;
    }    
    
    long long summation(int arr[], int n) {
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        return sum;
    }
    
    bool canSplit(int arr[], int n, long long maxCapacity, int ways) {
        long long capacity = 0, calculatingWays = 1;
        for(int i = 0; i < n; i++) {
            if(arr[i] + capacity <= maxCapacity) capacity += arr[i];
            else {
                calculatingWays++;
                capacity = arr[i];
            }
            if(calculatingWays > ways) return true;
        }
        return false;
    }
    
    long long minTime(int arr[], int n, int k) {
        long long low = findMax(arr, n);
        long long high = summation(arr, n);
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(canSplit(arr, n, mid, k)) low = mid + 1;
            else high = mid -1;
        }
        return low;
    }
};