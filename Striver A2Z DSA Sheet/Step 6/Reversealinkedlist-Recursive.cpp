/*
Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

struct Node* solve(struct Node* head) {
    if(!head || !head->next) return head;

    struct Node* reversedHead = solve(head->next);
    head->next->next = head;
    head->next = NULL;

    return reversedHead;
}

struct Node* reverseList(struct Node *head) {
    return solve(head);
}