/*
Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* node = slow;

        while(fast && fast->next) {
            node = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        node->next = slow->next;
        return head;
    }
};