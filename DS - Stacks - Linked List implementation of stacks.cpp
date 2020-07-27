//============================================================================
// Name        : DS.cpp
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

Node* top = NULL;
void Push(int x){

	Node* temp = new Node();
	temp->data = x;
	temp->next = top;
	top = temp;
}

void Pop(){
	Node* temp = top;
	if ( top == NULL ) return;
	top = temp->next;
	delete temp;

}

void Print(){

	Node* temp = top;

	while( temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout<<endl;
}

int main() {

	Push(2);Print();
	Push(4);Print();
	Push(7);Print();
	Pop();Print();
	Push(48);Print();
	Push(123);Print();
	Pop();Print();
	Push(999);Print();




	return 0;
}
