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

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int b_search(struct transaction *, int, int, char *, int);
int isgreater(char *, char *);

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (len <= 0)
		return -1;
	int res;
	res = b_search(Arr, 0, len - 1, date, len);
	return res;

}

int b_search(struct transaction *Arr, int first, int last, char *date, int len){
	int low, high, mid, value, temp, value1;
	low = first;
	high = last;
	while (low <= high){
		mid = (low + high) / 2;
		value = isgreater(Arr[mid].date, date);
		if (value == 0){
			temp = mid;
			value1 = isgreater(Arr[temp].date, date);
			while (value1 == 0){
				temp = temp + 1;
				value1 = isgreater(Arr[temp].date, date);
			}
			
			return len - (temp);
		}
		else if (value == 2){
			low = first;
			high = mid - 1;
		}
		else if (value == 1){
			low = mid + 1;
			high = last;
		}
	}
	if (low == len){
		return 0;
	}
	value = isgreater(Arr[low].date, date);
	if (value == 1){
		return (len - low);
	}
	return len - low - 1;

}

int isgreater(char *date1, char *date2){
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
