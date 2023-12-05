/*
Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/description/

Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode* slow, ListNode* node) {
        while(slow != node) {
            slow = slow->next;
            node = node->next;
        }
        return node;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* node = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return solve(slow, node);
            }
        }
        return nullptr;
    }
};