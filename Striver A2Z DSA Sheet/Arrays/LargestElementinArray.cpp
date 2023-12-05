// Problem Link: https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-element-in-array

class Solution {
public:
    int largest(vector<int> &arr, int n) {
        return *max_element(begin(arr), end(arr));
    }
};