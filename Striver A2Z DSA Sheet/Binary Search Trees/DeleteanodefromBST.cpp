/*
Problem Link: https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1

Time Complexity: O(log(N))
Space Complexity: O(N)
*/

Node* findLastRight(Node* root) {
    while(root->right) root = root->right;
    return root;
}

Node* solve(Node* root) {
    if(!root->left) return root->right;
    if(!root->right) return root->left;

    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    
    return root->left;
}

Node *deleteNode(Node *root, int X) {
    if(!root) return root;

    if(root->data == X) return solve(root);
    Node* node = root;
    while(root) {
        if(X > root->data) {
            if(root->right && root->right->data == X) {
                root->right = solve(root->right);
                break;
            } else root = root->right;
        } else {
            if(root->left && root->left->data == X) {
                root->left = solve(root->left);
                break;
            } else root = root->left;
        }
    }
    return node;
}