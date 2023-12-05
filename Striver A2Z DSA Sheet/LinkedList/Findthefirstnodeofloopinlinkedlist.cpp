/*
Problem Link: https://practice.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    int solve(Node* slow, Node* node) {
        while(slow != node) {
            slow = slow->next;
            node = node->next;
        }
        return node->data;
    }
    
    int findFirstNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        Node* node = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return solve(slow, node);
            }
        }
        return -1;
    }
};