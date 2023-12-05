/*
Problem Link: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

int findCeil(struct Node* root, int input) {
    int ceil = -1;
    while(root) {
        if(root->data == input) {
            return root->data;
        }
        if(input > root->data) root = root->right;
        else {
            ceil = ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}