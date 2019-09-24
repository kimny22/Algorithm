#include <stdio.h>
#define MIN(x,y) ((x<y) ? x : y)

int W[5][5] = { 0, 1, 1000, 1, 5,
				9, 0, 3, 2, 1000,
				1000, 1000, 0, 4, 1000,
				1000, 1000, 2, 0, 3,
				3, 1000, 1000, 1000, 0 };
int D[5][5] = { 0, };
int P[5][5] = { 0, };

void floyd(int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			D[i][j] = W[i][j];

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				D[i][j] = MIN(D[i][j], D[i][k] + D[k][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
}

void floyd2(int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			P[i][j] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			D[i][j] = W[i][j];

	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if ((D[i][k] + D[k][j]) < D[i][j]) {
					P[i][j] = k+1;
					D[i][j] = D[i][k] + D[k][j];
				}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}
}

void path(int q, int r)
{
	if (P[q-1][r-1] != 0) {

		path(q, P[q-1][r-1]);

		printf("v%d", P[q-1][r-1]);

		path(P[q-1][r-1], r);

	}
}

int minmult(int n) {
	int M[6][6];
	int d[7] = { 5,2,3,4,6,7,8 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			M[i][j] = 0;
	for(int diagonal = 0; diagonal <n-1; diagonal++)
		for (int i = 0; i < n - diagonal; i++) {
			int j = i + diagonal;
			for (int k = i; k < j - 1; k++) {
				M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
			}
		}
	return 0;
}

int main() {
	floyd(5);
	printf("\n");
	floyd2(5);
	path(5, 3);
}