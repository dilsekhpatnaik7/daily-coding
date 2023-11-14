/*
Problem Link: https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        if(!root) return {};

        vector<int> v;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* node = q.front(); q.pop();
            if(!node) v.push_back(-1);
            else {
                v.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            }
        }
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int> &A) {
        if(A.size() == 0) return nullptr;
        
        int i = 0;
        Node* root = new Node(A[i]);
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* node = q.front(); q.pop();
            
            int element = A[++i];
            if(element != -1) {
                node->left = new Node(element);
                q.push(node->left);
            } else {
                node->left = NULL;
            }
            
            element = A[++i];
            if(element != -1) {
                node->right = new Node(element);
                q.push(node->right);
            } else {
                node->right = NULL;
            }
        }
        return root;
    }
};