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
	int prevPlayer1StartPoint = 0;
	int prevPlayer1EndPoint = 8;
	int prevPlayer2StartPoint = 0;
	int prevPlayer2EndPoint = 8;
	int ballY = 10;
	int ballX = 10;
	bool player1Shot = true;
	bool player2Shot = false;
	int player1Points = 0;
	int player2Points = 0;

	//cout << "Press enter to start the game" << endl;

	//if (_getch() == 13) {
	while (true) {
		system("CLS");
		//COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
/*
		player1StartPoint = prevPlayer1StartPoint;
		player1EndPoint = prevPlayer1EndPoint;
		player2StartPoint = prevPlayer2StartPoint;
		player2EndPoint = prevPlayer2EndPoint;*/

		if (_kbhit()) {

			if (GetAsyncKeyState('S') & 0x8000f) {
				player1StartPoint = player1StartPoint++;
				player1EndPoint = player1EndPoint++;
			}
			else if (GetAsyncKeyState('W') & 0x8000f) {
				player1StartPoint = player1StartPoint--;
				player1EndPoint = player1EndPoint--;
			}

			if (GetAsyncKeyState('L') & 0x8000f) {
				player2StartPoint = player2StartPoint++;
				player2EndPoint = player2EndPoint++;
			}
			else if (GetAsyncKeyState('O') & 0x8000f) {
				player2StartPoint = player2StartPoint--;
				player2EndPoint = player2EndPoint--;
			}
		}
		for (size_t i = 0; i < 25; i++)
		{
			if (i >= player1StartPoint && i < player1EndPoint) {
				cout << "++++";
			}
			else {
				cout << "    ";
			}
			if (i == ballY)
			{
				switch (ballX)
				{
				case 1:
					cout << "*                   ";
					break;
				case 2:
					cout << " *                  ";
					break;
				case 3:
					cout << "  *                 ";
					break;
				case 4:
					cout << "   *                ";
					break;
				case 5:
					cout << "    *               ";
					break;
				case 6:
					cout << "     *              ";
					break;
				case 7:
					cout << "      *             ";
					break;
				case 8:
					cout << "       *            ";
					break;
				case 9:
					cout << "        *           ";
					break;
				case 10:
					cout << "         *          ";
					break;
				case 11:
					cout << "          *         ";
					break;
				case 12:
					cout << "           *        ";
					break;
				case 13:
					cout << "            *       ";
					break;
				case 14:
					cout << "             *      ";
					break;
				case 15:
					cout << "              *     ";
					break;
				case 16:
					cout << "               *    ";
					break;
				case 17:
					cout << "                *   ";
					break;
				case 18:
					cout << "                 *  ";
					break;
				case 19:
					cout << "                  * ";
					break;
				case 20:
					cout << "                   *";
					break;
				default:
					cout << "                    ";
					break;
				}
				if (ballX == 1) {
					player1Shot = true;
					player2Shot = false;
				}
				else if (!(i >= player1StartPoint && i < player1EndPoint) && ballX == 2) {
					player2Points++;
					system("CLS");
					cout << "Player 2 wins" << endl;
					for (size_t j = 0; j < 7; j++)
					{
						cout << "                    " << endl;
					}
					system("pause>0");
				}
				if (ballX == 20) {
					player1Shot = false;
					player2Shot = true;
				}
				else if (!(i >= player2StartPoint && i < player2EndPoint) && ballX == 19) {
					player1Points++;
					system("CLS");
					cout << "Player 1 wins" << endl;
					for (size_t j = 0; j < 7; j++)
					{
						cout << "                    " << endl;
					}
					system("pause>0");
				}
				if (player1Shot) {
					ballX++;
				}
				else if (player2Shot) {
					ballX--;
				}
			}
			else {
				cout << "                    ";
			}
			if (i >= player2StartPoint && i < player2EndPoint) {
				cout << "++++" << endl;
			}
			else {
				cout << endl;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	/*	prevPlayer1StartPoint = player1StartPoint;
		prevPlayer1EndPoint = player1EndPoint;
		prevPlayer2StartPoint = player2StartPoint;
		prevPlayer2EndPoint = player2EndPoint;*/
		//cout << "Player 1 score: " << player1Points << endl;
		//cout << "Player 2 score: " << player2Points << endl;
	}

	system("pause>0");
	//	}
}