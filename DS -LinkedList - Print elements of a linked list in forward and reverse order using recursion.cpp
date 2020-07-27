//============================================================================
// Name        : DS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;

void Insert(int data) {
	Node* temp = new Node();

	temp->data = data;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		return;
	}

	Node* temp1 = head;

	while (temp1->next != NULL) {
		temp1 = temp1->next;
	}

	temp1->next = temp;

}

void Print1(Node* headNode); // Print using recursion
void Print1(Node* headNode){

	if(headNode == NULL) return; // Exit condition
	cout << headNode->data << " "; // First print the value in the node
	Print1(headNode->next); // Recursive call

}

void Print2(Node* headNode); // Print using recursion - Reverse order
void Print2(Node* headNode){

	if(headNode == NULL) return; // Exit condition
	Print2(headNode->next); // First Recursive call
	cout << headNode->data << " "; // then print the value in the node


}

int main() {

	head = NULL;

	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	Insert(7);
	Print1(head);
	cout << endl;
	Print2(head);



	return 0;
}
