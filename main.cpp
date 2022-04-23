#include <iostream>
using namespace std;

#define X 10
#define O 11

class GameEngine
{
    int board[6][7];
    // declareing the board in the heap to avoid stack overflow
public:
    void printBoard()
    {
        cout<<endl<<endl<<"     1   2   3   4   5   6   7"<<endl;
        for (int i = 0; i < 6; i++)
        {
            cout << " |   ";
            for (int j = 0; j < 7; j++)
            {
                if(board[i][j] == X)
                    cout <<"X   ";
                else if (board[i][j] == O)
                    cout <<"O   ";
                else
                    cout <<"-   ";

            }
            cout << "| " << endl;
        }
        cout<<"   ____________________________"<<endl<<endl;
    }
    void enterPlayer1turn(int column){

    }


    GameEngine()      //for some reason initializing the array normally returns garbage when printed
    {
        for(int i=0;i<6;i++)
            for(int j=0;j<7;j++)
                board[i][j]=0;
    }

    void place(int column, int color)
    {
        int i=0;
        int column_norm=column-1;   //to normalize the input column value to the actual column value in the array

        if (color != X && color != O)
        {
            cout<<"Invalid piece. Try again!";
            return;
        }

        if(board[0][column_norm]!=0)
        {
            cout<<"Column is full. Try again! \n";
            return;
        }
        else
        {
            for(i;i<6;i++)
                if (board[i+1][column_norm]!=0)    //the loop finds the outmost filled cell in the column then we place at the cell above it
                    break;

            board[i][column_norm]=color;
        }
    }
};




int main()
{
    GameEngine gameEngine = GameEngine();
    gameEngine.printBoard();
    gameEngine.place(1, O);
    cout<<endl<<endl<<endl;
    gameEngine.printBoard();
    gameEngine.place(2, X);
    gameEngine.place(2, X);
    gameEngine.place(2, O);
    gameEngine.place(3, O);
    gameEngine.place(3, O);
    gameEngine.place(3, X);
    gameEngine.place(2, X);
    gameEngine.place(2, O);
    gameEngine.place(1, X);
    gameEngine.place(1, O);
    gameEngine.printBoard();
}
