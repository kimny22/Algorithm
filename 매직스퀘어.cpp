#include <iostream>

#define MAX 15

using namespace std;

void main(void)
{
	int square[MAX][MAX];
	int i, j, row, column;
	int count;
	int size;

	cout << " Enter the size of the square:\n";
	cin >> size;

	if (size < 1 || size > MAX + 1) {
		cout << "Error" << endl;
		exit(1);
	}
	if (!(size % 2)) {
		cout << "Error! Size is even" << endl;
		exit(1);
	}

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			square[i][j] = 0;

	square[0][(size - 1) / 2] = 1;
	i = 0; j = (size - 1) / 2;

	for (count = 2; count <= size*size; count++) {
		row = (i - 1 < 0) ? (size - 1) : (i - 1);
		column = (j - 1 < 0) ? (size - 1) : (j - 1);
		if (square[row][column])
			i = (++i) % size;
		else {
			i = row;
			j = (j - 1 < 0) ? (size - 1) : --j;
		}
		square[i][j] = count;
	}

	cout << " Magic square of: size " << size << endl;

	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++)
			cout << square[i][j] << "   ";
		cout << endl;
	}
	system("pause");
}