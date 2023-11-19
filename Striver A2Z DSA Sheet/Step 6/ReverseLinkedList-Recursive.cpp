/*
Problem Link: https://www.codingninjas.com/studio/problems/reverse-linked-list_920513?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/****************************************************************

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
        

*****************************************************************/
Node* solve(struct Node* head) {
    if(!head || !head->next) return head;

    Node* reversedHead = solve(head->next);
    head->next->next = head;
    head->next = NULL;

    return reversedHead;
}

Node* reverseLinkedList(Node *head) {
    return solve(head);
}