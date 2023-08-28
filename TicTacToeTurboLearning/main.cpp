#include <iostream>
#include <SKUtils.h>
#include "textBoard.h"

using namespace std;

void startUp();
void mainMenu();
void configGame();
void checkRules();
void runGame();
void twoPlayerGame();
void goodBye();

struct gameSettings {
	int columns = 3;
	int rows = 3;
	int winCondition = 3;
};
gameSettings game;

int main() {
	
	startUp();

	mainMenu();

	goodBye();

	return 0;
}

void startUp() {
	cout << "***** Dynamic Tic-Tac-Toe *****" << endl
		<< "Welcome to Dynamic Tic-Tac-Toe!" << endl
		<< "Menu Options are selected using number keys!" << endl
		<< "For example: to select 1. Title, you would type 1 then [Enter]" << endl;
}

void mainMenu() {
	bool running = true;
	unsigned int choice = 0;
	int columns = 3;
	int rows = 3;
	int winConditon = 3;

	while (running) {
		cout << "***** Main Menu *****" << endl
			<< "1. Configure Game" << endl
			<< "2. Rules" << endl
			<< "3. Play!" << endl
			<< "4. Quit" << endl
			<< "*********************" << endl;
		cin >> choice;
		choice = CheckInput(choice);

		switch (choice) {
		case 1:
			configGame();
			break;
		case 2:
			checkRules();
			break;
		case 3:
			runGame();
			break;
		default:
			running = false;
			break;
		}
	}
}

void configGame()
{
	int columns = 3;
	int rows = 3;
	int winConditon = 3;

	cout << "***** Game Configurator *****" << endl
		<< "# of columns (max 500): ";
	cin >> columns;
	columns = CheckInput(columns);
	columns = clamp(1, columns, 500);

	cout << "# of rows (max 500): ";
	cin >> rows;
	rows = CheckInput(rows);
	rows = clamp(1, rows, 500);

	cout << "Win condition (cannot be greater than either # of rows or columns): ";
	cin >> winConditon;
	winConditon = CheckInput(winConditon);
	winConditon = clamp(1, winConditon, columns);
	winConditon = clamp(1, winConditon, rows);

	game.columns = columns;
	game.rows = rows;
	game.winCondition = winConditon;

	cout << "*********************" << endl;
}

void checkRules() {
	cout << "***** Rules *****" << endl
		<< "Players take turns placing their symbols on a board" << endl
		<< "With the goal of having a certain number of their symbols next to each-other" << endl
		<< "Either in a row across" << endl
		<< "A Column down" << endl
		<< "Or diagonally across the board" << endl
		<< "Players cannot take each other's spots" << endl
		<< "*********************" << endl;
}

void runGame() {
	unsigned int choice = 0;

	cout << "***** Game Menu *****" << endl
		<< "1. Play With a Friend!" << endl
		<< "2. Back" << endl;
	cin >> choice;
	choice = CheckInput(choice);

	switch (choice) {
	 case 1:
		 twoPlayerGame();
	 default:
		 break;

	}

}

void twoPlayerGame()
{
	bool playing = true;
	int choice = 0;

	while (playing) {

		bool running = true;

		Board* board = new TextBoard(game.rows, game.columns, game.winCondition);

		cout << "***** Two Player Game *****" << endl
			<< "Welcome! Player One will be X and Player Two will be O!" << endl
			<< "To place your symbol in a position select a row (1-max)" << endl
			<< "Then select a column (1-max)" << endl
			<< "3... 2... 1... Beginning Game" << endl;
		
		cout << "**********************" << endl;
		board->drawBoard();
		cout << "**********************" << endl;

		while (running) {
			//Player One Turn
			cout << "***** Player One *****" << endl;
			board->playerTurn(1);
			if (board->checkWinner()) {
				cout << "Player One Won!" << endl
					<< "Congratulations!" << endl;
				running = false;
				break;
			}
			if (board->checkTie()) {
				cout << "Its a Tie!" << endl;
			}
			cout << "**********************" << endl;

			//Player Two Turn
			cout << "***** Player Two *****" << endl;
			board->playerTurn(2);
			if (board->checkWinner()) {
				cout << "Player Two Won!" << endl
					<< "Congratulations!" << endl;
				running = false;
				break;
			}
			if (board->checkTie()) {
				cout << "Its a Tie!" << endl;
			}
			cout << "**********************" << endl;
		}

		delete board;

		cout << "Would you like to play again?" << endl
			<< "1 for Yes, 2 for No" << endl;
		cin >> choice;
		choice = CheckInput(choice);
		choice = clamp(1, choice, 2);
		if (choice == 2) {
			playing = false;
			break;
		}
		else if (choice == 1) {
			cout << "Resetting Game!" << endl;
		}
		else {
			throw unexpected;
		}
	}
}

void goodBye()
{
	cout << "***** Good Bye *****" << endl;
	cout << "This Game was Made by:" << endl
		<< "Spenser Kramer" << endl
		<< "With Help From: " << endl
		<< "Trevor Kramer" << endl
		<< "Thanks For Playing!" << endl;
}
