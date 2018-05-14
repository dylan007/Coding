#include <stdio.h>
#include <stdbool.h>

#define UNASSIGNED 0

bool aux_SolveSudoku(int n, int array[][n]);
bool SolveSudoku(int n, int array[][n], int row, int col);
bool check(int n, int array[][n], int row, int col, int number);
bool CheckRow(int n, int array[][n], int row, int number);
bool CheckCol(int n, int array[][n], int col, int number);
bool CheckIfFull(int n, int array[][n]);
void printArray(int n, int array[][n]);

int main(void)
{
	int n;
	scanf(" %d", &n);
	int array[n][n];
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf(" %d", &array[i][j]);
	}

	if (aux_SolveSudoku(n, array) == true)
		printArray(n, array);
	else
		printf("-1\n");

	return 0;
}

bool aux_SolveSudoku(int n, int array[][n])
{
	int row,col;
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			if (SolveSudoku(n, array, row, col) && CheckIfFull(n, array))
				return true;
		}
	}
	return false;
}

bool SolveSudoku(int n, int array[][n], int row, int col)
{
	if (array[row][col] != UNASSIGNED)
		return true;
	static int level = 0;

	level++;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (check(n, array, row, col, i))
		{
			array[row][col] = i;

			if (SolveSudoku(n, array, row, col))
			{
				level--;
				return true;
			}

			array[row][col] = UNASSIGNED;
		}
	}
	level--;
	return false;
}

bool check(int n, int array[][n], int row, int col, int number)
{
	return(!CheckRow(n, array, row, number) && !CheckCol(n, array, col, number));
}

bool CheckRow(int n, int array[][n], int row, int number)
{
	int col;
	for (col = 0; col < n; col++)
	{
		if (array[row][col] == number)
		{
			return true;
		}
	}
	return false;
}

bool CheckCol(int n, int array[][n], int col, int number)
{
	int row;
	for (row = 0; row <  n; row++)
	{
		if (array[row][col] == number)
		{
			return true;
		}
	}
	return false;
}

bool CheckIfFull(int n, int array[][n])
{
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (array[i][j] == UNASSIGNED)
				return false;
		}
	}
	return true;
}

void printArray(int n, int array[][n])
{
	int row,col;
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			printf("%d ", array[row][col]);
		}
		printf("\n");
	}
}
