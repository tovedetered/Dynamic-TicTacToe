#pragma once
#include "Board.h"

class TextBoard : public Board
{
public:
	TextBoard(unsigned int startRows, unsigned int startColumns, unsigned int winCond);

	void drawBoard();
	void getInput();
};