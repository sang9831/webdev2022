#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(vector<int>a) {
	int max_index = 0;
	int max = 0;
	int tmp = 0;
	vector<int> b;
		
	while (!a.empty()) {
		cout << "a = ";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i];
		}
		cout << endl;
		max_index = max_element(a.begin(), a.end()) - a.begin();
		tmp = a.back();
		a.back() = *max_element(a.begin(), a.end());
		a[max_index] = tmp;
		b.push_back(a.back());
		a.pop_back();
	}

	reverse(b.begin(), b.end());
	cout << "b = ";
	for (int i = 0; i < b.size(); i++) {
		cout << b[i];
	}
	cout << endl;
}

int main() {
	vector<int> a = { 2, 3, 1, 5, 4 };
	selectionSort(a);
}