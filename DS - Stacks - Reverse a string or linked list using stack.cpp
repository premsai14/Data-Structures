//============================================================================
// Name        : DS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stack> // stack from Standard Template Library(STL)
using namespace std;

// =================================String Reversal=========================================== //
void Reverse(char *c, int n) { // reverse Array of string

	stack<char> S; //create stack S of type char
	// loop for push
	for (int i = 0; i < n; i++) {
		S.push(c[i]);
	}

	//loop for pop
	for (int i = 0; i < n; i++) {
		c[i] = S.top(); // overwrite the character at index i
		S.pop(); // perform pop.
	}
}

// =================================String Reversal=========================================== //

// =================================LinedList Reversal=========================================== //
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

void ReverseLL(){ // reverse LinkedList

	if(head == NULL) return;

	//step 1
	stack<Node*> S;
	Node* temp = head;
	while( temp != NULL){
		S.push(temp);
		temp = temp->next;
	}

	//step 2
	head = S.top();
	temp = head;
	S.pop();
	while( !S.empty()){
		temp->next = S.top();
		S.pop();
		temp = temp->next;

	}
	temp->next = NULL;


}
// =================================LinedList Reversal=========================================== //

int main() {

// =================================String Reversal=========================================== //
	char C[51];
	printf("Enter a string: ");
	cin >> C;
	Reverse(C, strlen(C));
	printf("Output: %s", C);
	cout << endl;
// =================================String Reversal=========================================== //

// =================================LinedList Reversal=========================================== //

	head = NULL;

	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	Insert(7);

	Print();
	cout << endl;

	ReverseLL();
	Print();


// =================================LinedList Reversal=========================================== //

	return 0;
}
