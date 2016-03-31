/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if (A != NULL&&B != NULL)
	{
		int count = 0;
		int i = 0, j = 0, day = 0, month = 0, year = 0, a[3];
		struct transaction *result = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
		
		while (i < ALen&&j < BLen)
		{
			day = (A[i].date[0] - '0') * 10 + A[i].date[1] - '0';
			month = (A[i].date[3] - '0') * 10 + A[i].date[4] - '0';
			year = (A[i].date[6] - '0') * 1000 + (A[i].date[7] - '0') * 100 + (A[i].date[8] - '0') * 10 + A[i].date[9] - '0';
			a[0] = (B[j].date[0] - '0') * 10 + B[j].date[1] - '0';
			a[1] = (B[j].date[3] - '0') * 10 + B[j].date[4] - '0';
			a[2] = (B[j].date[6] - '0') * 1000 + (B[j].date[7] - '0') * 100 + (B[j].date[8] - '0') * 10 + B[j].date[9] - '0';

			if (a[2] < year)
			{
				result[count] = B[j];
				count++;
				j++;
			}
			else if (a[2] == year&&a[1] < month)
			{
				result[count] = B[j];
				count++;
				j++;
			}
			else  if (a[2] == year&&a[1] == month&&a[0] < day)
			{
				result[count] = B[j];
				count++;
				j++;
			}
			else
			{
				result[count] = A[i];
				i++;
				count++;
			}
			a[0] = 0;
			a[1] = 0;
			a[2] = 0;
		}
		while (j < BLen)
		{
			result[count] = B[j];
			j++;
			count++;
		}
		while (i < ALen)
		{
			result[count] = A[i];
			i++;
			count++;
		}
		return result;
	}
	else
		return NULL;

}