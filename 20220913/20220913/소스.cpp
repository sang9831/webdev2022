#include <string>
#include <iostream>
using namespace std;

int main() {
	string names[5];  //string 배열 5개 선언

	for (int i = 0; i < 5; i++) {
		cout << "이름 >> ";
		getline(cin, names[i], '\n');  //문자열 입력
	}

	string latter = names[0];  //string 배열 첫번째 문자열을 latter에 저장
	for (int i = 0; i < 5; i++) {
		if (latter < names[i]) {
			latter = names[i];  //latter가 name[i]보다 앞일 경우 latter에 name[i] 문자열 저장 
		}
	}

	cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;
}