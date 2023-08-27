#include "pch.h"
#include "../TicTacToeTurboLearning/textBoard.h"
#include "../TicTacToeTurboLearning/Board.h"

TEST(TestCaseName, TestName) {
	TextBoard textboard(3, 3, 3);

	textboard.updateBoard(0,0);
	textboard.updateBoard(0, 1);
	textboard.updateBoard(0, 2);
	EXPECT_EQ(true, textboard.checkWinner());

}