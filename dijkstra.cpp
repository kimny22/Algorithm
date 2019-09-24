#include <stdio.h>
struct edge {
	int v1;
	int v2;
	int weight;
};
int W[5][5] = { 0,7,4,6,1,
				1000,0,1000,1000,1000,
				1000,2,0,5,1000,
				1000,3,1000,0,1000,
				1000,1000,1000,1,0 };
void dijkstra(int n) {
	int vnear = 0;
	int min = 1000;
	int* touch = new int[n-1];
	int* length = new int[n-1];
	for (int i = 0; i < n-1; i++) {
		touch[i] = 0;
		length[i] = W[0][i+1];
	}
	for (int count = 0; count < n - 1; count++) {
		for (int i = 0; i < n-1; i++) {
			if (length[i] >= 0 && length[i] < min) {
				min = length[i];
				vnear = i+1;
			}
		}
		for (int i = 0; i < n-1; i++) {
			if (length[vnear-1] + W[vnear][i+1] < length[i]) {
				length[i] = length[vnear-1] + W[vnear][i+1];
				touch[i] = vnear;
			}
		}
	}
	int startNode = 0;
	for (int i = 1; i < n; i++) {
			printf("\nDistance of %d = %d\n", i+1, length[i-1]);
			printf("Path = %d", i+1);
			int j = i;
			do {
				j = touch[j-1];
				printf("<- %d", j+1);
			} while (j != startNode);
	}
}
int main() {
	dijkstra(5);
}