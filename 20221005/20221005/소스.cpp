#include <iostream>
using namespace std;

class output {
public:
	void out() {
		cout.put('H');
		cout.put('i');
		cout.put(33);
		cout.put('\n');


		cout.put('C').put('+').put('+').put(' ');

		char str[] = "I love programming";
		cout.write(str, 6);
	}
};

class input {
public:
	void in() {
		cout << "cin.get()�� <Enter> Ű���� �Է� �ް� ����մϴ�>>";
		int ch;
		while ((ch = cin.get()) != EOF) {
			cout.put(ch);
			if (ch == '\n') {
				break;
			}
		}
	}
};

int main() {
	output out;
	input in;

	out.out();
	cout << "\n" << "-------------------------------" << endl;
	in.in();
}