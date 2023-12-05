// Problem Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inversion-of-array

class Solution{
public:
    long long merge(long long arr[], long long low, long long mid, long long high) {
        vector<long long> temp;
        long long left = low; 
        long long right = mid + 1;  
        long long cnt = 0;
    
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return cnt;
    }

    long long mergeSort(long long arr[], long long low, long long high) {
        long long cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid); 
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);  
        return cnt;
    }
    
    long long int inversionCount(long long arr[], long long n) {
        return mergeSort(arr, 0, n - 1);
    }
};