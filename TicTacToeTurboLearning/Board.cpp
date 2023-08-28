#include "Board.h"
#include <iostream>
#include <SKUtils.h>
#include "textBoard.h"
#include <exception>


Board::Board(unsigned int startRows, unsigned int startColumns, unsigned int winCond) : 
			 rows(startRows), columns(startColumns), winCondition(winCond), spaces(new char[rows * columns])
{
	activePlayerChar = playerOne;
	initBoard();
	
}

Board::~Board() 
{
	delete[] spaces;
}

void Board::initBoard()
{
	for (int i = 0; i < rows * columns; i++) {
		spaces[i] = ' ';
	}
}

void Board::updateBoard()
{
	bool checkInput = true;

	while (checkInput) {
		if (selectedRow < 0 || selectedRow > rows) {
			throw unexpected;
		}
		if (selectedColumn < 0 || selectedColumn > rows) {
			throw unexpected;
		}
		else {
			checkInput = false;
		}
	}

	spaces[(selectedRow * columns) + selectedColumn] = activePlayerChar;
	drawBoard();
}

void Board::playerTurn(int turn) {
	
	if (turn == 1) {
		getInput();
		updateBoard();
	}
	else if (turn == 2) {
		getInput();
		updateBoard();
	}
	else {
		throw unexpected;
	}

}

bool Board::checkWinner()
{
	for (int i = 0; i < rows; i++) {
		int counter = 0;
		for (int j = 0; j < columns; j++) {
			if (spaces[(i * columns) + j] == activePlayerChar) {
				counter++;
				if (counter == winCondition) {
					return true;
				}
			}
			else {
				counter = 0;
			}
		}
	}
	for (int i = 0; i < columns; i++) {
		int counter = 0;
		for (int j = 0; j < rows; j++) {
			if (spaces[(j * columns) + i] == activePlayerChar) {
				counter++;
				if (counter == winCondition) {
					return true;
				}
			}
			else {
				counter = 0;
			}
		}
	}
	//checks upper left diagonally
	//does not work for 1 down on a 3x4
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			if (spaces[(j * columns) + i] == activePlayerChar) {
				if (checkInverseDiagonal(j, i) == true) {
					return true;
				}
			}
		}
	}



	if (activePlayerChar == playerOne) {
		activePlayerChar = playerTwo;
	}
	else if (activePlayerChar == playerTwo) {
		activePlayerChar = playerOne;
	}
	else {
		throw unexpected;
	}


	return false;
}

bool Board::checkInverseDiagonal(int j, int i) {
	//called if a place has an active player char

	//check up and right
	int inverseDiagonal = 0;

	for (double n = 0; n < winCondition; n++) {
		int row = j + n;
		int column = i - n;
		if (row > rows - 1 || column > columns - 1 || row < 0 || column < 0) {
			break;
		}
		if (spaces[(row * columns) + column] == activePlayerChar) {
			inverseDiagonal++;
			if (inverseDiagonal == winCondition) {
				return true;
			}
		}
	}
	//check down and left
	for (double n = 1; n < winCondition; n++) {
		int row = j - n;
		int column = i + n;

		if (row > rows - 1|| column > columns - 1 || row < 0 || column < 0) {
			break;
		}
		if (spaces[(row * columns) + column] == activePlayerChar) {
			inverseDiagonal++;
			if (inverseDiagonal == winCondition) {
				return true;
			}
		}
	}


	int diagonal = 0;
	for (double n = 0; n < winCondition; n++) {
		int row = j - n;
		int column = i - n;
		if (row > rows - 1 || column > columns - 1 || row < 0 || column < 0) {
			break;
		}
		if (spaces[(row * columns) + column] == activePlayerChar) {
			diagonal++;
			if (diagonal == winCondition) {
				return true;
			}
		}
	}
	//check down and right
	for (double n = 1; n < winCondition; n++) {
		int row = j + n;
		int column = i + n;

		if (row > rows - 1 || column > columns - 1 || row < 0 || column < 0) {
			break;
		}
		if (spaces[(row * columns) + column] == activePlayerChar) {
			diagonal++;
			if (diagonal == winCondition) {
				return true;
			}
		}
	}

	return false;

}

/*
bool Board::checkDiagonal(int j, int i) {
	int diagonal = 0;

	for (double n = 0; n < (winCondition / 2.0); n++) {
		int row = j + n;
		int column = i - n;
		if (row > rows - 1 || column > columns - 1 || row < 0 || column < 0) {
			break;
		}
		if (spaces[(row * columns) + column] == activePlayerChar) {
			diagonal++;
			if (diagonal == winCondition) {
				return true;
			}
		}
	}
	//check down and left
	for (double n = 1; n < (winCondition / 2.0); n++) {
		int row = j - n;
		int column = i + n;

		if (row > rows - 1 || column > columns - 1 || row < 0 || column < 0) {
			break;
		}
		if (spaces[(row * columns) + column] == activePlayerChar) {
			diagonal++;
			if (diagonal == winCondition) {
				return true;
			}
		}
	}

	return false;

}

*/

bool Board::checkTie()
{
	for (int i = 0; i < rows * columns; i++) 
	{
		if (spaces[i] == ' ')
		{
			return false;
		}
	}
	return true;
}

