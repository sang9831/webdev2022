#include <iostream>
using namespace std;

class Rect; //Rect 클래스가 선언되기전에 참조되는 컴파일 오류를 막기위해 먼저 선언

class RectManager {
public:
	bool equals(Rect r, Rect s);
};

class Rect {
	int width, height;

public:
	Rect(int width, int height) {
		this->width = width;
		this->height = height;
	}

	friend bool RectManager::equals(Rect r, Rect s); //RectManager클래스의 equals() 멤버함수를 프렌드로 지정. 클래스 전체를 프렌드 지정도 가능
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) {
		return true;
	}
	else
		return false;
}

int main() {
	Rect a(3, 4), b(3, 4);
	RectManager man;

	if (man.equals(a, b)) {
		cout << "equal" << endl;
	}
	else
		cout << "not equal" << endl;
}