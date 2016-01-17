/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int* dateconverter(char *);

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i = 0;
	int j = 0;
	int K = ALen;
	if (ALen > BLen){
		K = BLen;
	}
	struct transaction *result = (struct transaction*)malloc(sizeof(struct transaction) * K);
	int index = 0;
	while (i < ALen && j < BLen){
		int *ADate = dateconverter(A[i].date);
		int *BDate = dateconverter(B[j].date);
		if (ADate[2] < BDate[2]){
			i++;
		}
		else if (ADate[2] > BDate[2]){
			j++;
		}
		else{
			if (ADate[1] < BDate[1]){
				i++;
			}
			else if (ADate[1] > BDate[1]){
				j++;
			}
			else{
				if (ADate[0] < BDate[0]){
					i++;
				}
				else if (ADate[0] > BDate[0]){
					j++;
				}
				else{
					result[index] = A[i];
					i++;
					index++;
				}
			}
		}
	}
	if (index){
		return result;
	}
	return NULL;
}

int* dateconverter(char *date){
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