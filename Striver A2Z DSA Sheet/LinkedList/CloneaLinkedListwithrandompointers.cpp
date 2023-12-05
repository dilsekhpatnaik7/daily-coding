/*
Problem Link: https://www.codingninjas.com/studio/problems/clone-a-linked-list-with-random-pointers_983604?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */

Node *cloneLL(Node *head){
	if(!head) return head;

	unordered_map<Node*, Node*> map;
	Node* temp = head;
	while(temp) {
		map[temp] = new Node(temp->data);
		temp = temp->next;
	}
	temp = head;
	while(temp) {
		map[temp]->next = map[temp->next];
		map[temp]->random = map[temp->random];
		temp = temp->next;
	}
	return map[head];
}