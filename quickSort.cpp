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
int paritition(vector<int>& a, int left, int right)
{

	int pivot = a[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= right && pivot >= a[low])
		{
			low++;
		}
		while (high >= (left + 1) && pivot <= a[high])
		{
			high--;
		}
		if (low <= high)
		{

			int temp = a[low];
			a[low] = a[high];
			a[high] = temp;


		}


	}

	int temp = a[left];
	a[left] = a[high];
	a[high] = temp;

	return high;



}

void quickSort(vector<int>& a, int left, int right)
{
	if (left < right)
	{
		int q = paritition(a, left, right);
		quickSort(a, left, q - 1);
		quickSort(a, q + 1, right);

	}

}

int main() {
	
	vector<int> a = { 2, 3, 1, 5, 4, 8, 10, 6, 9, 7 };
	int n = a.size();

	cout << "before : ";
	vectorUI(a);
	quickSort(a, 0, n - 1);
	cout << "after : ";
	vectorUI(a);

}