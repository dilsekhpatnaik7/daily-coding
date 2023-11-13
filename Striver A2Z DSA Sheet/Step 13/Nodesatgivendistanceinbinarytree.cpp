/*
Problem Link: https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    void markParents(Node* root, unordered_map<Node*, Node*>& m) {
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node->left) {
                m[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                m[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    void solve(Node* root, unordered_map<Node*, Node*>& m, Node* targetNode, int k, vector<int>& ans) {
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int currentLevel = 0;

        while(!q.empty()) {
            int size = q.size();
            if(currentLevel++ == k)
                break;

            for(int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(m[node] && !visited[m[node]]) {
                    q.push(m[node]);
                    visited[m[node]] = true;
                }
            }
        }

        while(!q.empty()) {
            Node* node = q.front(); q.pop();
            ans.push_back(node->data);
        }
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        if(!root) return {};
     
        unordered_map<Node*, Node*> m;
        markParents(root, m);

        Node* targetNode = nullptr;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node->data == target) {
                targetNode = node;
                break;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        if(!targetNode) return {};
        
        vector<int> ans;
        solve(root, m, targetNode, k, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};