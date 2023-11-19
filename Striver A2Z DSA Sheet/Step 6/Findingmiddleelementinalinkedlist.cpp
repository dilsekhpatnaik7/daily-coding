/*
Problem Link: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
    public:
    int getMiddle(Node *head) {
        Node* slow = head;
        Node* fast = head;
    
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};