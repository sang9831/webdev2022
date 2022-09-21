#include <iostream>
using namespace std;

//static���
class Person {
public:
	double money;
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney;  
	static void addShared(int n) {
		sharedMoney += n;
	}
};

int Person::sharedMoney = 10; //���� ������ static ���� ����, 10���� �ʱ�ȭ

int main() {
	Person A;
	A.money = 100;
	A.sharedMoney = 200;

	Person B;
	B.money = 150;
	B.addMoney(200);
	B.addShared(200);
	cout << A.money << ' ' << B.money << endl;
	cout << A.sharedMoney << ' ' << B.sharedMoney << endl;
}