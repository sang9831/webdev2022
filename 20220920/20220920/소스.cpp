#include <iostream>
using namespace std;

//참조 리턴
//참조 = 별명
char& find(char s[], int index) { //공간에 대한 참조 리턴하는 함수
	return s[index];
}

int main() {
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S';
	cout << name << endl;

	char& ref = find(name, 2);  //ref는 name[2]에 대한 참조
	ref = 't';
	cout << name << endl;
}