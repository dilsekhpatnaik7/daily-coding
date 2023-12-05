/*
Problem Link: https://practice.geeksforgeeks.org/problems/burning-tree/1

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
  public:
    Node* markParents(Node* root, map<Node*, Node*>& m, int target) {
        queue<Node*> q;
        q.push(root);
        Node* res = nullptr;
        
        while(!q.empty()) {
            Node* node = q.front(); q.pop();
            if(node->data == target) res = node;
            if(node->left) {
                m[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                m[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    
    int solve(Node* root, map<Node*, Node*>& m, Node* targetNode) {
        queue<Node*> q;
        q.push(targetNode);
        
        map<Node*, int> vis;
        vis[targetNode] = 1;
        int ans = 0;
        
        while(!q.empty()) {
            int size = q.size();
            int flag = 0;
            for(int i = 0; i < size; i++) {
                Node* node = q.front(); q.pop();
                if(node->left && !vis[node->left]) {
                    flag = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]) {
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(m[node] && !vis[m[node]]) {
                    flag = 1;
                    vis[m[node]] = 1;
                    q.push(m[node]);
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
  
    int minTime(Node* root, int target) {
        if(!root) return 0;
        
        map<Node*, Node*> m;
        Node* targetNode = markParents(root, m, target);
        if(!targetNode) return 0;
        
        return solve(root, m, targetNode);
    }
};