#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void vectorUI(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n--------------------------------------------\n";
}


void heapify(vector<int>& v, int k, int size) {
	int left = 2 * k+1;
	int right = 2 * k + 2;
	int smaller;

	if (right < size) {
		if (v[left] < v[right]) {
			smaller = left;
		}
		else
			smaller = right;
	}
	else if (left < size) {
		smaller = left;
	}
	else
		return;

	if (v[smaller] < v[k]) {
		swap(v[k], v[smaller]);
		heapify(v, smaller, size);
	}
}

void buildHeap(vector<int> &v, int size) {
	for (int i = (size - 1) / 2; i >= 0; i--) {
		heapify(v, i, size);
	}
}

void heapSort(vector<int> &v, int size) {
	buildHeap(v, size);
	for (int i = size; i >= 1; i--) {
		swap(v[0], v[i - 1]);
		heapify(v, 0, i - 2);
	}
}

int main() {

	vector<int> a = { 2, 3, 1, 5, 4, 8, 10, 6, 9, 7 };
	cout << "before : ";
	vectorUI(a);
	heapSort(a, a.size());
	cout << "after : ";
	vectorUI(a);

}