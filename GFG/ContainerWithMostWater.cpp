// Problem Link: https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

long long maxArea(long long A[], int len) {
    long long ans = 0, left = 0, right = len - 1;
    while(left <= right){
        ans = max(min(A[left], A[right]) * (right - left), ans);
        if(A[left] < A[right]) left++;
        else right--;
    }
    return ans;
}