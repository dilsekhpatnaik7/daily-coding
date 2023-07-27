// Problem Link: https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1

class Solution {
public:
    int getMax(int arr[], int N) {
        int maximum = INT_MIN;
        for(int i = 0; i < N; i++) {
            maximum = max(maximum, arr[i]);
        }
        return maximum;
    }
    
    int summation(int arr[], int N) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += arr[i];
        }
        return sum;
    }
    
    bool shipDays(int arr[], int N, long long shipCapacity, int days) {
        int calculatingDays = 1, capacity = 0;
        for(int i = 0; i < N; i++) {
            if(capacity + arr[i] > shipCapacity) {
                calculatingDays++;
                capacity = arr[i];
            } else {
                capacity += arr[i];
            }
            if(calculatingDays > days) return false;
        }
        return true;
    }
    
    int leastWeightCapacity(int arr[], int N, int D) {
        int low = getMax(arr, N), high = summation(arr, N);
        while(low <= high) {
            long long mid = low + (high - low ) / 2;
            if(shipDays(arr, N, mid, D)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};