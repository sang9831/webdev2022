#include <iostream>
using namespace std;


//다중 상속의 문제점 : 다중 상속시 기본 클래스 멤버 접근에 모호함 발생
//문제 해결 : virtual 키워드로 가상 상속 선언, 첫 상속때는 변수 공간을 할당하지만 두번째 상속때는 변수 공간 할당x

class BaseID {
public:
	int mode;
};

class In : virtual public BaseID { //가상상속
public:
	int readPos;
};

class Out : virtual public BaseID { //가상상속
public:
	int writePos;
};

class InOut : public In, public Out {
public:
	bool safe;
};

int main() {
	InOut ioObj;

	ioObj.readPos = 10;
	ioObj.writePos = 20;
	ioObj.safe = true;
	ioObj.mode = 5;
}