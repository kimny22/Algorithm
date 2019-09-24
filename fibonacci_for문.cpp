#include <stdio.h>

int fib(int n) {
	if (n == 0) return 0;
	if (n > 0) {
		int val1 = 0, val2 = 1;
		for (int i = 1; i <= n; i++) {
			int temp = val2;
			val2 = val1 + val2;
			val1 = temp;
		}
		return val1;
	}
}
int main() {
	int n;
	scanf_s("%d", &n);
	printf("%d", fib(n));
}