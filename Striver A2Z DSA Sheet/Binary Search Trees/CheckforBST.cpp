/*
Problem Link: https://www.geeksforgeeks.org/problems/check-for-bst/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    bool solve(Node* root, long long minVal, long long maxVal) {
    	if(!root) return true;
    	if(root->data >= maxVal || root->data <= minVal) return false;
    
    	return solve(root->left, minVal, root->data) && solve(root->right, root->data, maxVal);
    }

    bool isBST(Node* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};