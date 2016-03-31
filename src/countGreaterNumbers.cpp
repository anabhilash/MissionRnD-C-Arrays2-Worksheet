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
#include <stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	if (Arr != NULL)
	{
		int count = 0;
		int i = 0, j, day, month, year, a[3];
		
		day = (date[0] - '0') * 10 + date[1] - '0';
		month = (date[3] - '0') * 10 + date[4] - '0';
		year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + date[9] - '0';
		
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (j <2 )
				{
					a[0] = a[0] * 10 + Arr[i].date[j] - '0';
					
				}
				else if (j > 2 && j < 5)
				{
					a[1] = a[1] * 10 + Arr[i].date[j] - '0';
				}
				else if (j > 5)
				{
					a[2] = a[2] * 10 + Arr[i].date[j] - '0';
					
				}
			}
			if (a[2]>year)
			{
				count += 1;
			}
			else if (a[2] == year &&a[1] > month)
			{
				count += 1;
			}
			else if (a[2] == year && a[1] == month && a[0] > day)
			{
				count += 1;
			}
			a[0] = 0;
			a[1] = 0;
			a[2] = 0;
		}
		return count;
	}
	
	else
		return NULL;
}
