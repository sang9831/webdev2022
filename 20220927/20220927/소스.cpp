#include <iostream>
#include <string>
using namespace std;

class Point {
protected:  //protected 파생클래스와 멤버를 선언한 클래스에서만 접근 가능
	int x, y;
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point { //클래스 상속 파생 클래스 ColorPoint 클래스는 Point의 멤버변수, 함수 상속받음
	string color;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint();
	bool equals(ColorPoint p);
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

bool ColorPoint::equals(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color) {
		return true;
	}
	else {
		return false;
	}

}
int main() {
	Point p;
	p.set(2, 3);
	//p.x = 5; // Point 클래스의 멤버변수 x와y는 protected로 보호받고 있어서 외부함수에서 접근불가능
	//p.y = 5; 
	p.showPoint();

	ColorPoint cp;
	//cp.x = 10;
	//cp.y = 10;
	cp.set(3, 4);
	cp.setColor("Red");

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false");
}