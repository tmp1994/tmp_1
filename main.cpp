#include <iostream>
#include <string>

using namespace std;


void BinSum(int*, int*, int*, int);

int main() {
	const int n = 4;
	int a[] = {1, 1, 1, 1};
	int b[] = {1, 0, 0, 0};
	int c[n+1] = {0};
	BinSum(a, b, c, n);
	cout << "0 0 " << c[0] << endl;
	for (int i(0); i < n; i++) {
		cout << a[i] << " " << b[i] << " " << c[i+1] << endl;
	}
	system("pause");
	return 0;
}

void BinSum(int *a, int *b, int *c, int n) {
	int k(0);
	for (int i(n-1); i >= 0; i--) {
		int rez = a[i] + b[i] + k;
		if (rez < 2) {
			c[i+1] = rez;
			k = 0;
		}
		else {
			c[i+1] = rez - 2;
			k = 1;
		}
	}
	c[0] = k;
}