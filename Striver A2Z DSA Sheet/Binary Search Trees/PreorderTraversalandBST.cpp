/*
Problem Link: https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        stack<int> s;
        int low = INT_MIN;
    
        for(int i = 0; i < N; i++) {
            if(arr[i] < low) return false;
            
            while(!s.empty() && arr[i] > s.top()) {
                low = s.top();
                s.pop();
            }
            s.push(arr[i]);
        }
        return true;
    }
};