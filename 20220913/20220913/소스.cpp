#include <string>
#include <iostream>
using namespace std;

int main() {
	string names[5];  //string �迭 5�� ����

	for (int i = 0; i < 5; i++) {
		cout << "�̸� >> ";
		getline(cin, names[i], '\n');  //���ڿ� �Է�
	}

	string latter = names[0];  //string �迭 ù��° ���ڿ��� latter�� ����
	for (int i = 0; i < 5; i++) {
		if (latter < names[i]) {
			latter = names[i];  //latter�� name[i]���� ���� ��� latter�� name[i] ���ڿ� ���� 
		}
	}

	cout << "�������� ���� �ڿ� ������ ���ڿ��� " << latter << endl;
}