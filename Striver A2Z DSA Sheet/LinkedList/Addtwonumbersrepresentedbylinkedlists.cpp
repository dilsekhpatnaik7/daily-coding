/*
Problem Link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/0

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    struct Node* reverse(struct Node* head) {
        if(!head) return head;

        struct Node* prev = nullptr;
        struct Node* current = head;
        struct Node* nextNode = current->next;
    
        while(current) {
            current->next = prev;
            prev = current;
            current = nextNode;
            if(nextNode) {
                nextNode = nextNode->next;
            }
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        first = reverse(first);
        second = reverse(second);
        int carry = 0;
        struct Node* dummy = new Node(-1);
        struct Node* head = dummy;
        
        while(first || second || carry) {
            int sum = 0;
            if(first) {
                sum += first->data;
                first = first->next;
            }
            if(second) {
                sum += second->data;
                second = second->next;
            }
            sum += carry;
            carry = sum / 10;
            struct Node* node = new Node(sum % 10);
            head->next = node;
            head = head->next;
        }
        return head = reverse(dummy->next);
    }
};