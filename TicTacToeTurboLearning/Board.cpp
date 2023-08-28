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
		int counter = 0;
		for (int j = 0; j < rows; j++) {
			if (spaces[(j * columns) + j] == activePlayerChar) {
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
	//IDK what this does???
	//commenting it out
	/*
	for (int i = 0; i < columns; i++) {
		int counter = 0;
		for (int j = 0; j < rows; j++) {
			if (spaces[(j * rows) + j] == activePlayerChar) {
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
	*/

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

