/*
Problem Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

Time Complexity: O(log(N))
Space Complexity: O(N)
*/

class Solution {
    public:
    Node* getPre(Node* root, int key) {
        Node* predecessor = nullptr;
        while(root) {
            if(key > root->key) {
                predecessor = root;
                root = root->right;
            } else root = root->left;
        }
        return predecessor;
    }
    
    Node* getSuc(Node* root, int key) {
        Node* successor = nullptr;
        while(root) {
            if(key >= root->key) root = root->right;
            else {
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        pre = getPre(root, key);
        suc = getSuc(root, key);
    }
};