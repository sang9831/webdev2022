#include <string>
#include <vector>
#include <iostream>
using namespace std;

void vectorUI(vector<int> x) {
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void merge(vector<int>& v, int s, int m, int e) {

	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

void mergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		mergeSort(v, s, m);
		mergeSort(v, m + 1, e);
		merge(v, s, m, e);
	}
}

int main() {
	
	vector<int> a = { 2, 3, 1, 5, 4, 8, 10, 6, 9, 7 };
	int n = a.size();

	cout << "before : ";
	vectorUI(a);
	mergeSort(a, 0, n - 1);
	cout << "after : ";
	vectorUI(a);

}