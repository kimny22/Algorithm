#include <stdio.h>
int fib(int x) {
	if (x <= 1)
		return x;
	else return (fib(x - 1) + fib(x - 2));
}
int fib2(int x) {
	int i;
	int* f = new int[x];
	f[0] = 0;
	if (x > 1) {
		f[1] = 1;
		for (i = 2; i <= x; i++)
			f[i] = f[i - 1] + f[i - 2];
	}
	return f[x];
}
int main() {
	int n;
	scanf_s("%d", &n);
	printf("%d\n", fib(n));
	printf("%d\n", fib2(n));
	return 0;
}



