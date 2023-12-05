/*
Similar Same As: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
Problem Link: https://www.codingninjas.com/studio/problems/allocate-books_1090540?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N * log(N))
Space Cmplexity: O(1)
*/

bool canAllocate(vector<int>& arr, long long pageCapacity, int noOfStudents) {
    int students = 1, n = arr.size();
    long long pages = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] + pages <= pageCapacity) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
        if(students > noOfStudents) return true;
    }
    return false;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(canAllocate(arr, mid, m)) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}