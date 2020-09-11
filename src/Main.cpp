#include <iostream>
using namespace std;

bool xTurn = true;
int board[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

bool spaceAvailable() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 0)
				return true;			//If any space hasn't been played yet...
		}
	}
	return false;
}

int checkWin() {
	//Very against these hard coded win conditions, will revisit later

	if ((board[0][0] != 0) && (board[0][0] == board[1][0]) && (board[1][0] == board[2][0]))		//Top row
		return board[0][0];
	else if ((board[0][1] != 0) && (board[0][1] == board[1][1]) && (board[1][1] == board[2][1]))	//Mid row
		return board[0][1];
	else if ((board[0][2] != 0) && (board[0][2] == board[1][2]) && (board[1][2] == board[2][2]))	//Bot row
		return board[0][2];
	else if ((board[0][0] != 0) && (board[0][0] == board[0][1]) && (board[0][1] == board[0][2]))	//Lt column
		return board[0][0];
	else if ((board[1][0] != 0) && (board[1][0] == board[1][1]) && (board[1][1] == board[1][2]))	//Mid column
		return board[1][0];
	else if ((board[2][0] != 0) && (board[2][0] == board[2][1]) && (board[2][1] == board[2][2]))	//Rt column
		return board[2][0];
	else if ((board[0][0] != 0) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))//Diagonal top-rt to bt-lt
		return board[0][0];
	else if ((board[0][2] != 0) && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))	//Diagonal bot-rt to tp-lt
		return board[0][2];
	else
		return 0;		//If any win condition is met return winner, otherwise return 0
}

void turn(int row, int column) {
	if (board[column][row] == 0) {
			if (xTurn)							//If X's turn, set space to 1
				board [column][row] = 1;
			else
				board[column][row] = 2;	//If not (aka O's turn), set space to 2
	} else
		cout << "Not a valid space" << endl;

}

void displayBoard() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << board[i][j];
		}
		cout << endl;					//Print board as 0s, 1s, and 2s
	}
}

int main() {
	string inputSpace;
	do {
		displayBoard();

		cout << "Space? \"Column,Row\" format." << endl;
		getline(cin, inputSpace);

		turn((((int)inputSpace[0]) - '0'), (((int)inputSpace[2] - '0')));	//Not a fan of this either, will revisit
		xTurn = !xTurn;
	}while (checkWin() == 0 && spaceAvailable());				//Until someone wins or all spaces have been filled, loop

	if (checkWin() == 0)
		cout << "It's a draw.";
	else if (checkWin() == 1)
		cout << "X wins!";
	else if (checkWin() == 2)
		cout << "O wins!";
	else
		cout << "Code is pretty broken if winner is equal to anything other than 0, 1, or 2.";

	return 0;

}







