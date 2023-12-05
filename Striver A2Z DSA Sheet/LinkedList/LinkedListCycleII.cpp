/*
Problem Link: https://www.codingninjas.com/studio/problems/linked-list-cycle-ii_1112628?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
Node* solve(Node* slow, Node* node) {
    while(slow != node) {
        slow = slow->next;
        node = node->next;
    }
    return node;
}

Node *firstNode(Node *head) {
    Node* slow = head;
    Node* fast = head;
    Node* node = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return solve(slow, node);
        }
    }
    return nullptr;
}