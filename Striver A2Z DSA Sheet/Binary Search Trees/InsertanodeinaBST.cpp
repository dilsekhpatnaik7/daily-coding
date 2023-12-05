/*
Problem Link: https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(!root) return new Node(data);
        
        Node* node = root;
        while(true) {
            if(node->data == data) break;
            
            if(data >= node->data) {
                if(node->right) node = node->right;
                else {
                    node->right = new Node(data);
                    break;
                }
            } else {
                if(node->left) node = node->left;
                else {
                    node->left = new Node(data);
                    break;
                }
            }
        }
        return root;
    }
};