#include <iostream>
#include <string>
#include <random>
using namespace std;

//게임 설명 : 두 플레이어의 이름을 입력 후 엔터를 누를 때마다 세 개의 숫자가 0~2 중 랜덤하게 설정, 세 개의 숫자가 전부 같아지면 게임 승리

class Player {
	string player;
public:
	string getPlayer1Name() {
		cout << "첫번째 선수 이름>>";
		getline(cin, player, '\n');
		return player;
	}

	string getPlayer2Name() {
		cout << "두번째 선수 이름>>";
		getline(cin, player, '\n');
		return player;
	}
};

class GamblingGame {
	int threenum[3];
	int flag;
public:
	void GambleGame(string p1, string p2) {
		random_device rd;							//난수관련코드
		mt19937 gen(rd());							//난수관련코드
		uniform_int_distribution<int> dis(0, 2);	//난수관련코드
		while (1) {

			cout << p1 << ":<Enter>" << endl;
			flag = getchar();
			for (int i = 0; i < 3; i++) {
				threenum[i] = dis(gen);
			}

			if (threenum[0] == threenum[1] && threenum[1] == threenum[2] && threenum[2] == threenum[0]) {
				cout << threenum[0] << "     " << threenum[1] << "     " << threenum[2] << "     " << p1 << "님 승리!!" << endl;
				break;
			}

			else
				cout << threenum[0] << "     " << threenum[1] << "     " << threenum[2] << "     아쉽군요!" << endl;


			cout << p2 << ":<Enter>" << endl;
			flag = getchar();
			for (int i = 0; i < 3; i++) {
				threenum[i] = dis(gen);
			}

			if (threenum[0] == threenum[1] && threenum[1] == threenum[2] && threenum[2] == threenum[0]) {
				cout << threenum[0] << "     " << threenum[1] << "     " << threenum[2] << "     " << p2 << "님 승리!!" << endl;
				break;
			}

			else
				cout << threenum[0] << "     " << threenum[1] << "     " << threenum[2] << "     아쉽군요!" << endl;

		}
	}
};


int main() {

	string playerName[2];
	Player players;
	playerName[0] = players.getPlayer1Name();
	playerName[1] = players.getPlayer2Name();

	GamblingGame game;
	game.GambleGame(playerName[0], playerName[1]);
	
}