/*
Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

Time Complexity: O(N)
Space Complexity: O(1)
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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextNode = current->next;

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

    ListNode* getKNode(ListNode* temp, int k) {
        k -= 1;
        while(temp && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        while(temp) {
            ListNode* kNode = getKNode(temp, k);
            if(!kNode) {
                if(prevLast) prevLast->next = temp;
                break;
            } 

            ListNode* nextNode = kNode->next;
            kNode->next = nullptr;
            reverseList(temp);
            if(temp == head) {
                head = kNode;
            } else {
                prevLast->next = kNode;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};