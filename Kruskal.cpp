#include <stdio.h>
struct edge {
	int v1;
	int v2;
	int weight;
};
int parent[5];
int find(int n) {
	while (parent[n] != n)
		n = parent[n];
	return n;
}
void merge(int x, int y) {
	int i = find(x);
	int j = find(y);
	parent[i] = j;
}
void kruskal(int n, int m, const int E[][5], edge F[]) {
	int p, q;
	for (int i = 0; i < n; i++) parent[i] = i;
	edge e[7];
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (E[i][j] == 0 || E[i][j] == 1000)	;
			else {
				e[index].v1 = i;
				e[index].v2 = j;
				e[index].weight = E[i][j];
				index++;
			}
		}
	} //Edge설정
	for (int i = m - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			if (e[j].weight > e[i].weight) {
				edge temp = e[j];
				e[j] = e[i];
				e[i] = temp;
			}
		}
	} //Edge 정렬
	int count = 0;
	int k = 0;
	while (count < n-1) {
		edge X = e[k];
		int i = X.v1;
		int j = X.v2;
		p = find(i);
		q = find(j);
		if (p != q) {
			merge(p, q);
			F[count] = X;
			count++;
		}
		else k++;
	}
}

int main() {
	int E[5][5] = { 0,1,3,1000,1000,
					1,0,3,6,1000,
					3,3,0,4,2,
					1000,6,4,0,5,
					1000,1000,2,5,0 };
	edge F[4] = { 0, };
	kruskal(5,7,E,F);
	for (int k = 0; k < 4; k++) {
		printf("Vertex(%d, %d) : %d\n", F[k].v1+1, F[k].v2+1, F[k].weight);
	}
}