#pragma once
class Board
{
public:
	Board(unsigned int rows, unsigned int columns, unsigned int winCond);
	virtual ~Board();

	virtual void drawBoard() = 0;

	void updateBoard();
	bool checkWinner();
	bool checkInverseDiagonal(int j, int i);
	bool checkTie();

	void playerTurn(int turn);

protected:

	char* const spaces;

	const unsigned int rows;
	const unsigned int columns;
	const unsigned int winCondition;

	virtual void getInput() = 0;


	unsigned int selectedColumn;
	unsigned int selectedRow;

private:

	void initBoard();

	char activePlayerChar;
	const char playerOne = 'X';
	const char playerTwo = 'O';

};