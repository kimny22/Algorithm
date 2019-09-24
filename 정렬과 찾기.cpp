#include <iostream>
using namespace std;

#define COMPARE(x,y) (((x)<(y))? -1:((x)==(y))? 0:1)
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void sort(int[], int);
int binsearch(int list[], int key, int first, int last);

int main()
{
	int list[] = { 35, 2, 4, 7, 14, 30, 70, 8, 12, 69 };
	int key, i;
	sort(list, 10);
	cout << "찾는 값은?" << endl;
	cin >> key;
	i = binsearch(list, key, 0, 9);

	if (i>0)
		cout << "찾는 값인" << key << "는 " << i << "번째에 있음\n";

	else
		cout << "찾는 값이 존재하지 않음";
}

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i<n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}

int binsearch(int list[], int key, int first, int last)
{
	int mid;
	if (first <= last) {
		mid = (first + last) / 2;
		switch (COMPARE(key, list[mid])) {
		case -1: return binsearch(list, key, first, mid - 1);
		case 0: return mid;
		case 1: return binsearch(list, key, mid + 1, last);
		}
	}
	return -1;
}