#include <iostream>
using namespace std;

#define blue 10
#define red 11

#define GameEnded 20
#define NotFinishedYet 30

unsigned char GameState=NotFinishedYet;

class GameEngine {
	int board[6][7];
	// declareing the board in the heap to avoid stack overflow
	int current_move[6][7];

public:
	void printBoard() {
		cout << endl << endl << "     1   2   3   4   5   6   7" << endl;
		for (int i = 0; i < 6; i++) {
			cout << " |   ";
			for (int j = 0; j < 7; j++) {
				if (board[i][j] == blue)
					cout << "B   ";
				else if (board[i][j] == red)
					cout << "R   ";
				else
					cout << "x   ";

			}
			cout << "| " << endl;
		}
		cout << "   ____________________________" << endl << endl;
	}

	void GetWinner(void) {
		int row = 0;
		int column = 0;
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 4; column++) {

				/* Check winner vertically*/

				while(GameState!=GameEnded)
				{
				if (current_move[row][column] == current_move[row++][column]
						== current_move[row + 2][column]
						== current_move[row + 3][column]) {

					if(current_move[row][column]==red)
					{
						cout<<"RED WON !!!!!!!!!!!!!!"<<endl;
					}
					else
					{
					cout<<"BLUE WON !!!!!!!!!!!!!!!"<<endl;
					}
					GameState=GameEnded;
					break;
				}

				/* Check winner horizontally*/

				else if (current_move[row][column]
						== current_move[row][column++]
						== current_move[row][column + 2]
						== current_move[row][column + 3]) {

					if(current_move[row][column]==red)
					{
						cout<<"RED WON !!!!!!!!!!!!!!"<<endl;
					}
					else
					{
					cout<<"BLUE WON !!!!!!!!!!!!!!!"<<endl;
					}
					GameState=GameEnded;
					break;

				}

				/*	Check winner in diagonal forms (4 different form checks)	*/

				else if (current_move[row][column]
						== current_move[row++][column++]
						== current_move[row + 2][column + 2]
						== current_move[row + 3][column + 3]) {

					if(current_move[row][column]==red)
					{
						cout<<"RED WON !!!!!!!!!!!!!!"<<endl;
					}
					else
					{
					cout<<"BLUE WON !!!!!!!!!!!!!!!"<<endl;
					}

					GameState=GameEnded;
					break;
				}
				else if (current_move[row][column]
						== current_move[row--][column--]
						== current_move[row - 2][column - 2]
						== current_move[row - 2][column - 2]) {

					if(current_move[row][column]==red)
					{
						cout<<"RED WON !!!!!!!!!!!!!!"<<endl;
					}
					else
					{
					cout<<"BLUE WON !!!!!!!!!!!!!!!"<<endl;
					}

					GameState=GameEnded;
					break;
				}
				else if (current_move[row][column]
						== current_move[row++][column--]
						== current_move[row + 2][column - 2]
						== current_move[row + 3][column - 3]) {

					if(current_move[row][column]==red)
					{
						cout<<"RED WON !!!!!!!!!!!!!!"<<endl;
					}
					else
					{
					cout<<"BLUE WON !!!!!!!!!!!!!!!"<<endl;
					}
					GameState=GameEnded;
					break;

				}
				else if (current_move[row][column]
						== current_move[row--][column++]
						== current_move[row - 2][column + 2]
						== current_move[row - 3][column + 3]) {

					if(current_move[row][column]==red)
					{
						cout<<"RED WON !!!!!!!!!!!!!!"<<endl;
					}
					else
					{
					cout<<"BLUE WON !!!!!!!!!!!!!!!"<<endl;
					}

					GameState=GameEnded;
					break;
				}
				else {


				}
				}
			}
		}
	}
	void enterPlayer1turn(int column) {

	}

	GameEngine() //for some reason initializing the array normally returns garbage when printed
	{
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 7; j++)
				board[i][j] = 0;
	}

	void place(int column, int color) {
		int i = 0;
		int column_norm = column - 1; //to normalize the input column value to the actual column value in the array

		if (color != blue && color != red) {
			cout << "Invalid piece. Try again!";
			return;
		}

		if (board[0][column_norm] != 0) {
			cout << "Column is full. Try again! \n";
			return;
		} else {
			for (i = 0; i < 6; i++)
				if (board[i + 1][column_norm] != 0) //the loop finds the outmost filled cell in the column then we place at the cell above it
					break;

			board[i][column_norm] = color;
			current_move[i][column_norm] = board[i][column_norm];
		}
	}
};

int main() {
	GameEngine gameEngine = GameEngine();
	gameEngine.printBoard();
gameEngine.place(1,red);
cout<<endl<<endl<<endl;
gameEngine.printBoard();
gameEngine.place(1,red);
gameEngine.place(2,red);
gameEngine.place(3,blue);
gameEngine.place(3,red);
gameEngine.place(3,red);
gameEngine.place(3,red);
gameEngine.place(4,red);
gameEngine.place(4,blue);
gameEngine.place(4,red);
gameEngine.place(4,red);
gameEngine.printBoard();
gameEngine.place(2,red);
gameEngine.printBoard();
gameEngine.GetWinner();
}
