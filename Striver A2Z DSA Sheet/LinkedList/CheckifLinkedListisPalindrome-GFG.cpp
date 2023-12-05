/*
Problem Link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
  public:
    Node* getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* reverseList(Node* head) {
        if(!head) return nullptr;

        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = current->next;

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
    
    bool isPalindrome(Node *head) {
        Node* mid = getMiddle(head);
        Node* secondHead = reverseList(mid);

        while(head && secondHead) {
            if(head->data != secondHead->data) return false;
            head = head->next;
            secondHead = secondHead->next;
        }
        return true;
    }
};