#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <ios>
#include <iomanip>
#include <limits>
using namespace std;

class Node {
public:
	int val;
	Node* nextNode;
};

void traverseLinkedList(Node* head) {
	Node* curNode = head;
	while (curNode != NULL) {
		cout << curNode->val << " ";
		curNode = curNode->nextNode;
	}
	cout << endl;
}

void insertNode(Node* prevNode, int newVal) {
	Node* newNode = new Node();
	newNode->val = newVal;
	newNode->nextNode = prevNode->nextNode;
	prevNode->nextNode = newNode;
}

void deleteNodeNextTo(Node* prevNode) {
	if (prevNode->nextNode != NULL) {
		prevNode->nextNode = prevNode->nextNode->nextNode;
	}
}

int main() {
    //Creating new Nodes
	Node* head = new Node();
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();

    //Filling the nodes
	head->val = 5;
	head->nextNode = node1;
	node1->val = 7;
	node1->nextNode = node2;
	node2->val = 8;
	node2->nextNode = node3;
	node3->val = 15;
	node3->nextNode = NULL;

    //Printing Each Value of Node
	traverseLinkedList(head);
    
    //Inserting new Node after Node 2 with value of 56
	insertNode(node2, 56);
	traverseLinkedList(head);
    
    //Deleting node just next to Node 2
	deleteNodeNextTo(node2);
	traverseLinkedList(head);

    return 0;
}
