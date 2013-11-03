// AUTHOR: VIT
#include <iostream>
#include <time.h>
using namespace std;

void InsertionSort(int*, int, int);
void Print(int*, int);
int BinFind(int*, int, int, int);

int main() {
	srand(time(NULL));
	int n(rand() % 91 + 10);
	int *b = new int [n];
	for (int i(0); i < n; i++)
		b[i] = rand() % 100;
	InsertionSort(b, n, 2);
	for (int i(0); i < n; i++)
		cout << "b[" << i << "] = " << b[i] << endl;
	for (int i(0); i < n; i++) {
		int h = rand() % 100;
		cout << h << " -> " << BinFind(b, 0, n - 1, h) << endl;
	}
	system("pause");
	return 0;
}

void InsertionSort(int *a, int n, int k) { 
	int i(0), key(0);
	if (k <= n) {
		key = a[k-1];
		i = k - 2;
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
		InsertionSort(a, n, k + 1);
	}
	else
		return;
}

void Print(int *a, int n) {
	for (int i(0); i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int BinFind(int *mas, int f, int l, int v) {
	if (l - f + 1 > 2) {
		int i = f + (l - f + 1) / 2 + (l - f + 1) % 2;
		if (mas[i-1] <= v)
			BinFind(mas, i - 1, l, v);
		else
			BinFind(mas, f, i - 2, v);
	}
	else {
		if (mas[f] == v)
			return f;
		else
			if (mas[l] == v)
				return l;
			else
				return -1;
	}
}