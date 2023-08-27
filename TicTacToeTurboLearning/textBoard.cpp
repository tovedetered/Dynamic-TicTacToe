#include "textBoard.h"
#include <iostream>

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
