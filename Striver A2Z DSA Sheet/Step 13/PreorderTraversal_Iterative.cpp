/*
Problem Link: https://practice.geeksforgeeks.org/problems/preorder-traversal/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

void solve(Node* root, vector<int>& ans) {
    stack<Node*> s;
    s.push(root);

    while(!s.empty()) {
        Node* node = s.top();
        s.pop();

        ans.push_back(node->data);
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
}

vector<int> preorder(Node* root) {
    if(!root) return {};

    vector<int> ans;
    solve(root, ans);
    return ans;
}