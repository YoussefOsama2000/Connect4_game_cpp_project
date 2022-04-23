
#include <iostream>
using namespace std;

#define blue 10
#define red 11

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
                if(board[i][j]==blue)
                    cout <<"B   ";
                else if (board[i][j]==red)
                    cout <<"R   ";
                else
                    cout <<"x   ";

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

        if (color != blue && color != red)
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
    gameEngine.place(1,red);
    cout<<endl<<endl<<endl;
    gameEngine.printBoard();
    gameEngine.place(3,blue);
    gameEngine.place(1,blue);
    gameEngine.place(1,blue);
    gameEngine.place(1,blue);
    gameEngine.place(1,blue);
    gameEngine.place(1,red);
    gameEngine.printBoard();
    gameEngine.place(1,red);
    gameEngine.printBoard();
}
