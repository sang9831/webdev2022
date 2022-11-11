#include <vector>
#include <iostream>
using namespace std;

void vectorUI(vector<int> x) {
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void insertionSort(vector<int> &a) {
	int i, j, tmp;
	for (i = 1; i < a.size(); i++) {
		tmp = a[i];
		for (j = i-1; j >= 0; j--) {
			if (a[j] > tmp) {
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = tmp;
	}
}

int main() {
	vector<int> a = { 2, 3, 1, 5, 4, 8, 10, 6, 9, 7 };
	vectorUI(a);
	insertionSort(a);
	vectorUI(a);
}