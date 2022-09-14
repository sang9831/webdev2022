#include <iostream>
#include <string>
#include <random>
using namespace std;

//���� ���� : �� �÷��̾��� �̸��� �Է� �� ���͸� ���� ������ �� ���� ���ڰ� 0~2 �� �����ϰ� ����, �� ���� ���ڰ� ���� �������� ���� �¸�

class Player {
	string player;
public:
	string getPlayer1Name() {
		cout << "ù��° ���� �̸�>>";
		getline(cin, player, '\n');
		return player;
	}

	string getPlayer2Name() {
		cout << "�ι�° ���� �̸�>>";
		getline(cin, player, '\n');
		return player;
	}
};

class GamblingGame {
	int threenum[3];
	int flag;
public:
	void GambleGame(string p1, string p2) {
		random_device rd;							//���������ڵ�
		mt19937 gen(rd());							//���������ڵ�
		uniform_int_distribution<int> dis(0, 2);	//���������ڵ�
		while (1) {

			cout << p1 << ":<Enter>" << endl;
			flag = getchar();
			for (int i = 0; i < 3; i++) {
				threenum[i] = dis(gen);
			}

			if (threenum[0] == threenum[1] && threenum[1] == threenum[2] && threenum[2] == threenum[0]) {
				cout << threenum[0] << "     " << threenum[1] << "     " << threenum[2] << "     " << p1 << "�� �¸�!!" << endl;
				break;
			}

			else
				cout << threenum[0] << "     " << threenum[1] << "     " << threenum[2] << "     �ƽ�����!" << endl;


			cout << p2 << ":<Enter>" << endl;
			flag = getchar();
			for (int i = 0; i < 3; i++) {
				threenum[i] = dis(gen);
			}

			if (threenum[0] == threenum[1] && threenum[1] == threenum[2] && threenum[2] == threenum[0]) {
				cout << threenum[0] << "     " << threenum[1] << "     " << threenum[2] << "     " << p2 << "�� �¸�!!" << endl;
				break;
			}

			else
				cout << threenum[0] << "     " << threenum[1] << "     " << threenum[2] << "     �ƽ�����!" << endl;

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