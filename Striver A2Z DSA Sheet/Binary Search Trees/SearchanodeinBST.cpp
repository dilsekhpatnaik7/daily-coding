/*
Problem Link: https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1

Time Complexity: O(log(N))
Space Complexity: O(N)
*/

struct Node* solve(struct Node* root, int x) {
    if(!root || root->data == x) return root;
    
    
    if(x < root->data) return solve(root->left, x);
    else return solve(root->right, x);
}

bool search(struct Node* root, int x) {
    struct Node* ans = solve(root, x);
    return ans && ans->data == x;
}