#include<stdio.h>
void exchangesort(int n, int S[])
{
	int i, j, temp;
	for (i = 0; i < n; i++)
		for (j = i + 1; j<n; j++)
			if (S[j] < S[i])
			{
				temp = S[j];
				S[j] = S[i];
				S[i] = temp;
			}
}
int main() {
	int S[9] = { 3,6,1,2,8,5,9,7,4 };
	exchangesort(9, S);
	for (int i = 0; i<9; i++)
		printf("%d ", S[i]);
	printf("\n");
}