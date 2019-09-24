#include <stdio.h>

void mult(int x,int n) {
	if (n == 10) return;
	printf("%dX%d = %d\n",x, n, (x*n));
	mult(x, n + 1);
}

int main() {
	int x;
	scanf_s("%d", &x);
	mult(x, 1);
}