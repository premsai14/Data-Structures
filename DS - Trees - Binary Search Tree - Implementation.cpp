//============================================================================
// Name        : DS.cpp
// Author      : Prem Sai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct BstNode { // Binary Search Tree Node
	int data;
	BstNode* left;
	BstNode* right;
};

// creating a new node in memory heap
BstNode* GetNewNode(int data) {

	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;

}

// Inserting data in BST
BstNode* Insert(BstNode* root, int data) {

	if (root == NULL) { // empty node - simply point returned newNode in GetNewNode to root
		root = GetNewNode(data);

	} else if (data <= root->data) {
		root->left = Insert(root->left, data);

	} else {
		root->right = Insert(root->right, data);

	}
	return root; // this root in the function is locally created
				 // hence it will be cleared after function finishes
				 // need to return to modify the root in main()

}

// searches if the element is present in the tree
bool Search(BstNode* root, int data) {

	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return Search(root->left, data);
	else
		return Search(root->right, data);
}

//==============================================================================

//finding the min element of a BST
int FindMin(BstNode* root){ // this root is local for this function. hence it doesn't change the main() root.

	if( root == NULL){
		cout << "Error: Tree is empty !";
		return -1;
	}
	while( root->left != NULL){ // to find min we have to go as left as possible and as below as possible in a BST
		root = root->left;
	}
	return root->data;

}

//finding the min element of BST using recursion
int FindMin_Recur(BstNode* root){
	if (root == NULL){
		cout << "Error: Tree is empty !";
		return -1;
	}
	else if( root->left == NULL ){
		return root->data;
	}
	// go the the left subtree until the end
	return FindMin_Recur(root->left);
}


//finding the max element of a BST
int FindMax(BstNode* root){
	if(root == NULL){
		cout << "Error: Tree is empty !";
		return -1;
	}

	while(root->right != NULL){
		root = root->right;
	}
	return root->data;
}


//finding the max element of BST using recursion
int FindMax_Recur(BstNode* root){
	if( root == NULL){
		cout << "Error: Tree is empty !";
		return -1;
	}
	else if ( root->right == NULL){
		return root->data;
	}

	return FindMax_Recur(root->right);
}


//==============================================================================

//Find the height of a binary tree
int FindHeight(BstNode* root){
	if (root == NULL){
		return -1;
	}
	return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

//==============================================================================

int main() {

	BstNode* root = NULL; // pointer to root node and making the tree as empty

	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	int num;
	cout << "Enter number to be searched: " ;
	cin >> num;
	if( Search(root, num) == true)

		cout << "Found";
	else
		cout << "NOT Found" << endl;

//=================================

	cout << "Min element in BST using iteration: " << FindMin(root) << endl;
	cout << "Min element in BST using recursion: " << FindMin_Recur(root) << endl;
	cout << "Max element in BST using iteration: " << FindMax(root) << endl;
	cout << "Max element in BST using recursion: " << FindMax_Recur(root) << endl;

//=================================

	cout << "Height of the BST: " << FindHeight(root) ;



	return 0;
}
