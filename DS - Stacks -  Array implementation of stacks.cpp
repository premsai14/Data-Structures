//============================================================================
// Name        : DS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x){

	if(top == MAX_SIZE - 1){
		cout << "Error: stack overflow!" << endl;
		return;
	}

	top++;
	A[top] = x;
	// the above 2 statements can be written as A[++top] = x;
	// ++top is increment top first
}

void Pop(){

	if( top == -1){
		cout << "Error: No element to pop" << endl;
		return;
	}
	top--;
}

void Top(){
	cout << A[top];
}

void Print(){
	cout << "Stack: " ;
	for( int i = 0; i <= top; i++){
		cout << A[i] << " " ;
	}
	cout << endl;

}
int main() {

	Push(2);Print();
	Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Push(15);Print();
	Push(28);Print();


	return 0;
}
