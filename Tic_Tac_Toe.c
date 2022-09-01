#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void displayBoard(int [3][3]);
void playWithSmartComputer();
void playWithEvilComputer();
void playWithAnotherPlayer();
int findWinner(int, int [3][3]);
int checkWinningPossibility(int, int [3][3]);
//void displayResult(char [], char [], int [3][3], char []);

int main() {
	int choice;

	while(1) {
		system("cls");
		printf("\n************ TIC-TAC-TOE ************");
		printf("\n\n1. Want to play with Smart Computer");
		printf("\n2. Want to play with Evil Computer");
		printf("\n3. Want to play with Another Player");
		printf("\n4. Exit");
		printf("\n*************************************");
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				playWithSmartComputer();
				break;
			case 2:
				playWithEvilComputer();
				break;
			case 3:
				playWithAnotherPlayer();
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid Choice!");
		}
		printf("\n\nPress any key to go to the main menu...");
		getch();
	}

	return 0;
}

void displayBoard(int board[3][3]) {
	int i, j;

	printf("\n\t+---+---+---+\n\t");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
			if (board[i][j] == 'X' || board[i][j] == 'O')
				printf("| %c ", board[i][j]);
			else
            	printf("| %d ", board[i][j]);
        }
        printf("|\n\t+---+---+---+\n\t");
    }
}
/*
void displayResult(char player1[], char player2[], int board[3][3], char winner[]) {
	system("cls");
	printf("\n************ TIC-TAC-TOE ************");
	printf("\n\nFirst Player 'X'  : %s", player1);
	printf("\nSecond Player 'O' : %s\n", player2);
	displayBoard(board);
	printf("\n*************************************");
	printf("\n\n\t%s\n", winner);
	printf("\n*************************************");
}
*/
int findWinner(int player, int board[3][3]) {
	int i;

	/*Row wise checking*/
	for(i=0; i<3; i++) {
		if (board[i][0] == player && board[i][1] == player &&  board[i][2] == player)
			return 1;
	}

	/*Column wise checking*/
	for(i=0; i<3; i++) {
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
			return 1;
	}

	/*Diagonally checking*/
	if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return 1;
	}
	if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		return 1;
	}

	return 0;
}

int checkWinningPossibility(int player, int board[3][3]) {
	int i, j, tmp;

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			if (board[i][j] != 'X' && board[i][j] != 'O') {
				tmp = board[i][j];
				board[i][j] = player;				
				if (findWinner(player, board)) {
					board[i][j] = 'O';
					return 1;
				}
				board[i][j] = tmp;
			}			
		}
	}
	return 0;
}

void playWithSmartComputer() {
	int i, cell, board[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = &board[0][0], move = 0;
	char player[30];

	printf("\nEnter player name: ");
	fflush(stdin);
	fgets(player, 30, stdin);
	 
	while(1) {
		system("cls");
		printf("\n************ TIC-TAC-TOE ************");
		printf("\n\nFirst Player 'X'  : %s", player);
		printf("\nSecond Player 'O' : Smart Computer\n");
		displayBoard(board);
		printf("\n*************************************");
		printf("\n\n%s's turn, Enter Cell number: ", player);
		scanf("%d", &cell);

		if (cell >= 1 && cell <= 9) {
			cell--;
			if (*(p+cell) != 'X' && *(p+cell) != 'O') {
				*(p+cell) = 'X';
				move++;

				if (findWinner('X', board)) {
					system("cls");
					printf("\n************ TIC-TAC-TOE ************");
					printf("\n\nFirst Player 'X'  : %s", player);
					printf("\nSecond Player 'O' : Smart Computer\n");
					displayBoard(board);
					printf("\n*************************************");
					printf("\n\n\tPlayer X Won\n");
					printf("\n*************************************");
					return;
				} 
				if (move == 9) {
					system("cls");
					printf("\n************ TIC-TAC-TOE ************");
					printf("\n\nFirst Player 'X'  : %s", player);
					printf("\nSecond Player 'O' : Smart Computer\n");
					displayBoard(board);
					printf("\n*************************************");
					printf("\n\n\tGame Draw\n");
					printf("\n*************************************");
					return;
				}

				/*Computer's Turn*/
				
				if (!checkWinningPossibility('O', board) && !checkWinningPossibility('X', board)) {
					/*for(i=0; i<9; i++) {
						if (*(p+i) != 'X' && *(p+i) != 'O') {
							*(p+i) = 'O';
							break;
						}
					}*/
					srand(time(0));
					i = rand() % 9;
					while(*(p+i) == 'X' || *(p+i) == 'O')
						i = rand() % 9;
					*(p+i) = 'O';					
				}
				move++;
				
				if (findWinner('O', board)) {
					system("cls");
					printf("\n************ TIC-TAC-TOE ************");
					printf("\n\nFirst Player 'X'  : %s", player);
					printf("\nSecond Player 'O' : Smart Computer\n");
					displayBoard(board);
					printf("\n*************************************");
					printf("\n\n\tPlayer O Won\n");
					printf("\n*************************************");
					return;
				} 
			}
			else {
				printf("\nThe cell is already occupied, Press any key to input again...");
				getch();
			}			
		} 
		else {
			printf("\nInvalid Cell Number, Press any key to input again...");
			getch();
		}
	}
}

void playWithEvilComputer() {
	int i, cell, board[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = &board[0][0], move = 0, flag;
	char player[30];

	printf("\nEnter player name: ");
	fflush(stdin);
	fgets(player, 30, stdin);
	 
	while(1) {
		system("cls");
		printf("\n************ TIC-TAC-TOE ************");
		printf("\n\nFirst Player 'X'  : %s", player);
		printf("\nSecond Player 'O' : Evil Computer\n");
		displayBoard(board);
		printf("\n*************************************");
		printf("\n\n%s's turn, Enter Cell number: ", player);
		scanf("%d", &cell);

		if (cell >= 1 && cell <= 9) {
			cell--;
			if (*(p+cell) != 'X' && *(p+cell) != 'O') {
				*(p+cell) = 'X';
				move++;

				if (findWinner('X', board)) {
					system("cls");
					printf("\n************ TIC-TAC-TOE ************");
					printf("\n\nFirst Player 'X'  : %s", player);
					printf("\nSecond Player 'O' : Evil Computer\n");
					displayBoard(board);
					printf("\n*************************************");
					printf("\n\n\tPlayer X Won\n");
					printf("\n*************************************");
					return;
				} 
				if (move == 9) {
					system("cls");
					printf("\n************ TIC-TAC-TOE ************");
					printf("\n\nFirst Player 'X'  : %s", player);
					printf("\nSecond Player 'O' : Evil Computer\n");
					displayBoard(board);
					printf("\n*************************************");
					printf("\n\n\tMatch Draw\n");
					printf("\n*************************************");
					return;
				}

				/*Computer's Turn*/
				if (checkWinningPossibility('O', board)) {
					move++;
				} 
				else {
					flag = 0;
					while(checkWinningPossibility('X', board)) {
						move++;
						flag = 1;
					}
					if (!flag) {
						srand(time(0));
						i = rand() % 9;
						while(*(p+i) == 'X' || *(p+i) == 'O')
							i = rand() % 9;
						*(p+i) = 'O';		
						move++;
					}
				}

				if (findWinner('O', board)) {
					system("cls");
					printf("\n************ TIC-TAC-TOE ************");
					printf("\n\nFirst Player 'X'  : %s", player);
					printf("\nSecond Player 'O' : Evil Computer\n");
					displayBoard(board);
					printf("\n*************************************");
					printf("\n\n\tPlayer O Won\n");
					printf("\n*************************************");
					return;
				} 				
				if (move == 9) {
					system("cls");
					printf("\n************ TIC-TAC-TOE ************");
					printf("\n\nFirst Player 'X'  : %s", player);
					printf("\nSecond Player 'O' : Evil Computer\n");
					displayBoard(board);
					printf("\n*************************************");
					printf("\n\n\tMatch Draw\n");
					printf("\n*************************************");
					return;
				}
			}
			else {
				printf("\nThe cell is already occupied, Press any key to input again...");
				getch();
			}			
		} 
		else {
			printf("\nInvalid Cell Number, Press any key to input again...");
			getch();
		}
	}
}

void playWithAnotherPlayer() {
	char player1[30], player2[30];
	int i, cell, move, turn, *p, board[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("\nEnter first player name: ");
	fflush(stdin);
	fgets(player1, 30, stdin);
	printf("\nEnter second player name: ");
	fflush(stdin);
	fgets(player2, 30, stdin);

	turn = 'X', move = 0, p = &board[0][0];

	while(1) {
		system("cls");
		printf("\n************ TIC-TAC-TOE ************");
		printf("\n\nFirst Player 'X'  : %s", player1);
		printf("\nSecond Player 'O' : %s\n", player2);
		displayBoard(board);
		printf("\n*************************************");
		printf("\n\n%s's turn, Enter Cell number: ", turn == 'X' ? player1 : player2);
		scanf("%d", &cell);

		if (cell >= 1 && cell <= 9) {
			cell--;

			if (*(p+cell) != 'X' && *(p+cell) != 'O') {				
				*(p+cell) = turn;
				move++;

				if (findWinner(turn, board)) {
					system("cls");
					printf("\n************ TIC-TAC-TOE ************");
					printf("\n\nFirst Player 'X'  : %s", player1);
					printf("\nSecond Player 'O' : %s\n", player2);
					displayBoard(board);
					printf("\n*************************************");
					printf("\n\n\tPlayer %c Won\n", turn);
					printf("\n*************************************");
					return;
				} 
				if (move == 9) {
					system("cls");
					printf("\n************ TIC-TAC-TOE ************");
					printf("\n\nFirst Player 'X'  : %s", player1);
					printf("\nSecond Player 'O' : %s\n", player2);
					displayBoard(board);
					printf("\n*************************************");
					printf("\n\n\tGame Draw\n");
					printf("\n*************************************");
					return;
				}

				turn = (turn == 'X') ? 'O' : 'X';
			}
			else {
				printf("\nThe cell is already occupied, Press any key to input again...");
				getch();
			}
		}			
		else {
			printf("\nInvalid Cell Number, Press any key to input again...");
			getch();
		}
	}
}