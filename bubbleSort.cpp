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

void bubbleSort(vector<int>a) {
	int tmp = 0;
	int cnt = 0;
	int max = 0;
	vector<int> b;

	while (!a.empty()) {
		if (a.size() == 1) {
			
		}
		else if (a[cnt] <= a[cnt + 1]) {
			cnt++;
		}
		else if(a[cnt] > a[cnt + 1]){
			tmp = a[cnt];
			a[cnt] = a[cnt + 1];
			a[cnt + 1] = tmp;
			cnt++;
		}

		vectorUI(a);

		if (cnt == a.size()-1) {
			max = a.back();
			a.pop_back();
			b.push_back(max);
			cnt = 0;
			cout << "b : ";
			vectorUI(b);
			cout << "popÈÄ : ";
			vectorUI(a);
		}
		
	}
}

int main() {
	vector<int> a = { 2, 3, 1, 5, 4, 8, 10, 6, 9, 7 };
	bubbleSort(a);
}