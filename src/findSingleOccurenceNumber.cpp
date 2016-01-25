/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>

void sortArray(int *, int);

int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	sortArray(A, len);
	for (int index = 0; index < len; index += 3)
		if (index == len - 1 || A[index] != A[index + 1])
			return A[index];
	return -1;
}

void sortArray(int * given_array, int no_of_elements){
	int temp;
	for (int index = 0; index < no_of_elements - 1; index++){
		for (int idx = 0; idx < no_of_elements - 1 - index; idx++){
			if (given_array[idx] > given_array[idx + 1]){
				temp = given_array[idx];
				given_array[idx] = given_array[idx + 1];
				given_array[idx + 1] = temp;
			}
		}
	}
	return;
}
