/*
Exactly Same As: Allocate Books (https://www.codingninjas.com/studio/problems/allocate-books_1090540?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf)
Problem Link: https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N * log(N))
Space Cmplexity: O(1)
*/

bool canPaint(vector<int>& boards, long long maxCapacity, int ways) {
    int n = boards.size(), capacity = 0, calculatingWays = 1;
    for(int i = 0; i < n; i++) {
        if(boards[i] + capacity <= maxCapacity) capacity += boards[i];
        else {
            calculatingWays++;
            capacity = boards[i];
        }
        if(calculatingWays > ways) return true;
    }
    return false;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(canPaint(boards, mid, k)) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}