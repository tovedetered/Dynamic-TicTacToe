#pragma once
class Board
{
public:
	Board(unsigned int rows, unsigned int columns, unsigned int winCond);
	virtual ~Board();

	const unsigned int rows;
	const unsigned int columns;
	const unsigned int winCondition;

	void updateBoard();
	bool checkWinner();
	bool checkTie();

	void playerTurn(int turn);
	virtual void drawBoard() = 0;


protected:

	char* const spaces;


	virtual void getInput() = 0;

	unsigned int selectedColumn;
	unsigned int selectedRow;
	 //will handle obtaining input
	//virtual void displayOutput(); //will handle displaying output like "please enter column"

private:

	void initBoard();

	char activePlayerChar;
	const char playerOne = 'X';
	const char playerTwo = 'O';

};

