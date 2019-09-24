#include <stdio.h>

void normal_product(int n, int A[2][2], int B[2][2], int C[2][2])
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < n; k++)
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
		}
	}
}
void strassen(int A[2][2], int B[2][2], int C[2][2]) {
		int M1 = (A[0][0] + A[1][1])*(B[0][0] + B[1][1]);
		int M2 = (A[1][0] + A[1][1])*B[0][0];
		int M3 = A[0][0] * (B[0][1] - B[1][1]);
		int M4 = A[1][1] * (B[1][0] - B[0][0]);
		int M5 = (A[0][0] + A[0][1])*B[1][1];
		int M6 = (A[1][0] - A[0][0])*(B[0][0] + B[0][1]);
		int M7 = (A[0][1] - A[1][1])*(B[1][0] + B[1][1]);
		C[0][0] = M1 + M4 - M5 + M7;
		C[0][1] = M3 + M5;
		C[1][0] = M2 + M4;
		C[1][1] = M1 + M3 - M2 + M6;
	
}
int main() {
	int A[2][2];
	int B[2][2];
	int C[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			A[i][j] = (i+1)*(j+2);
			B[i][j] = i*j+2;
			C[i][j] = 0;
		}
	}
	printf("matA : \n");
	for (int i = 0; i < 2; i++)
	{

		for (int j = 0; j < 2; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("matB : \n");
	for (int i = 0; i < 2; i++)
	{

		for (int j = 0; j < 2; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	strassen(A, B, C);
	printf("matC : \n");
	for (int i = 0; i < 2; i++)
	{

		for (int j = 0; j < 2; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	normal_product(2, A, B, C);
	printf("matC : \n");
	for (int i = 0; i < 2; i++)
	{

		for (int j = 0; j < 2; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}