// Features : Create Binary Tree, Add Nodes, Search Values

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <cmath>
#include <ios>
#include <iomanip>
#include <limits>
using namespace std;

class BSTNode {
public:
	int data;
	BSTNode* leftnode;
	BSTNode* rightnode;
};

BSTNode* createNode(int data) {
	BSTNode* tempNode = new BSTNode();
	tempNode->data = data;
	tempNode->leftnode = tempNode->rightnode = NULL;
	return tempNode;
}

BSTNode* insertNode(BSTNode* root, int val) {
	if (root == NULL) {
		root = createNode(val);
		cout << val << " added at location " << root << endl;
	}
	else {
		if (val < root->data) {
			root->leftnode = insertNode(root->leftnode, val);
		}
		else {
			root->rightnode = insertNode(root->rightnode, val);
		}
	}
	return root;
}

BSTNode* searchTree(BSTNode* root, int val) {
	if (root != NULL) {
		if (val == root->data)
			return root;
		else if (val < root->data) {
			return searchTree(root->leftnode, val);
		}
		else {
			return searchTree(root->rightnode, val);
		}
	}
	else {
		return NULL;
	}
}

void searchBinaryTreeInterface(BSTNode* root, int valToSearch) {
	BSTNode* searchQ = searchTree(root, valToSearch);
	if (searchQ == NULL)
		cout << valToSearch << " was not found :(" << endl;
	else
		cout << valToSearch << " was found on location " << searchQ << endl;
}

int findMin(BSTNode* root) {
	BSTNode* temp = root;
	while (temp->leftnode != NULL) {
		temp = temp->leftnode;
	}
	return temp->data;
}

int findMaxRec(BSTNode* root) {
	if (root->rightnode != NULL) {
		return findMaxRec(root->rightnode);
	}
	else {
		return root->data;
	}
}

int main() {
	
	BSTNode* root = NULL;
	root = insertNode(root ,10);
	root = insertNode(root, 15);
	root = insertNode(root, 8);

	searchBinaryTreeInterface(root, 8);
	searchBinaryTreeInterface(root, 10);
	
	cout << "min is " << findMin(root) << endl;
	cout << "max using recursion is " << findMaxRec(root) << endl;
	
	return 0;
}
