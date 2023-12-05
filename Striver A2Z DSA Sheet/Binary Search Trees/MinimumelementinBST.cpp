/*
Problem Link: https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

Time Complexity: O(log(N))
Space Complexity: O(N)
*/

int minValue(Node* root) {
    if(!root) return -1;
    
    while(root->left) root = root->left;
    return root->data;
}