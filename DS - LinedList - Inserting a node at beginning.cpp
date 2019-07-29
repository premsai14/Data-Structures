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

Node* head; // global variable, can be accessed anywhere

void Insert(int x) {

	Node* temp = new Node();
	temp->data = x; // dereferencing temp which points to newly created dynamic mem and accesing data variable to set it to x
	temp->next = head;
	head = temp; // pointing head to temp so it is declared as the beginning.

}

void Print() {

	Node* temp1 = head;
	cout << "List is: ";
	while (temp1 != NULL) {

		cout << temp1->data << " ";
		temp1 = temp1->next;
	}
	cout << endl;

}

int main() {

	head = NULL; // empty list
	cout << "How many numbers? " << endl;

	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Enter the number " << endl;
		cin >> x;
		Insert(x);
		Print();
	}

	return 0;
}

