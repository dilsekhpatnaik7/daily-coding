/*
Problem Link: https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

Node* solve(int in[], int is, int ie, int post[], int ps, int pe, map<int, int>& m) {
    if(is > ie || ps > pe) return nullptr;

    Node* root = new Node(post[pe]);
    int inRoot = m[post[pe]];
    int numsLeft = inRoot - is;

    root->left = solve(in, is, inRoot - 1, post, ps, ps + numsLeft - 1, m);
    root->right = solve(in, inRoot + 1, ie, post, ps + numsLeft, pe - 1, m);

    return root;
}

Node *buildTree(int in[], int post[], int n) {
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        m[in[i]] = i;
    }
    
    return solve(in, 0, n - 1, post, 0, n - 1, m);
}