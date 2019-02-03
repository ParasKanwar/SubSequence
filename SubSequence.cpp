#include"pch.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<string.h>

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
};

void main()
{
	
	char x[] = "strong";
	char y[] = "sequence";
	int m = strlen(x);
	int n = strlen(y);
	int l[7][9];
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				l[i][j] = 0;

			else if (x[i - 1] == y[j - 1])
				l[i][j] = l[i - 1][j - 1] + 1;

			else
				l[i][j] = max(l[i - 1][j], l[i][j - 1]);
		}
	}

	for (int k = 0; k <= m; k++)
	{
		for (int b = 0; b <= n; b++)
		{
			printf("%d ", l[k][b]);
		}
		printf("\n");
	}

	int i1 = m;
	int j1 = n;
	int iterator = 0;
	const int last = l[m][n];
	int answer[100];
	while (i1 >= 0) 
	{
		while (j1 >= 0) 
		{
			if (l[i1][j1 - 1] == l[i1][j1])
				j1 = j1 - 1;
			else if (l[i1 - 1][j1] == l[i1][j1])
				i1 = i1 - 1;
			else 
			{
				answer[iterator] = i1;
				iterator++;
				i1--;
				j1--;
			}
		
		}
	}
	for (int i = l[m][n]-1; i >=0; i--)
	{
		std::cout << x[answer[i]-1];
	}
	
}