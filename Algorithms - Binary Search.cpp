//============================================================================
// Name        : Algorithms.cpp
// Author      : Prem Sai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int BinarySearch(int A[], int n, int x) {

	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2; // (low + high) may overflow

		if (x == A[mid])
			return mid;
		else if (x < A[mid])
			high = mid - 1;
		else
			low = mid + 1;

	}
	return -1;
}
int main() {

	int A[] = { 2, 4, 5, 7, 13, 14, 15, 23 };

	int x;
	cout << "Enter a number: ";
	cin >> x;

	int index = BinarySearch(A, 8, x);

	if (index != -1)
		cout << "Number " << x << " is at index " << index;
	else
		cout << "Couldn't find the number";

	return 0;
}
