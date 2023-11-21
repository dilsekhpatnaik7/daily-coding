/*
Problem Link: https://www.codingninjas.com/studio/problems/sort-linked-list_625193?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*log(N))
Space Complexity: O(N)
*/

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
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

Node* mergeSort(Node* head) {
    if(!head || !head->next) return head;

    Node* mid = getMiddle(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    return merge(left, right);
}

Node* sortList(Node* head) {
    return mergeSort(head);
}