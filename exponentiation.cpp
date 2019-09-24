#include <stdio.h>

int power(int base, int exp) {
	if (exp == 0) return 1;
	if (exp % 2 == 0)
		return power(base, exp / 2)*power(base, exp / 2);
	else if (exp % 2 == 1)
		return power(base, exp / 2)*power(base, exp / 2)*base;
}
int main() {
	int base, exp, result;
	scanf_s("%d", &base);
	scanf_s("%d", &exp);
	printf("power = %d",power(base, exp));
}