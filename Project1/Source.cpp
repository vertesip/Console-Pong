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
	int ballY = 5;
	int ballX = 1;
	bool player1Shot;
	bool player2Shot;

	while (true) {
	
	int player1pressedKey = 3;
	int player2pressedKey = 3;
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
					else if (ballX == 20) {
						player1Shot = false;
						player2Shot = true;
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
				
			}
			else {
				cout << "    ";
				cout << "                    ";
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