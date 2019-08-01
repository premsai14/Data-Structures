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

void Print() {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;

}

void Reverse(Node* p); //Reverse the lined list using recursion
void Reverse(Node* p) { // p is a copied 'head'

	if (p->next == NULL) {
		head = p;
		return;
	}
	Reverse(p->next);

	Node* q = p->next; // q points to next address of p
	q->next = p;
	p->next = NULL;
}

int main() {
	head = NULL;

	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	Insert(7);

	Print();

	Reverse(head);
	Print();

	return 0;
}

