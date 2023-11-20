/*
Problem Link: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
public:
    int getNthFromLast(Node *head, int n) {
        if(!head) return -1;
        
        Node* slow = head;
        Node* fast = head;
        
        for(int i = 1; i < n; i++) {
            if(fast->next) fast = fast->next;
            else return -1;
        }
        
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
        
    }
};