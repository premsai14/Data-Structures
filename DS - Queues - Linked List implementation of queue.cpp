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

Node* front;
Node* rear;

void Enqueue(int data) {
	Node* temp = new Node();

	temp->data = data;
	temp->next = NULL;

	if (front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}

	rear->next = temp;
	rear = temp;

}

void Dequeue() {
	Node* temp = front;
	if (front == NULL) {
		return;
	}
	if (front == rear) {
		front = rear = NULL;
	} else {
		front = front->next;
	}
	free(temp);

}

void Print() {
	Node* temp = front;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;

}

int main() {

	front = rear = NULL;

	Enqueue(2);
	Enqueue(3);
	Enqueue(5);Print();
	Dequeue();Print();
	Enqueue(9);Print();
	Enqueue(11);Print();
	Dequeue();Print();
	Dequeue();Print();
	Dequeue();Print();

	return 0;
}
