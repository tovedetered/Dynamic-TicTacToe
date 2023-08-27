#include "Board.h"
#include <iostream>
#include "textBoard.h"

Board::Board(unsigned int startRows, unsigned int startColumns, unsigned int winCond) : 
			 rows(startRows), columns(startColumns), winCondition(winCond), spaces(new char[rows * columns])
{
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

void Board::updateBoard(unsigned int selectedRow, unsigned int selectedColumn)
{
	activePlayerChar = playerOne;
	spaces[(selectedRow * columns) + selectedColumn] = activePlayerChar;
	drawBoard();
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

