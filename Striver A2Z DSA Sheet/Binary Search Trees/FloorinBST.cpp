/*
Problem Link: https://practice.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=geeksforgeeks&utm_medium=newui_home&utm_campaign=potd

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
public:
    int floor(Node* root, int x) {
        int f = -1;
        while(root) {
            if(root->data == x) return x;
            if(x > root->data) {
                f = root->data;
                root = root->right;
            } else root = root->left;
        }
        return f;
    }
};