/*
Problem Link: https://leetcode.com/problems/linked-list-cycle/description/

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};