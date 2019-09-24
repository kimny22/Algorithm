#include <stdio.h>
void matrixmult(int n, const int A[][3], const int B[][3], int C[3][3])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < n; k++)
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
		}
}
int main() {
	int n = 3;
	int a[3][3];
	int b[3][3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = i + j + 1;
			b[i][j] = (i + 1) * (j + 1);
		}
	}
	int c[3][3];
	matrixmult(n, a, b, c); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}