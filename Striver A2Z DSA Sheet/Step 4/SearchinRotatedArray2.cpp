// Problem Link: https://practice.geeksforgeeks.org/problems/search-in-rotated-array-2/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-rotated-array

class Solution {
public:
    bool binarySearch(vector<int>& A, int low, int high, int key) {
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(key == A[mid]) return true;
            if(A[low] == A[mid] && A[mid] == A[high]) {
                low++;
                high--;
                continue;
            }
            if(A[low] <= A[mid]) {
                if((A[low] <= key) && (key <= A[mid])) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if((A[mid] <= key) && (key <= A[high])) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }   
  
    bool Search(int N, vector<int>& A, int Key) {
        return binarySearch(A, 0, N - 1, Key);
    }
};