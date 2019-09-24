#include <stdio.h>

void heapify(int A[], int k, int n) {
	int left = 2 * k + 1;
	int right = 2 * k + 2;
	int smaller = 0;
	if (right <= n) {
		if (A[left] < A[right])	smaller = left;
		else smaller = right;
	}
	else if (left <= n) smaller = left;
	else return;
	if (A[smaller] < A[k]) {
		int t = A[k];
		A[k] = A[smaller];
		A[smaller] = t;
		heapify(A, smaller, n);
	}
}

void buildheap(int A[], int n) {
	for (int i = n / 2; i >= 0; i--) { heapify(A, i, n); }
}

void heapSort(int A[], int n) {
	buildheap(A, n);
	for (int i = n; i >= 0; i--) {
		int t = A[0];
		A[0] = A[i];
		A[i] = t;
		n--;
		heapify(A, 0, n);
	}
}

int main() {
	int A[10] = { 64,32,1,8,62,78,33,21,87,34 };
	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
	heapSort(A, 9);
	printf("\nsorted\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
}