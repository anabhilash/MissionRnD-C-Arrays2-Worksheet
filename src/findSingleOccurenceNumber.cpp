/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include <stdio.h>
void qsort(int *A, int low, int high);
void swap(int *A, int x, int y);

int findSingleOccurenceNumber(int *A, int len) 
{
	if (A == NULL || len < 0)
		return -1;
	int i, temp;
	int gap, swapped;
	gap = len / 2;
	do
	{
		do
		{
			swapped = 0;
			for (i = 0; i < len - gap; i++)
			{
				if (A[i]>A[i + gap])
				{
					temp = A[i];
					A[i] = A[i + gap];
					A[i + gap] = temp;
					swapped = 1;
				}
			}
		} while (swapped == 1);
	} while ((gap = gap / 2) >= 1);
	for (i = 0; i < len; i=i + 3)
	{
		if (i == len - 1)
		{
			if (A[i] != A[i - 1])
				return A[i];
		}
		if (A[i] != A[i + 1])
			return A[i];
		
	}

}
