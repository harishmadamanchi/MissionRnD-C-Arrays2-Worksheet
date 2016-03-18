/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
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

int is_Greater(char *, char *);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i, j, k = 0, flag = 0, value;
	struct transaction *Arr;
	Arr = (struct transaction*)malloc(sizeof(struct transaction));
	for (i = 0; i < ALen; i++){
		for (j = 0; j < BLen; j++){
			value = is_Greater(A[i].date, B[j].date);
			if (value == 0){
				flag = 1;
				break;
			}
		}
		if (flag == 1){
			Arr[k] = A[i];
			k++;
			flag = 0;
		}
	}
	if (k == 0){
		return NULL;
	}
	return Arr;
}


int is_Greater(char *date1, char *date2){
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