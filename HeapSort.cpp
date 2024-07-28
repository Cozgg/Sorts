#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void heapify(long a[], int i, int n) {
	int j = 2 * i + 1;
	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		heapify(a, j, n);
	}
}

void HeapSort(long a[], int n) {
	int i = n / 2 - 1;
	while (i >= 0) {
		heapify(a, i, n);
		i--;
	}
	int right = n - 1;
	while (right > 0) {
		swap(a[0], a[right]);
		if (right > 0)
			heapify(a, 0, right);
		right--;
	}
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
	
	HeapSort(a, n);
	printList(a, n);

	return 1;
}