/*
Problem Link: https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

Node* deleteMid(Node* head) {
    if(!head || !head->next) return nullptr;

    Node* slow = head;
    Node* fast = head;
    Node* node = slow;

    while(fast && fast->next) {
        node = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    node->next = slow->next;
    return head;
}