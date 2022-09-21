#include <iostream>
using namespace std;

//static멤버
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

int Person::sharedMoney = 10; //전역 공간에 static 변수 생성, 10으로 초기화

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