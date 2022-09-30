#include <iostream>
using namespace std;

class Adder {
protected:
	int add(int a, int b) {
		return a + b;
	}
};

class Subtractor {
protected:
	int minus(int a, int b) {
		return a - b;
	}
};

class Calculator :public Adder, public Subtractor { //다중 상속
public:
	int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b) {
	int res = 0;
	switch (op) {
		case '+':res = add(a, b); break; //Adder클래스의 add() 호출
		case '-':res = minus(a, b); break; //Subtractor클래스의 minus() 호출
	}
	return res;
}

int main() {
	Calculator handCalculator;
	cout << "2 + 4 = " << handCalculator.calc('+', 2, 4) << endl;
	cout << "100 - 8 = " << handCalculator.calc('-', 100, 8) << endl;
}