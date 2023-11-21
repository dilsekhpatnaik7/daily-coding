/*
Problem Link: https://leetcode.com/problems/sort-list/description/

Time Complexity: O(N*log(N))
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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        current->next = list1 ? list1 : list2;
        return dummy->next;
    }

    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev) prev->next = nullptr;
        return slow;
    }

    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = getMiddle(head);
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(mid);

        return merge(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};