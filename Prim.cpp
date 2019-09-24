#include <stdio.h>
struct edge {
	int v1;
	int v2;
	int weight;
};
void prim(int n, const int W[][5]) {
	int i, vnear, min;
	edge e[4];
	int nearest[4];
	int distance[4];
	for (i = 0; i < n-1; i++) {
		nearest[i] = 0;
		distance[i] = W[0][i+1];
	}
	for (int k = 0; k < n-1; k++) {
		min = 1000;
		for (i = 0; i < n-1; i++) {
			if (distance[i] > 0 && distance[i] < min) {
				min = distance[i];
				vnear = i+1;
			}
		}
		e[k].v2 = vnear;
		e[k].v1 = nearest[vnear - 1];
		e[k].weight = W[vnear][nearest[vnear - 1]];
		distance[vnear-1] = -1;
		for (i = 0; i < n-1; i++) {
			if (W[i+1][vnear] < distance[i]) {
				distance[i] = W[i+1][vnear];
				nearest[i] = vnear;
			}
		}
		printf("Vertex(%d, %d) : %d\n", e[k].v1, e[k].v2, e[k].weight);
	}
}
int main() {
	int W[5][5] = { 0,1,3,1000,1000,
				    1,0,3,6,1000,
				    3,3,0,4,2,
					1000,6,4,0,5,
					1000,1000,2,5,0	};
	prim(5, W);
}