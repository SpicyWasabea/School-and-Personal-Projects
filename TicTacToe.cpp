#include<iostream>

using namespace std;

void displayBoard()
{
	// making the 2d arrays
	/*
		[0,0] [0,1] [0,2]; 0, 1, 2
		[1,0] [1,1] [1,2]; 3, 4, 5
		[2,0] [2,1] [2,2]; 6, 7, 8
	*/
	

	char board[3][3] = {
						{ ' ',' ',' ' },
						{ ' ',' ',' ' },
						{ ' ',' ',' ' }
	};

	cout
		<< "     |     |     " << endl
		<< "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl
		<< "_____|_____|_____" << endl
		<< "     |     |     " << endl
		<< "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl
		<< "_____|_____|_____" << endl
		<< "     |     |     " << endl
		<< "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl
		<< "     |     |     " << endl;
}

void update(char board[][3], int yPos, int xPos, int player)
{
	

	if (player == 0)
	{
		board[yPos][xPos] = 'X';
	}
	else if (player == 1)
	{
		board[yPos][xPos] = 'O';
	}

	cout
		<< "     |     |     " << endl
		<< "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl
		<< "_____|_____|_____" << endl
		<< "     |     |     " << endl
		<< "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl
		<< "_____|_____|_____" << endl
		<< "     |     |     " << endl
		<< "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl
		<< "     |     |     " << endl;
}

bool didPlayerOneWin(char board[][3])
{
	// player 1 wins
	if (
		// horizontal wins
		(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
		(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
		(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
		// vertical wins
		(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
		(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
		(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
		// diagonal wins
		(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
		(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool didPlayerTwoWin(char board[][3])
{
	// player 2 wins
	if (
		// horizontal wins
		(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
		(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
		(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
		// vertical wins
		(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
		(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
		(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
		// diagonal wins
		(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
		(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool tieOrLose(char board[][3])
{
	if (
		board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' '&&
		board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' '&&
		board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' '
		)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

void gameLogic(char board[][3])
{
	bool notGameOver = true;
	char answer;
	int x;
	int y;
	int playerNum;
	bool checking = true;
	bool checker[3][3] = {
							{false, false, false},
							{false, false, false},
							{false, false, false}
						 };



	while (notGameOver)
	{
		checking = true;

		// user 1 input
		playerNum = 0;
		cout << "Player 1 Row: ";
		cin >> y;
		y--;
		cout << "Player 1 Column: ";
		cin >> x;
		x--;

		while (checking)
		{
			if (checker[y][x] == false)
			{
				update(board, y, x, playerNum);
				checker[y][x] = true;
				checking = false;
			}
			else
			{
				cout << "That spot is already taken!" << endl;
				cout << "Player 1 Row: ";
				cin >> y;
				y--;
				cout << "Player 1 Column: ";
				cin >> x;
				x--;
			}
		}
		// did player 1 win
		if (didPlayerOneWin(board))
		{
			cout << "Game Over! Player 1 won!" << endl;
			notGameOver = false;
			break;
		}
		// is it a tie game?
		if (tieOrLose(board))
		{
			cout << "Game Over! Neither player won!" << endl;
			notGameOver = false;
			break;
		}
		
		checking = true;

		// user 2 input
		playerNum = 1;
		cout << "Player 2 Row: ";
		cin >> y;
		y--;
		cout << "Player 2 Column: ";
		cin >> x;
		x--;

		while (checking)
		{
			if (checker[y][x] == false)
			{
				update(board, y, x, playerNum);
				checker[y][x] = true;
				checking = false;
			}
			else
			{
				cout << "That spot is already taken!" << endl;
				cout << "Player 2 Row: ";
				cin >> y;
				y--;
				cout << "Player 2 Column: ";
				cin >> x;
				x--;
			}
		}
		// did player 2 win
		if (didPlayerTwoWin(board))
		{
			cout << "Game Over! Player 2 won!" << endl;
			notGameOver = false;
			break;
		}

		// is it a tie game?
		if (tieOrLose(board))
		{
			cout << "Game Over! Neither player won!" << endl;
			notGameOver = false;
			break;
		}
	}
}

int main()
{
	char board[3][3] = {
						{ ' ',' ',' ' },
						{ ' ',' ',' ' },
						{ ' ',' ',' ' }
	};
	displayBoard();
	gameLogic(board);	
}