#include <vector>
#include <iostream>
using namespace std;

void vectorUI(vector<int> x) {
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

//int fibonacci(int x) {
//	vector<int> a;
//	if (x == 0) {
//		a.push_back(0);
//	}
//	else if (x == 1) {
//		a.push_back(1);
//	}
//	else if (x >= 2) {
//		int sum = a[]
//	}
//}

int solution(int x) {
    int answer = 0;
	vector<int> a;
	for (int i = 0; i <= x; i++) {
		if (i == 0) {
			a.push_back(0);
		}
		else if (i == 1) {
			a.push_back(1);
		}
		else if (i >= 2) {
			int sum = a[i - 2] % 1234567 + a[i - 1] % 1234567;
			a.push_back(sum);
		}
	}
	answer = a[x] % 1234567;
    return answer;
}

int main() {
    cout << solution(30);
}