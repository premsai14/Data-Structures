//============================================================================
// Name        : DS.cpp
// Author      : Prem Sai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<queue>
using namespace std;

//=============================Creating BST===============================//
struct BstNode { // Binary Search Tree Node
	char data;
	BstNode* left;
	BstNode* right;
};

// creating a new node in memory heap
BstNode* GetNewNode(char data) {

	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;

}

// Inserting data in BST
BstNode* Insert(BstNode* root, char data) {

	if (root == NULL) { // empty node - simply point returned newNode in GetNewNode to root
		root = GetNewNode(data);

	} else if (data <= root->data) {
		root->left = Insert(root->left, data);

	} else {
		root->right = Insert(root->right, data);

	}
	return root;

}

//=============================Creating BST===============================//

//=============================Level Order Traversal===============================//

void LevelOrder(BstNode* root) {
	if (root == NULL)
		return;

	queue<BstNode*> Q;
	Q.push(root);

	while (!Q.empty()) { //while there is at least one discovered node
		BstNode* current = Q.front();

		cout << current->data << " ";
		if (current->left != NULL)
			Q.push(current->left);
		if (current->right != NULL)
			Q.push(current->right);
		Q.pop(); // removing the element at front

	}
}

//=============================Level Order Traversal===============================//

int main() {

	BstNode* root = NULL; // pointer to root node and making the tree as empty

	/*					F
	 * 				 /		\
	 * 				 D		 J
	 * 		               /   \		/  \
	 * 			      B     E          G    K
	 * 		       	     / \	        \
	 * 		     	    A   C		 I
	 * 				  		/
	 * 					       H
	 */

	root = Insert(root, 'F'); // ROOT
	root = Insert(root, 'D'); // Left subtree
	root = Insert(root, 'B');
	root = Insert(root, 'E');
	root = Insert(root, 'A');
	root = Insert(root, 'C');

	root = Insert(root, 'J'); // Right subtree
	root = Insert(root, 'G');
	root = Insert(root, 'K');
	root = Insert(root, 'I');
	root = Insert(root, 'H');

	cout << "Level Order Traversal: " ;
	LevelOrder(root); // Output: F D J B E G K A C I H

	return 0;
}
