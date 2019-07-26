//============================================================================
// Name        : DS.cpp
// Author      : Prem Sai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* head;

// InsertAtHead(x)
// InsertAtTail(x)
// Print()
// ReversePrint() - This ensures the reverse linked are correctly applied

//This is to create a new dynamic memory and return the address
struct Node* GetNewNode(int x) {
	Node* newNode = new Node();

	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}
void InsertAtHead(int x) {

	Node* newNode = GetNewNode(x);

	if (head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;

}

void Print() {
	Node* temp = head;
	cout << "Forward: ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

void ReversePrint() {
	Node* temp = head;
	if (temp == NULL)
		return; // empty list, exit.

	// Going to last NOde
	while (temp->next != NULL) {
		temp = temp->next;
	}

	//Tracersing backwards using 'prev' pointer
	cout << "Reverse: ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->prev;
	}

	cout << endl;

}
int main() {
	head = NULL;

	InsertAtHead(2);
	Print();
	ReversePrint();
	InsertAtHead(4);
	Print();
	ReversePrint();
	InsertAtHead(5);
	Print();
	ReversePrint();
	InsertAtHead(6);
	Print();
	ReversePrint();

	return 0;
}

