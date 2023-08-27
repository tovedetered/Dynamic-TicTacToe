#include "textBoard.h"
#include <iostream>
#include <SKUtils.h>

using namespace std;

TextBoard::TextBoard(unsigned int startRows, unsigned int startColumns, unsigned int winCond) :
	Board(startRows, startColumns, winCond)
{


}

void TextBoard::drawBoard() {
	int j = 0;

	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < columns; y++) {
			if (y < columns - 1) {
				cout << " " << *(spaces + x * columns + y) << " " << "|";
			}
			else {
				cout << " " << *(spaces + x * columns + y) << " ";
			}
		}
		cout << endl;
		j++;
		for (int i = 0; i < columns; i++) {
			if (j < rows) {
				if (i < columns - 1) {
					cout << "---|";
				}
				else {
					cout << "---";
				}
			}
		}
		cout << endl;
	}
	j = 0;
}

void TextBoard::getInput()
{
	bool inputCheck = true;
	int column = -1;
	int row = -1;
	while (inputCheck) {
		std::cout << "Please indicate the column you would like to play: ";
		std::cin >> column;
		column = CheckInput(column);
		while (true) {
			if (column > columns || column < 0) {
				std::cout << "Invalid Input, Enter a Number between 0 and " << columns << ": ";
				std::cin >> column;
				column = CheckInput(column);
			}
			else {
				break;
			}
		}
		std::cout << "Please indicate the row where you would like to play: ";
		std::cin >> row;
		row = CheckInput(row);
		while (true) {
			if (row > rows || rows < 0) {
				std::cout << "Invalid Input, Enter a Number between 0 and " << rows << ": ";
				std::cin >> row;
				row = CheckInput(row);
			}
			else {
				break;
			}
		}
		if (spaces[row * column] != ' ') {
			std::cout << "That Space is Already Taken!";
		}

	}
}
