// Problem Link: https://www.codingninjas.com/studio/problems/square-root-integral_893351?leftPanelTab=0%3Futm_source%3Dstriver&utm_medium=website&utm_campaign=a_zcoursetuf

int floorSqrt(int n) {
    int low = 0, high = n, ans = -1;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;
        if(square == (long long)(n)) return mid;

        if(square < (long long)(n)) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}