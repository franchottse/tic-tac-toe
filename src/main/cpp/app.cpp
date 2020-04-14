#include <iostream>
#include <vector>
#include <ctype.h>
#include <string>

using namespace std;

int p1 = 0, p2 = 0; // Win rounds for player 1 and 2, respectively
vector<char> board(9, ' ');

// Tic Tac Toe board
void draw()
{
	cout << "     |     |      \n";

	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";

	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";

	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
	cout << "     |     |      \n";

	cout << "\n";
}

// Fill the grid with 'X' or 'O'
void take_turn(char c, int p)
{
	if (board[p - 1] == ' ')
	{
		board[p - 1] = c;
	}
	else
	{
		cout << "Error, the grid is already filled. Please try again." << endl;
	}
}

// Introduction, game rules
void introduction()
{
	cout << "Tic-Tac-Toe is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3x3 grid." << endl;
	cout << "The player who succeeds in placing three of their marks in a horizontal, vertical or diagonal row wins the game." << endl;
	cout << "Also, each player will take turns round by round by entering the n-th grid of the board, and the game is of best of 3." << endl;
	cout << "When a player inputs a number, please input the number between 1 and 9" << endl;
	cout << "So, enjoy yourselves!!" << endl;
}

// Check if the marks are in a horizontal, vertical or diagonal row
bool is_winner(char c)
{
	if (c == 'X')
	{
		if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
			(board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
			(board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
			(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
			(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
			(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
			(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
			(board[2] == 'X' && board[4] == 'X' && board[6] == 'X'))
		{
			return true;
		}
	}
	else
	{
		if ((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') ||
			(board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
			(board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
			(board[0] == 'O' && board[3] == 'O' && board[6] == 'O') ||
			(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
			(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
			(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
			(board[2] == 'O' && board[4] == 'O' && board[6] == 'O'))
		{
			return true;
		}
	}
	return false;
}

// Check if all the grids are filled
bool filled_up()
{
	for (int i = 0; i < board.size(); ++i)
	{
		if (board[i] == ' ')
			return false;
	}
	return true;
}

// Check if the specific grid is filled
bool is_filled(int p)
{
	if (board[p - 1] != ' ')
		return true;
	return false;
}

// Clean all the grids
void reset()
{
	for (int i = 0; i < board.size(); ++i)
	{
		board[i] = ' ';
	}
}


// Check if the input from the player is out of range
bool check_number(int n)
{
	if (n < 1 || n > 9)
		return true;
	return false;
}

// Check if the input from the player is digit only
bool is_digit(const string &str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}

int main()
{

	string p1_step, p2_step; // Player inputs
	char c1 = 'X', c2 = 'O'; // Marks
	introduction();
	draw();
	while (true)
	{
		if (p1 >= 2)
		{
			cout << "Player 1 wins!! (player1 wins: " << p1 << ", player2 wins: " << p2 << endl;
			break;
		}
		if (p2 >= 2)
		{
			cout << "Player 2 wins!! (player1 wins: " << p1 << ", player2 wins: " << p2 << endl;
			break;
		}
		cout << "Player 1: ";
		cin >> p1_step;
		while (true)
		{
			if (!is_digit(p1_step))
			{
				cout << "This is not a number, please try again: ";
				cin >> p1_step;
				continue;
			}
			if (is_filled(stoi(p1_step)) || check_number(stoi(p1_step)))
			{
				cout << "Invalid input or the grid is filled, please try again: ";
				cin >> p1_step;
				continue;
			}
			take_turn(c1, stoi(p1_step));
			break;
		}
		draw();
		// Since the last person who enters the number is always player 1, the board should be checked after player 1 fills a grid
		if (filled_up())
		{
			cout << "All the grids are filled, this round ended in a draw." << endl;
			reset();
			draw();
			continue;
		}
		if (is_winner(c1))
		{
			cout << "Player 1 wins this round!!" << endl;
			p1++;
			reset();
			draw();
			continue;
		}
		cout << "Player 2: ";
		cin >> p2_step;
		while (true)
		{
			if (!is_digit(p2_step))
			{
				cout << "This is not a number, please try again: ";
				cin >> p2_step;
				continue;
			}
			if (is_filled(stoi(p2_step)) || check_number(stoi(p2_step)))
			{
				cout << "Invalid input or the grid is filled, please try again: ";
				cin >> p2_step;
				continue;
			}
			take_turn(c2, stoi(p2_step));
			break;
		}
		draw();
		if (is_winner(c1))
		{
			cout << "Player 1 wins this round!!" << endl;
			p1++;
			reset();
			draw();
			continue;
		}
		if (is_winner(c2))
		{
			cout << "Player 2 wins this round!!" << endl;
			p2++;
			reset();
			draw();
			continue;
		}
	}
	return 0;
}
