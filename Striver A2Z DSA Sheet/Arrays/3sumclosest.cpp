// Problem Link: https://practice.geeksforgeeks.org/problems/3-sum-closest/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=3-sum-closest

// Sort the array and then use the two pointer apprpach
class Solution{
public:
    int closest3Sum(int A[], int N, int X) {
        int ans = INT_MAX, res = 0;
        sort(A, A + N);
        for(int i = 0; i < N - 2; i++) {
            int low = i + 1, high = N - 1;
            while(low < high) {
                int sum = A[i] + A[low] + A[high];
                if(sum == X) return X;
                else if(sum < X) low++;
                else high--;
                
                if(abs(sum - X) < ans) {
                    ans = abs(sum - X);
                    res = sum;
                }
            }
        }
        return res;
    }
};