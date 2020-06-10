//#include <iostream>
//#include <stdlib.h>
//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//
//using namespace std;
//
//void resetArray(char[7][7], int);
//void Board(char[][7], int);
//void player1(char[][7], char, int);
//void player2(char[][7], char, int);
//void gamecheck(char[][7], int, bool&);
//
//int fd2;
//char *myfifo = "tic";
//char arr1[20], arr2[20];
//
//int main()
//{
//
//
//	mkfifo(myfifo, 0666);
//
//	char choice;
//	bool turn = 1, back = 1;
//	char board[7][7];
//	resetArray(board, 7);
//	while (back == 1)
//	{
//		printf("\n\t   T i c - T a c - T o e \n\n");;
//		Board(board, 7);
//		printf("[X] For First Player \n");
//		printf("[O] For Second Player \n\n");
//		if (turn == 1)
//		{
//
//			printf("\tTurn of first Player\n");
//			printf("Wait for First Player choice [X]:");
//			fd2 = open(myfifo, O_RDONLY);
//			read(fd2, arr1, 20);
//			close(fd2);
//			choice = arr1[0];
//			player1(board, choice, 7);
//			turn = 0;
//		}
//		else
//		{
//			printf("\tTurn of Second Player\n");
//			printf("Enter Your choice [O]:");
//			cin >> choice;
//			arr2[0] = choice;
//			fd2 = open(myfifo, O_WRONLY);
//			write(fd2, arr2, 20);
//			close(fd2);
//			player2(board, choice, 7);
//			turn = 1;
//		}
//
//		system("clear");
//		gamecheck(board, 7, back);
//		system("clear");
//		if (back == 0)
//		{
//			break;
//		}
//	}
//	printf("\n");
//
//	system("pause");
//}
////////
//void Board(char board[][7], int s)
//{
//	for (int i = 0; i<s; i++)
//	{
//
//		printf("\t\t");;
//		if (i == 2 || i == 4)
//		{
//			printf("___|___|___\n\t\t");
//		}
//		printf(" ");
//		for (int j = 0; j<7; j++)
//		{
//			if (j == 2 || j == 4)
//			{
//				printf("| ");
//			}
//			printf("%c", board[i][j]);
//		}
//		printf("\n");
//	}
//
//}
////////////////
//void resetArray(char board[][7], int s)
//{
//	for (int i = 0; i<7; i++)
//	{
//		for (int j = 0; j<7; j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//	board[1][0] = '1';
//	board[1][2] = '2';
//	board[1][4] = '3';
//	board[3][0] = '4';
//	board[3][2] = '5';
//	board[3][4] = '6';
//	board[5][0] = '7';
//	board[5][2] = '8';
//	board[5][4] = '9';
//}
/////////////////
//void player1(char board[][7], char find, int s)
//{
//	bool signal = 1;
//	for (int i = 0; i < s; i++)
//	{
//		for (int j = 0; i < 7; j++)
//		{
//			if (board[i][j] == find)
//			{
//				board[i][j] = 'X';
//				signal = 0;
//				break;
//			}
//		}
//		if (signal == 0)
//		{
//			break;
//		}
//	}
//}
/////////////
//void player2(char board[][7], char find, int s)
//{
//	bool signal = 1;
//	for (int i = 0; i < s; i++)
//	{
//		for (int j = 0; i < 7; j++)
//		{
//			if (board[i][j] == find)
//			{
//				board[i][j] = 'O';
//				signal = 0;
//				break;
//			}
//		}
//		if (signal == 0)
//		{
//			break;
//		}
//	}
//}
////////////////
//void gamecheck(char board[][7], int s, bool& back)
//{
//	char game;
//
//	if (board[1][0] == 'X'&&board[1][2] == 'X'&&board[1][4] == 'X' ||
//		board[3][0] == 'X'&&board[3][2] == 'X'&&board[3][4] == 'X' ||
//		board[5][0] == 'X'&&board[5][2] == 'X'&&board[5][4] == 'X' ||
//		board[1][0] == 'X'&&board[3][2] == 'X'&&board[5][4] == 'X' ||
//		board[1][4] == 'X'&&board[3][2] == 'X'&&board[5][0] == 'X' ||
//		board[1][0] == 'X'&&board[3][0] == 'X'&&board[5][0] == 'X' ||
//		board[1][2] == 'X'&&board[3][2] == 'X'&&board[5][2] == 'X' ||
//		board[1][4] == 'X'&&board[3][4] == 'X'&&board[5][4] == 'X')
//	{
//		Board(board, 7);
//		printf("\t  :Player 1 win:\n");
//		printf("Did Player1 Wants to play Again! Wait.");
//		fd2 = open(myfifo, O_RDONLY);
//		read(fd2, arr1, 20);
//		game = arr1[0];
//		close(fd2);
//		if (game == 'Y' || game == 'y')
//		{
//			cout << "\n Player1 Wants to play Again with you.\n";
//			sleep(5);
//			resetArray(board, 7);
//			back = 1;
//		}
//		else
//		{
//			back = 0;
//		}
//
//	}
//
//	if (board[1][0] == 'O'&&board[1][2] == 'O'&&board[1][4] == 'O' ||
//		board[3][0] == 'O'&&board[3][2] == 'O'&&board[3][4] == 'O' ||
//		board[5][0] == 'O'&&board[5][2] == 'O'&&board[5][4] == 'O' ||
//		board[1][0] == 'O'&&board[3][2] == 'O'&&board[5][4] == 'O' ||
//		board[1][4] == 'O'&&board[3][2] == 'O'&&board[5][0] == 'O' ||
//		board[1][0] == 'O'&&board[3][0] == 'O'&&board[5][0] == 'O' ||
//		board[1][2] == 'O'&&board[3][2] == 'O'&&board[5][2] == 'O' ||
//		board[1][4] == 'O'&&board[3][4] == 'O'&&board[5][4] == 'O')
//	{
//		Board(board, 7);
//		printf("\t  :Player 2 win: \n");
//		printf("Do you Want to play Again ! (Y or N): ");
//		cin >> game;
//		arr2[0] = game;
//		fd2 = open(myfifo, O_WRONLY);
//		write(fd2, arr2, 20);
//		close(fd2);
//		if (game == 'Y' || game == 'y')
//		{
//			resetArray(board, 7);
//			back = 1;
//		}
//		else
//		{
//			back = 0;
//		}
//
//	}
//
//	if (board[1][0] != '1' && board[1][2] != '2' &&
//		board[1][4] != '3' && board[3][0] != '4' &&
//		board[3][2] != '5' && board[3][4] != '6' &&
//		board[5][0] != '7' && board[5][2] != '8' &&
//		board[5][4] != '9')
//	{
//		char game2;
//		Board(board, 7);
//		printf("\t  Match Draw: \n");
//		fd2 = open(myfifo, O_RDONLY);
//		read(fd2, arr1, 20);
//		game2 = arr1[0];
//		close(fd2);
//
//		printf("Do you Want to play Again ! (Y or N):");
//		cin >> game;
//		fd2 = open(myfifo, O_WRONLY);
//		arr2[0] = game;
//		write(fd2, arr2, 20);
//		close(fd2);
//
//		if ((game == 'Y' || game == 'y') && (game2 == 'Y' || game2 == 'y'))
//		{
//			resetArray(board, 7);
//			back = 1;
//		}
//		else
//		{
//			back = 0;
//		}
//	}
//}
