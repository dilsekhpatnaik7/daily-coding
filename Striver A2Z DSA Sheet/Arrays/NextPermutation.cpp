// Problem Link: https://practice.geeksforgeeks.org/problems/next-permutation5226/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=next-permutation

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int index = -1;
        for(int i = N - 2; i >=0; i--) {
            if(arr[i] < arr[i + 1]) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            sort(arr.begin(), arr.end());
        }
        else {
            int nextGreater = index;
            for(int i = N - 1; i > index; i--) {
                if(arr[i] > arr[nextGreater]) {
                    nextGreater = i;
                    break;
                }
            }
            swap(arr[index], arr[nextGreater]);
            sort(arr.begin() + index + 1, arr.end());
        }
        return arr;
    }
};