#include <stdio.h>
int partition(int A[], int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			int temp = A[++i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int t = A[i+1];
	A[i+1] = A[r];
	A[r] = t;
	return i + 1;
}
void quickSort(int A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int main() {
	int A[10] = { 64,32,1,8,62,78,33,21,87,34 };
	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
	quickSort(A, 0, 9);
	printf("\nsorted\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
}