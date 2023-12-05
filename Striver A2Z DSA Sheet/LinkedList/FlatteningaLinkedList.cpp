/*
Problem Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

Node* merge(Node* first, Node* second) {
    Node* temp = new Node(-1);
    Node* res = temp;
    
    while(first && second) {
        if(first->data <= second->data) {
            temp->bottom = first;
            first = first->bottom;
        } else {
            temp->bottom = second;
            second = second->bottom;
        }
        temp = temp->bottom;
    }
    
    temp->bottom = first ? first : second;
    return res->bottom;
}

Node* solve(Node* root) {
    if(!root || !root->next) return root;
    
    root->next = solve(root->next);
    root = merge(root, root->next);
    return root;
}

Node *flatten(Node *root) {
    return solve(root);
}