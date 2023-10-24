//Write a program that asks the user to enter integers as inputs to be stored in the variables 'a' and 'b' respectively. 
// There are also two integer pointers named ptrA and ptrB. Assign the values of 'a' and 'b' to ptrA and ptrB respectively, and display them.
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;

bool binarySearchByRef(int(&a)[16], int needle) {
	int low = 0;

	int high = (sizeof(a) / sizeof(a[0]));
	cout << high << endl;
	do {
		int mid_point = floor(low + (high - low) / 2);
		int value = a[mid_point];

		if (value == needle) {
			cout << "We found it at : " << mid_point << endl;
			return true;
		}
		else if (value > needle) {
			high = mid_point;
		}
		else {
			low = mid_point + 1;
		}
	} while (low < high);
	cout << "Not found it" << endl;

	return false;
}

bool binarySearchByPointers(int (*a)[16], int needle) {
	int low = 0;

	int high = (sizeof(*a) / sizeof((*a)[0]));
	cout << high << endl;
	do {
		int mid_point = floor(low + (high - low) / 2);
		int value = (*a)[mid_point];

		if (value == needle) {
			cout << "We found it at : " << mid_point << endl;
			return true;
		}
		else if (value > needle) {
			high = mid_point;
		}
		else {
			low = mid_point + 1;
		}
	} while (low < high);
	cout << "Not found it" << endl;

	return false;
}

int main()
{
	int b[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 32 };
	binarySearchByRef(b, 8);
	binarySearchByRef(b, 32);
	binarySearchByRef(b, 22);
	
	int c[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 32 };
	binarySearchByPointers(&c, 8);
}	
