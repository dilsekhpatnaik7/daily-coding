// Problem Link: https://practice.geeksforgeeks.org/problems/square-root/1

long long binarySearch(long long x) {
    int low = 0, high = x, ans = -1;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;
        if(square == x) return mid;
        
        if(square < x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

long long int floorSqrt(long long int x) {
    return binarySearch(x);
}