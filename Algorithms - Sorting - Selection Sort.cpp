//============================================================================
// Name        : Algorithms.cpp
// Author      : Prem Sai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void SelectionSort(int A[], int n) {

	for (int i = 0; i < n - 1; i++) { // need to do n-2 passes
		int i_min = i; // i'th position: elements from i till n-1 are candidates

		for (int j = i + 1; j <= n - 1; j++) {
			if (A[j] < A[i_min])
				i_min = j; // update the index of minimun element
		}
		int temp = A[i];
		A[i] = A[i_min];
		A[i_min] = temp;

	}
}

int main() {

	int A[] = { 2, 7, 4, 1, 5, 3 };

	for (int i = 0; i < 6; i++) {
		cout << A[i] << " ";
	}

	SelectionSort(A, 6);
	cout << endl;

	for (int i = 0; i < 6; i++) {
		cout << A[i] << " ";
	}

	return 0;
}

