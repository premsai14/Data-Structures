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

//=============================Breadth First: Level Order Traversal===============================//

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

//=============================Breadth First: Level Order Traversal===============================//

//=============================Depth First Traversal==============================================//

//PreOrder Traversal
//visiting <root> <left subtree> <right subtree>
void Preorder(BstNode* root){

	if( root == NULL){
		return;
	}
	cout << root->data << " "; // <root> print root element
	Preorder(root->left);	   // <left subtree> go to left subtree first
	Preorder(root->right);	   // <right subtree> go to right subtree second
}

//InOrder Traversal
//visiting  <left subtree> <root> <right subtree>
void Inorder(BstNode* root){

	if( root == NULL){
		return;
	}
	Inorder(root->left);	   // <left subtree> go to left subtree first
	cout << root->data << " "; // <root> print root element
	Inorder(root->right);	   // <right subtree> go to right subtree second
}

//PostOrder Traversal
//visiting  <left subtree> <right subtree> <root>
void Postorder(BstNode* root){

	if( root == NULL){
		return;
	}
	Postorder(root->left);	   // <left subtree> go to left subtree first
	Postorder(root->right);	   // <right subtree> go to right subtree second
	cout << root->data << " "; // <root> print root element
}

//=============================Depth First Traversal==============================================//

int main() {

	BstNode* root = NULL; // pointer to root node and making the tree as empty

	/*									F
	 * 								 /		\
	 * 								 D		 J
	 * 							   /   \	/  \
	 * 							  B     E  G    K
	 * 							 / \	    \
	 * 							A   C		 I
	 * 										/
	 * 									   H			This is actually a BST
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

	cout << endl << "Pre-order Traversal: " ;
	Preorder(root); // Output: F D B A C E J G I H K

	cout << endl << "In-order Traversal: " ;
	Inorder(root); // Output: A B C D E F G H I J K
	// In order traversal of a BST leaves us a sorted list!

	cout << endl << "Post-order Traversal: " ;
	Postorder(root); // Output: A C B E D H I G K J F

	return 0;
}
