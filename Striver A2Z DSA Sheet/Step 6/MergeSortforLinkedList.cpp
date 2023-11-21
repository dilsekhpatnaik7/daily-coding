/*
Problem Link: https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

Time Complexity: O(N*log(N))
Space Complexity: O(N)
*/

class Solution{
  public:
    Node* merge(Node* list1, Node* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
    
        Node* dummy = new Node(-1);
        Node* current = dummy;
    
        while(list1 && list2) {
            if(list1->data <= list2->data) {
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
    
    Node* getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;
    
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
    
        if(prev) prev->next = nullptr;
        return slow;
    }
    
    Node* solve(Node* head) {
        if(!head || !head->next) return head;
    
        Node* mid = getMiddle(head);
        Node* left = solve(head);
        Node* right = solve(mid);
    
        return merge(left, right);
    }
  
    Node* mergeSort(Node* head) {
        return solve(head);
    }
};