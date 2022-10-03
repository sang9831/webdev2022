#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) {
		this->radius = radius;
	}

	int getRadius() {
		return radius;
	}
};

template <class T>
void myswap(T& a, T& b) {  //���׸� �Լ�
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 4, b = 5;
	myswap(a, b);    //myswap(int &a, int &b) �Լ� ��üȭ �� ȣ��
	cout << "a=" << a << ", " << "b=" << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d);      //myswap(double &a, double &b) �Լ� ��üȭ �� ȣ��
	cout << "c=" << c << ", " << "d=" << d << endl;

	Circle donut(5), pizza(20);
	myswap(donut, pizza);       //myswap(Circle &a, Circle &b) �Լ� ��üȭ �� ȣ��
	cout << "donutRadius=" << donut.getRadius() << ", ";
	cout << "pizzaRadius=" << pizza.getRadius() << endl;
}