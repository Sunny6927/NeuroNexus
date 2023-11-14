#include <iostream>
#include <stdlib.h>
using namespace std;
void PRINT_BOARD();
void PLAYER_INPUT();
void MACHINE_INPUT();
void REFRESH();
void RESET();
int WINNER();
int board[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int player = 1;
int main() {
	cout << "Tic Tac Toe\n1.Type in the corresponding number given in the key map. \n2.If you lose, you will be first in the second round, otherwise, you will be second.\n";
	cout << "\nPress any key to play again...\n";
	char c;
	cin >> c;
start:
	REFRESH();
	PRINT_BOARD();
	PLAYER_INPUT();
	REFRESH();
	PRINT_BOARD();
	//**********************************************
	if (WINNER() == 10) {
		cout << endl;
		cout << "***********************************\n";
		cout << "* Game over! It is a DRAW!         *\n";
		cout << "***********************************\n";
		cout << "\nPress any key to play again...\n";
		char c;
		cin >> c;
		player = 1;
		RESET();
		goto start;
	}
	if (WINNER() == player) {
		cout << endl;
		cout << "***********************************\n";
		cout << "* Game over! The winner is YOU!   *\n";
		cout << "***********************************\n";
		cout << "\nPress any key to play again...\n";
		char c;
		cin >> c;
		player = 2;
		RESET();
		goto secround;
	}
	else if ((WINNER() != 0) && (WINNER() != player)) {
		cout << endl;
		cout << "***********************************\n";
		cout << "* Game over! The winner is MACHINE!    *\n";
		cout << "***********************************\n";
		cout << "\nPress any key to play again...\n";
		char c;
		cin >> c;
		player = 1;
		RESET();
		goto start;
	}
	//**********************************************
	REFRESH();
	PRINT_BOARD();
secround:
	REFRESH();
	PRINT_BOARD();
	MACHINE_INPUT();
	REFRESH();
	//PRINT_BOARD();
	//**********************************************
	if (WINNER() == 10) {
		cout << endl;
		cout << "***********************************\n";
		cout << "* Game over! It is a tie!         *\n";
		cout << "***********************************\n";
		cout << "\nPress any key to play again...\n";
		char c;
		cin >> c;
		player = 1;
		RESET();
		goto start;
	}
	if (WINNER() == player) {
		cout << endl;
		cout << "***********************************\n";
		cout << "* Game over! The winner is YOU!   *\n";
		cout << "***********************************\n";
		cout << "\nPress any key to play again...\n";
		char c;
		cin >> c;
		player = 2;
		RESET();
		goto secround;
	}
	else if ((WINNER() != 0) && (WINNER() != player)) {
		cout << endl;
		cout << "***********************************\n";
		cout << "* Game over! The winner is ME!    *\n";
		cout << "***********************************\n";
		cout << "\nPress any key to play again...\n";
		char c;
		cin >> c;
		player = 1;
		RESET();
		goto start;
	}
	//**********************************************
	REFRESH();
	PRINT_BOARD();
	goto start;
	return 0;
}

void RESET() {
	for (int i = 0; i < 9; i++) {
		board[i] = 0;
	}
}
void REFRESH() {
	for (int i = 0; i < 100; i++) {
		cout << "\n";
	}
}



int WINNER() {
	if ((board[0] != 0) && (board[1] != 0) && (board[2] != 0) && (board[3] != 0) && (board[4] != 0) && (board[5] != 0) && (board[6] != 0) && (board[7] != 0) && (board[8] != 0)) {
		return 10;
	}
	if ((board[0] == board[1]) && (board[1] == board[2]) && (board[0] != 0)) {
		return board[0];
	}
	if ((board[3] == board[4]) && (board[4] == board[5]) && (board[3] != 0)) {
		return board[3];
	}
	if ((board[6] == board[7]) && (board[7] == board[8]) && (board[6] != 0)) {
		return board[6];
	}
	if ((board[0] == board[3]) && (board[3] == board[6]) && (board[0] != 0)) {
		return board[0];
	}
	if ((board[1] == board[4]) && (board[4] == board[7]) && (board[1] != 0)) {
		return board[1];
	}
	if ((board[2] == board[5]) && (board[5] == board[8]) && (board[2] != 0)) {
		return board[2];
	}
	if ((board[0] == board[4]) && (board[4] == board[8]) && (board[0] != 0)) {
		return board[0];
	}
	if ((board[2] == board[4]) && (board[4] == board[6]) && (board[2] != 0)) {
		return board[2];
	}
	return 0;
}

void MACHINE_INPUT();() {
	int input = 9;
	cout << "My turn. Thinking...\n";
	if ((board[0] == board[1]) && (board[0] == player) && (board[2] == 0)) {
		input = 2;
	}
	if ((board[1] == board[2]) && (board[1] == player) && (board[0] == 0)) {
		input = 0;
	}
	if ((board[0] == board[2]) && (board[0] == player) && (board[1] == 0)) {
		input = 1;
	}
	if ((board[3] == board[4]) && (board[3] == player) && (board[5] == 0)) {
		input = 5;
	}
	if ((board[4] == board[5]) && (board[4] == player) && (board[3] == 0)) {
		input = 3;
	}
	if ((board[3] == board[5]) && (board[3] == player) && (board[4] == 0)) {
		input = 4;
	}
	if ((board[6] == board[7]) && (board[6] == player) && (board[8] == 0)) {
		input = 8;
	}
	if ((board[7] == board[8]) && (board[7] == player) && (board[6] == 0)) {
		input = 6;
	}
	if ((board[6] == board[8]) && (board[6] == player) && (board[7] == 0)) {
		input = 7;
	}
	if ((board[0] == board[3]) && (board[0] == player) && (board[6] == 0)) {
		input = 6;
	}
	if ((board[3] == board[6]) && (board[3] == player) && (board[0] == 0)) {
		input = 0;
	}
	if ((board[0] == board[6]) && (board[0] == player) && (board[3] == 0)) {
		input = 3;
	}
	if ((board[1] == board[4]) && (board[1] == player) && (board[7] == 0)) {
		input = 7;
	}
	if ((board[4] == board[7]) && (board[4] == player) && (board[1] == 0)) {
		input = 1;
	}
	if ((board[1] == board[7]) && (board[1] == player) && (board[4] == 0)) {
		input = 4;
	}
	if ((board[2] == board[5]) && (board[2] == player) && (board[8] == 0)) {
		input = 8;
	}
	if ((board[5] == board[8]) && (board[5] == player) && (board[2] == 0)) {
		input = 2;
	}
	if ((board[2] == board[8]) && (board[2] == player) && (board[5] == 0)) {
		input = 5;
	}
	if ((board[0] == board[4]) && (board[0] == player) && (board[8] == 0)) {
		input = 8;
	}
	if ((board[4] == board[8]) && (board[4] == player) && (board[0] == 0)) {
		input = 0;
	}
	if ((board[0] == board[8]) && (board[0] == player) && (board[4] == 0)) {
		input = 4;
	}
	if ((board[2] == board[4]) && (board[2] == player) && (board[6] == 0)) {
		input = 6;
	}
	if ((board[4] == board[6]) && (board[4] == player) && (board[2] == 0)) {
		input = 2;
	}
	if ((board[2] == board[6]) && (board[2] == player) && (board[4] == 0)) {
		input = 4;
	}
	if (input == 9) {
		cout << "No solution, randomly filling in...\n";
		int i;
		while (input != 9) {
			i = rand() % 9;
			if (board[i] == 0) {
				input = i;
			}
		}
	}
	if (player == 1) {
		board[input] = 2;
	}
	else {
		board[input] = 1;
	}
	cout << "Placed on address " << input << "\n";
	PRINT_BOARD();
}

void PLAYER_INPUT() {
	int input;
ask:
	input = 0;
	cout << "Your turn. Enter a number.\n";
	cin >> input;
	if (input > 9) {
		cout << "The number you entered is too big.\n";
		goto ask;
	}
	else if (input < 1) {
		cout << "The number you entered is too small.\n";
		goto ask;
	}
	else if (board[input - 1] != 0) {
		cout << "The number you entered has already filled in.\n";
		goto ask;
	}
	else {
		board[input - 1] = player;
	}
}




void PRINT_BOARD() {
	char D_BOARD[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	for (int i = 0; i < 9; i++) {
		switch (board[i]) {
		case 0:
			D_BOARD[i] = ' ';
			break;
		case 1:
			D_BOARD[i] = 'O';
			break;
		case 2:
			D_BOARD[i] = 'X';
			break;
		};
	}
	cout << "Game Board          Board GUIDE\n";
	cout << "*************       *************\n";
	cout << "* " << D_BOARD[0] << " * " << D_BOARD[1] << " * " << D_BOARD[2] << " *       * 1 * 2 * 3 *\n";
	cout << "*************       *************\n";
	cout << "* " << D_BOARD[3] << " * " << D_BOARD[4] << " * " << D_BOARD[5] << " *       * 4 * 5 * 6 *\n";
	cout << "*************       *************\n";
	cout << "* " << D_BOARD[6] << " * " << D_BOARD[7] << " * " << D_BOARD[8] << " *       * 7 * 8 * 9 *\n";
	cout << "*************       *************\n";
}