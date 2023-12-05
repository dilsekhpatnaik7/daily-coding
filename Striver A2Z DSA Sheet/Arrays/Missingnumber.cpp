// Problem Link: https://practice.geeksforgeeks.org/problems/missing-number4257/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=missing-number

int missingNumber(int A[], int N) {
    int actualSum = (N * (N + 1)) / 2;
    int givenSum = 0;
    for(int i = 0; i < N - 1; i++) {
        givenSum += A[i];
    }
    return actualSum - givenSum;
}