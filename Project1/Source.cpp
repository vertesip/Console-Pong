#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;

int main() {
	int player1StartPoint = 0;
	int player1EndPoint = 8;
	int player2StartPoint = 0;
	int player2EndPoint = 8;
	int ball = 5;

	while (true) {
	
	int player1pressedKey = _getch();
	int player2pressedKey = _getch();
	if (player1pressedKey || player2pressedKey > 0) {
		system("CLS");
	}
	if (player1pressedKey == 's') {
		player1StartPoint = player1StartPoint++;
		player1EndPoint = player1EndPoint++;
	}
	else if (player1pressedKey == 'w') {
		player1StartPoint = player1StartPoint--;
		player1EndPoint = player1EndPoint--;
	}

	if (player2pressedKey == 'l') {
		player2StartPoint = player2StartPoint++;
		player2EndPoint = player2EndPoint++;
	}
	else if (player2pressedKey == 'o') {
		player2StartPoint = player2StartPoint--;
		player2EndPoint = player2EndPoint--;
	}

	for (size_t i = 0; i < 30; i++)
	{
		if (i >= player1StartPoint && i < player1EndPoint || i >= player2StartPoint && i < player2EndPoint)
		{
			if (i >= player1StartPoint && i < player1EndPoint) {
				cout << "++++";
				cout << "                                                            ";
			}
			else {
				cout << "    ";
				cout << "                                                            ";
			}
			
			if (i >= player2StartPoint && i < player2EndPoint) {
				cout << "++++" << endl;
			}
			else {
				cout << endl;
			}
	
		}
		else {
			cout << endl;
		}
	}
	}
	system("pause>0");
}