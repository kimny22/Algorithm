#include <iostream>
#include <string>
using namespace std;

/* Lab 1: HEAPS */
#define MAX_ELEMENT 200
#define HEAP_FULL(n) (n==MAX_ELEMENT-1)
#define HEAP_EMPTY(n) (!n)

struct element {
	int key;
};

element heap[MAX_ELEMENT];
int n = 0;

// Insertion for MAX HEAPs
void insert_max_heap(element item, int& n)
{
	int i;

	// cheak whether it is full 
	if (HEAP_FULL(n)) {
		cout << "Hepas is full\n";
		exit(1);
	}

	// increment n: number of elements
	i = ++n;

	// begin from the leaf to root parent position
	//      comparing key values...
	//    item's key > parent's key then swap 
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

// deletion for MAX HEAP
element delete_max_heap(int &n)
{
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(n)) {
		cout << " The heap is empty";
		exit(1);
	}
	item = heap[1];
	temp = heap[n]; n--;

	parent = 1, child = 2;
	while (child <= n) {
		// ���� ������ �߿��� ū�� ã��
		if ((child < n) && (heap[child].key <heap[child + 1].key))
			child++;

		// temp �� child ���� ũ�� ã�Ҵ�!!!!
		if (temp.key >= heap[child].key) break;

		// child �� �ø���, child ��ġ�� ���� �ٽ� ã�� ����
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

void insert_min_heap(element item, int& n)
{
	int i;

	if (HEAP_FULL(n)) {
		cout << "Hepas is full\n";
		exit(1);
	}

	i = ++n;

	while ((i != 1) && (item.key < heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;

}

element delete_min_heap(int &n)
{
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(n)) {
		cout << " The heap is empty";
		exit(1);
	}
	item = heap[1];
	temp = heap[n]; n--;

	parent = 1, child = 2;
	while (child <= n) {
		if ((child < n) && (heap[child].key >heap[child + 1].key))
			child++;

		if (temp.key <= heap[child].key) break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

void main()
{
	// Ű �� 7, 16, 49, 82, 5, 31, 6, 2, 44 �� �ִٰ� ����

	int data[] = {7, 16, 49, 82, 5, 31, 6, 2, 44 };

	// �� ���� heap �� ���Ե� ���� �ִ� heap �� ������

	int count = 0, i, j;
	element a;
	for (i = 0; i < 9; i++) {
		a.key = data[i];
		insert_max_heap(a, count);
	}

	for (i = 0; i < 9; i++) {
		cout<<delete_max_heap(count).key<<" ";
	}

	// �� ���� heap �� ���Ե� ���� �ּ� heap �� ������

	count = 0;
	for (i = 0; i < 9; i++) {
		a.key = data[i];
		insert_min_heap(a, count);
		for (j = 1; j < i + 2; ++j) {
			cout << heap[j].key << " ";
		}
		cout << endl;
	}

	for (i = 0; i < 9; i++) {
		delete_min_heap(count);
	}

	system("pause");
}