/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int* dateConverter(char *);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (len <= 0 || Arr == NULL || date == NULL)
		return -1;
	int greaterNumber = 0;
	int *keyDate = dateConverter(date);
	int *intDate;
	for (int index = 0; index < len; index++){
		intDate = dateConverter(Arr[index].date);
		if (keyDate[2] < intDate[2]){
			greaterNumber++;
		}
		else if (keyDate[2] == intDate[2]){
			if (keyDate[1] < intDate[1]){
				greaterNumber++;
			}
			else if (keyDate[1] == intDate[1]){
				if (keyDate[0] < intDate[0]){
					greaterNumber++;
				}
			}
		}

	}
	return greaterNumber;
}

int* dateConverter(char *date){
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

