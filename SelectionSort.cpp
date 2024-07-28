#include <iostream>
using namespace std;

void swap(int &a, int&b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void selectionSort(long a[], int n) {
	int pos;
	for (int i = 0; i < n - 1; i++) {
		pos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[pos] > a[j]) {
				pos = j;
			}
		}
		swap(a[pos], a[i]);
	}
}

void insertionSort(long a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int x = a[i];
		int j = i - 1;
		while (0 <= j && x < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

void bubbleSort(long a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}

void interchangeSort(long a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

void merge(long arr[], int l, int mid, int r) {
	int n1 = mid - l + 1;
	int n2 = r - mid;

	long* a = new long[n1];
	long* b = new long[n2];

	for (int i = 0; i < n1; i++) {
		a[i] = arr[l + i];
	}
	for (int i = 0; i < n2; i++) {
		b[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2) {
		if (a[i] <= b[j]) {
			arr[k] = a[i];
			i++;
		}
		else {
			arr[k] = b[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = a[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = b[j];
		j++;
		k++;
	}

	delete[] a;
	delete[] b;
}

void mergeSort(long a[], int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);
		merge(a, l, mid, r);
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

	mergeSort(a, 0, n-1);
	printList(a, n);

	return 1;
}