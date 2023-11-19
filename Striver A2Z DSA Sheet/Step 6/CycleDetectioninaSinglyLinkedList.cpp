/*
Problem Link: https://www.codingninjas.com/studio/problems/cycle-detection-in-a-singly-linked-list_628974?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
bool detectCycle(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;	
}