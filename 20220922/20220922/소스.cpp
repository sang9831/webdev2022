#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class UpAndDownGame { 

public:

	static int n;
	static void GamePlay(string p1, string p2) {
		srand((unsigned)time(0));
		n = rand();
		n = n % 100;
		int num1 = 0;
		int num2 = 99;
		int answer = 0;
		cout << n << endl;
		cout << "Up & Down ������ �����մϴ�." << endl;

		while (1) { 
			if (answer < n) {
				cout << "���� " << answer << "��" << num2 << "���̿� �ֽ��ϴ�." << endl;
				cout << p1 << ">>";
				cin >> answer;
				if (answer == n) {
					cout << p1 << "�� �̰���ϴ�!!";
					break;
				}
				num2 = answer;
			}
			else if (answer > n) {
				cout << "���� " << num1 << "��" << answer << "���̿� �ֽ��ϴ�." << endl;
				cout << p1 << ">>";
				cin >> answer;
				if (answer == n) {
					cout << p1 << "�� �̰���ϴ�!!";
					break;
				}
				num1 = answer;
			}
			

			if (answer < n) {
				cout << "���� " << answer << "��" << num2 << "���̿� �ֽ��ϴ�." << endl;
				cout << p2 << ">>";
				cin >> answer;
				if (answer == n) {
					cout << p2 << "�� �̰���ϴ�!!";
					break;
				}
				num2 = answer;
			}
			else if (answer > n) {
				cout << "���� " << num1 << "��" << answer << "���̿� �ֽ��ϴ�." << endl;
				cout << p2 << ">>";
				cin >> answer;
				if (answer == n) {
					cout << p2 << "�� �̰���ϴ�!!";
					break;
				}
				num1 = answer;
			}
			
		}
	}
};

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

int UpAndDownGame::n = 0;

int main() {
	string playerName[2];
	Player players;
	playerName[0] = players.getPlayer1Name();
	playerName[1] = players.getPlayer2Name();

	UpAndDownGame game;
	game.GamePlay(playerName[0], playerName[1]);
}