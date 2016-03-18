/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdlib.h>

int is_greater(char *, char *);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL){
		return NULL;
	}
	int mlen, i, j, k = 0, value;
	mlen = ALen + BLen;
	struct transaction *Arr;
	Arr = (struct transaction*)malloc(mlen*sizeof(struct transaction));
	for (i = 0, j = 0; i < ALen && j < BLen; ){
		value = is_greater(A[i].date, B[j].date);
		if (value == 2){
			Arr[k] = B[j];
			k++;
			j++;
		}
		else if (value == 1){
			Arr[k] = A[i];
			k++;
			i++;
		}
		else if (value == 0){
			Arr[k] = A[i];
			k++;
			i++;
			Arr[k] = B[j];
			j++;
			k++;
		}
	}
	if (i == ALen && j < BLen){
		for (int m = j; m < BLen; m++){
			Arr[k] = B[m];
			k++;
		}
	}
	else{
		for (int m = i; m < ALen; m++){
			Arr[k] = A[m];
			k++;
		}
	}
	return Arr;
}

int is_greater(char *date1, char *date2){
	int i, year1 = 0, year2 = 0, month1 = 0, month2 = 0, day1 = 0, day2 = 0;
	i = 6;
	while (i != 10){
		year1 = year1 * 10 + (date1[i] - '0');
		year2 = year2 * 10 + (date2[i] - '0');
		i++;
	}
	if (year1 > year2){
		return 2;
	}
	else if (year1 < year2){
		return 1;
	}
	else{
		i = 3;
		while (i != 5){
			month1 = month1 * 10 + (date1[i] - '0');
			month2 = month2 * 10 + (date2[i] - '0');
			i++;
		}
		if (month1 > month2){
			return 2;
		}
		else if (month1 < month2){
			return 1;
		}
		else{
			i = 0;
			while (i != 2){
				day1 = day1 * 10 + (date1[i] - '0');
				day2 = day2 * 10 + (date2[i] - '0');
				i++;
			}
			if (day1 > day2){
				return 2;
			}
			else if (day1 < day2){
				return 1;
			}
			else
				return 0;
		}
	}
}