#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;

int main() {
	//Set the start values outside the game loop
	int player1StartPoint = 3;
	int player1EndPoint = 9;
	int player2StartPoint = 3;
	int player2EndPoint = 9;
	int ballY = 5;
	int ballX = 10;
	bool player1Shot = true;
	bool player2Shot = false;
	bool player1ShotTopEdge = false;
	bool player2ShotTopEdge = false;
	bool player1ShotBottomEdge = false;
	bool player2ShotBottomEdge = false;
	int player1Points = 0;
	int player2Points = 0;
	bool gameEnd = false;

	cout << "Press enter to start the game (if it does not start, press enter a couple more times)" << endl;
	cout << "Player 1 movement: W for up, S for down" << endl;
	cout << "Player 2 movement: O for up, L for down" << endl;

	if (_getch() == 13) {

	while (true) {

	// If the game ends, reset everything

		if (gameEnd) {
			ballX = 10;
			ballY = 5;
			gameEnd = false;
		}

	// Clear screen
		system("CLS");

	//Player movement
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

		//Main loop for drawing the game

		for (size_t i = 0; i < 25; i++)
		{

			//Draw player one
			if (i >= player1StartPoint && i < player1EndPoint) {
				cout << "|";
			}
			else {
				cout << " ";
			}

			//Draw the ball at the correct X position
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

				//If the ball hits player one the boolean is set to true to increment the value later
				if (ballX == 1) {
					player1Shot = true;
					player2Shot = false;
				}
				else if (!(i >= player1StartPoint && i < player1EndPoint) && ballX == 2) {
					//If the ball is not hit by the player, the game ends
					player2Points++;
					system("CLS");
					cout << "Player 2 wins" << endl;
					for (size_t j = 0; j < 7; j++)
					{
						cout << "                    " << endl;
					}
					gameEnd = true;
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
					gameEnd = true;
					system("pause>0");
				}
				//Increment the X value to move the ball horizontally
				if (player1Shot) {
					ballX++;
				}
				else if (player2Shot) {
					ballX--;
				}
			}
			else {
			//Draw some empty line where nothing is
				cout << "                    ";
			}
			if (i >= player2StartPoint && i < player2EndPoint) {
				//Draw player 2 where the coordinates appear
				cout << "|" << endl;
			}
			else {
				cout << endl;
			}
		}

		//Setting the players booleans to false if the other player hit the ball

		if (player2Shot) {
			player1ShotTopEdge = false;
			player1ShotBottomEdge = false;
		}
		if (player1Shot) {
			player2ShotTopEdge = false;
			player2ShotBottomEdge = false;
		}

		/// /////////////////////////
		//If a player hit the ball at the edge, it will also move vertically

		if (player1Shot && ballX < player1StartPoint + 1) {
			player1ShotTopEdge = true;
		}
		if (player1ShotTopEdge) {
			ballY--;
		}
		if (player1Shot && ballX > player1EndPoint - 1) {
			player1ShotBottomEdge = true;
		}
		if (player1ShotBottomEdge) {
			ballY++;
		}

		/// /////////////////////////

		if (player2Shot && ballX < player2StartPoint + 1) {
			player2ShotTopEdge = true;
		}
		if (player2ShotTopEdge) {
			ballY--;
		}
		if (player2Shot && ballX > player2EndPoint - 1) {
			player2ShotBottomEdge = true;
		}
		if (player2ShotBottomEdge) {
			ballY++;
		}

		/// /////////////////////////
		//Save the balls if they want to go outside the playground

		if (ballY <= 0) {
			ballY++;
		}
		if (ballY == 20) {
			ballY--;
		}

		//Just logging out the scoreboard
		cout << "Player 1 score: " << player1Points << endl;
		cout << "Player 2 score: " << player2Points << endl;

		//Slow down the game loop
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	system("pause>0");
		}
}