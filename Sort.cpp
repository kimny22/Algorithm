#include <stdio.h>

void selectionSort(int A[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			if (A[j] > A[i]) {
				int temp = A[j];
				A[j] = A[i];
				A[i] = temp;
			}
		}
	}
}
void bubbleSort(int A[], int n) {
	bool sorted;
	for (int j = 0; j < n; j++) {
		sorted = true;
		for (int i = 0; i < n - 1; i++) {
			if (A[i] > A[i + 1]) {
				int temp = A[i + 1];
				A[i + 1] = A[i];
				A[i] = temp;
				sorted = false;
			}
		}
		if (sorted) return;
	}

}
void insertionSort(int A[], int n) {
	for (int i = 1; i < n; i++) {
		int loc = i - 1;
		int newitem = A[i];
		while (loc >= 0 && newitem < A[loc]) {
			A[loc + 1] = A[loc];
			loc--;
		}
		A[loc + 1] = newitem;
	}
}
int main() {
	//selectionSort
	int A[10] = { 7,1,6,4,5,2,8,9,10,3 };
	selectionSort(A, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	//bubbleSort
	int B[10] = { 7,1,6,4,5,2,8,9,10,3 };
	bubbleSort(B, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");

	//insertionSort
	int C[10] = { 7,1,6,4,5,2,8,9,10,3 };
	insertionSort(C, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", C[i]);
	}
}