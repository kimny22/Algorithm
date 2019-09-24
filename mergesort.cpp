#include <stdio.h>
void merge(int A[], int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 0;
	int tmp[10];
	while (i <= q && j <= r) {
		if (A[i] <= A[j]) tmp[t++] = A[i++];
		else tmp[t++] = A[j++];
	}
	while (i <= q) tmp[t++] = A[i++];
	while (j <= r) tmp[t++] = A[j++];
	i = p;
	t = 0;
	while (i <= r) A[i++] = tmp[t++];
}
void mergeSort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	int A[10] = { 64,32,1,8,62,78,33,21,87,34 };
	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
	mergeSort(A, 0, 9);
	printf("\nsorted\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
}