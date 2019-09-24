#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int bin(int n, int k) {
	if (k == 0 || n == k)
		return 1;
	else
		return (bin(n - 1, k - 1) + bin(n - 1, k));
}

int bin2(int n, int k) {
	int** b = new int*[n+1];
	for (int i = 0; i <= n; i++) {
		b[i] = new int[k+1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= MIN(i,k); j++) {
			if (j == 0 || j == i) b[i][j] = 1;
			else b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
		}
	}
	return b[n][k];
}

int bin3(int n, int k) {
	int *c = new int[k + 1];
	for (int i = 0; i <= k; i++) {
		c[i] = 0;
	}
	c[0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = MIN(i, k); j > 0; j--)
			c[j] += c[j - 1];
	}
	return c[k];
}

int main() {
	int n, k;
	scanf_s("%d %d", &n, &k);
	printf("binomial coefficient = %d\n", bin(n, k));
	printf("binomial coefficient2 = %d\n", bin2(n, k));
	printf("binomial coefficient3 = %d\n", bin3(n, k));
}