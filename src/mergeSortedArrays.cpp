/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int* DateConverter(char *);

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i = 0;
	int j = 0;
	int k = 0;
	struct transaction *result = (struct transaction*)malloc(sizeof(struct transaction) * (ALen+BLen));
	while (i < ALen && j < BLen){
		int *ADate = DateConverter(A[i].date);
		int *BDate = DateConverter(B[j].date);
		if (ADate[2] < BDate[2]){
			result[k] = A[i];
			i++;
			k++;
		}
		else if (ADate[2] > BDate[2]){
			result[k] = B[j];
			k++;
			j++;
		}
		else{
			if (ADate[1] < BDate[1]){
				result[k] = A[i];
				i++;
				k++;
			}
			else if (ADate[1] > BDate[1]){
				result[k] = B[j];
				k++;
				j++;
			}
			else{
				if (ADate[0] < BDate[0]){
					result[k] = A[i];
					i++;
					k++;
				}
				else if (ADate[0] > BDate[0]){
					result[k] = B[j];
					k++;
					j++;
				}
				else{
					result[k] = A[i];
					i++;
					k++;
				}
			}
		}
	}
	if (i < ALen) {
		for (int index = i; index < ALen; index++) {
			result[k] = A[index];
			k++;
		}
	}
	else {
		for (int index = j; index < BLen; index++) {
			result[k] = B[index];
			k++;
		}
	}
	return result;
}

int* DateConverter(char *date){
	int j = 0;
	int num = 0;
	int * x = (int *)malloc(sizeof(int) * 3);
	for (int i = 0; date[i] != '\0'; i++){
		if (date[i] == '-'){
			x[j] = num / 10;
			j += 1;
			num = 0;
		}
		else
			num = (num + (date[i] - '0')) * 10;
	}
	x[j] = num / 10;
	return x;
}