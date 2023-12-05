// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n==0 ||  n==1)  return 0;
        if(arr[0] == 0) return -1;
        
        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 0;
       
        for(int i = 1; i < n; i++){
           if(i == n-1)  return jumps+1;
           steps--;
           maxReach = max(maxReach, arr[i] + i);
           if(steps==0){
               if(i==maxReach) return -1;
               jumps++;
               steps= maxReach-i;
            }
        }
    }
};