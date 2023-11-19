/*
Problem Link: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    bool detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
    
            if(slow == fast) return true;
        }
        return false;	
    }
};