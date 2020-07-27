//============================================================================
// Name        : Ds.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

void Reverse(){
	 Node *prev,*current,*nextNode;

	 current = head;
	 prev = NULL;

	 while( current != NULL ){
		 nextNode = current->next;
		 current->next = prev;
		 prev = current;
		 current = nextNode;
	 }

	 head = prev;

}

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

int main() {
	head = NULL;

	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	Insert(7);
	Print();

	Reverse();
	Print();




	return 0;
}
