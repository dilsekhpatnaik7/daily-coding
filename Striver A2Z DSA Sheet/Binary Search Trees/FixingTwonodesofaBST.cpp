/*
Problem Link: https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    void inorder(struct Node* root, struct Node*& first, struct Node*& second, struct Node*& prev) {
        if(!root) return;
        inorder(root->left, first, second, prev);

        if(prev && root->data < prev->data) {
            if(!first) {
                first = prev;
                second = root;
            } else second = root;
        }
        prev = root;
        inorder(root->right, first, second, prev);
    }
  
    void correctBST( struct Node* root ) {
        struct Node* first = nullptr;
        struct Node* second = nullptr;
        struct Node* prev = nullptr;
        
        inorder(root, first, second, prev);
        swap(first->data, second->data);
    }
};