#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(long a[], int left, int right) {
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j) QuickSort(a, left, j);
	if (i < right) QuickSort(a, i, right);
}

void printList(long a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	long a[] = { 65, 73, 88, 12, 100, 93, 27 };
	int n = sizeof(a) / sizeof(a[0]);

	QuickSort(a, 0, n - 1);
	printList(a, n);

	return 1;
}