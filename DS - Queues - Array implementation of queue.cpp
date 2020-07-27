//============================================================================
// Name        : DS.cpp
// Author      : Prem Sai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

	// declare front element and rear element
	// and is global to access it everywhere
	int A[10];
	int front = -1; // set to -1 so it represents empty array - empty queue
	int rear = -1;
	int N = sizeof(A)/sizeof(*A);

bool IsEmpty(){ // checks whether the queue is empty

	if( front == -1 && rear == -1){
		return true;
	}else
		return false;

}

void Enqueue(int x){ // push element at the end/tail/rear
	if ( (rear + 1) % N == front){ // checks whether the queue is full
			return;
	}
	else if( IsEmpty()){
		front = rear = 0;
		// line 1
	}
	else{
		rear = (rear + 1 ) % N; // go to next element
		// line 2
	}
	A[rear] = x; // in line 1, line 2 this A[rear] = x appears, so I put it as a common at the end


}

void Dequeue(){
	if( IsEmpty()){
		return;
	}
	else if( front == rear ){
		front = rear = -1; // if only one element empty the queue by setting -1
	}
	else{
		front = ( front + 1 ) % N; // go to the next index. no need to delete the element as i may be replaced in the next cycle anyway
	}

}

void FrontOfQueue(){
	cout << "Front element is: " << A[front] << endl;
}


int main() {

	// we use circular array concept, to reduced the ineffectiveness of
	// unused spaces in the beginning of the array after performing Dequeue operation

	Enqueue(2);
	Enqueue(3);
	Enqueue(5);FrontOfQueue();
	Dequeue();FrontOfQueue();
	Enqueue(9);FrontOfQueue();
	Enqueue(11);FrontOfQueue();
	Dequeue();FrontOfQueue();
	Dequeue();FrontOfQueue();
	Dequeue();FrontOfQueue();







	return 0;
}
