/*
Problem Link: https://practice.geeksforgeeks.org/problems/preorder-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=preorder-traversal

Time Complexity: O(N)
Space Complexity: O(1)
*/

vector <int> preorder(Node* root) {
    if(!root) return {};

    vector<int> ans;
    Node* node = root;
    while(node) {
        if(!node->left) {
            ans.push_back(node->data);
            node = node->right;
        } 
        else {
            Node* prev = node->left;
            while(prev->right && prev->right != node) {
                prev = prev->right;
            }

            if(!prev->right) {
                prev->right = node;
                ans.push_back(node->data);
                node = node->left;
            } else {
                prev->right = NULL;
                node = node->right;
            }
        }
    }
    return ans;
}