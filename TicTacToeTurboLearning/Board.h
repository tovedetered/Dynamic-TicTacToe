#pragma once
class Board
{
public:
	Board(unsigned int rows, unsigned int columns, unsigned int winCond);
	virtual ~Board();

	const unsigned int rows;
	const unsigned int columns;
	const unsigned int winCondition;

	void updateBoard(unsigned int selectedRow, unsigned int selectedColumn);
	bool checkWinner();
	bool checkTie();

	virtual void drawBoard() = 0;


protected:

	char* const spaces;

	 //will handle drawing to user
	//virtual void getInput(); //will handle obtaining input
	//virtual void displayOutput(); //will handle displaying output like "please enter column"

private:

	void initBoard();


	

	char activePlayerChar;
	const char playerOne = 'X';
	const char playerTwo = 'O';

};

