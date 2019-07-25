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
};
Node* head; // global
void Insert(int data); // insert an integer at end of the list
void Print(); // print all elements in the list
void Delete(int); // delete node at position n

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

void Print() {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;

}

void Delete(int n) {

	Node* temp1 = head;

	if (n == 1) {
		head = temp1->next; // head now points to second node
		delete temp1;
		return;
	}

	for (int i = 0; i < n - 2; i++) {
		temp1 = temp1->next;
	} // temp1 points to (n-1)th node

	Node* temp2 = temp1->next; // nth node
	temp1->next = temp2->next; // (n+1)th node
	delete temp2; // deletes nth node

}

int main() {
	head = NULL; // empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5); // List: 2, 4, 6, 5
	Print();

	int n;
	cout << "Enter a position: " << endl;
	cin >> n;

	Delete(n);
	Print();

	return 0;
}

