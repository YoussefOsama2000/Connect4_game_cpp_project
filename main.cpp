#include <iostream>
using namespace std;

#define X 10
#define O 11
#define X_won 1
#define O_won 2
//#define GameEnded 0

int current_move[2];

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
        int col_reentry=0;

        if (color != X && color != O)
        {
            cout<<"Invalid piece. Try again! \n";
            return;
        }

        if(column_norm<0 || column_norm>6)
        {
          cout<<"Enter a valid column! \n";
          cin>>col_reentry;
          place(col_reentry, color);
          return;
        }

        if(board[0][column_norm]!=0)
        {
            cout<<"Column is full. Try again! \n";
            cin>>col_reentry;
          place(col_reentry, color);
        }
        else
        {
            for(i;i<5;i++)
                if (board[i+1][column_norm]!=0)    //the loop finds the outmost filled cell in the column then we place at the cell above it
                    break;

            board[i][column_norm]=color;
        }
             current_move[0]=i;
             current_move[1]=column_norm;
    }

    int getWinner()
    {
        int m=current_move[0]; //row
        int n=current_move[1]; //column
        int current_piece=board[m][n];
        int loop_row,loop_col,loop_no;
        int t;

        //checking for winner horizontally
        for(int i=0;i<4;i++)
        {
            if((board[m][i]+board[m][i+1]+board[m][i+2]+board[m][i+3])==4*current_piece)
                if(current_piece==X)
                    return X_won;
                else if(current_piece==O)
                    return O_won;                            
        }

        //checking for winner vertically
        for(int i=0;i<3;i++)
        {
            //t=(board[i][n])+(board[i+1][n])+(board[i+2][n])+(board[i+3][n]); debugging variable
            if((board[i][n]+board[i+1][n]+board[i+2][n]+board[i+3][n])==4*current_piece)
                if(current_piece==X)
                    return X_won;
                else if(current_piece==O)
                    return O_won;    
        }

        //checking for winner on the right diagonal
        if((m+n)<=6)
           { 
               loop_row=0;
               loop_col=m+n;
               loop_no=m+n+1;
           }
        else if((m+n)>6)
        {                                             //this part to get the specific diagonal in which last cell was filled
            loop_row=m+n-6;                  
            loop_col=6;
            loop_no=6-loop_row;
        }
        else
            {
                loop_row=0;
                loop_col=6;
                loop_no=6;
            }

        for(int i=0;i<loop_no-3;i++)
        {
            if(loop_no<=2)
            break;
           // t=board[loop_row+i][loop_col-i]+board[loop_row+i+1][loop_col-i-1]+board[loop_row+i+2][loop_col-i-2]+board[loop_row+i+3][loop_col-i-3]; debugging variable
            if((board[loop_row+i][loop_col-i]+board[loop_row+i+1][loop_col-i-1]+board[loop_row+i+2][loop_col-i-2]+board[loop_row+i+3][loop_col-i-3])==4*current_piece)
                if(current_piece==X)
                    return X_won;
                else if(current_piece==O)
                    return O_won;    
        }      

        //checking for winner on the left diagonal
        if(m-n<0)
        {
            loop_row=m-n;
            loop_col=0;
            loop_no=6-(m-n);
        }      
        else if(m-n>0)
        {
            loop_row=0;
            loop_col=m-n+1;
            loop_no=7-(m-n);
        }
        else
        {                                       //this part to get the specific diagonal in which last cell was filled
            loop_row=0;
            loop_col=0;
            loop_no=6;
        }

for(int i=0;i<loop_no-3;i++)
        {
            if(loop_no<=2)
            break;

            if((board[loop_row+i][loop_col+i]+board[loop_row+i+1][loop_col+i+1]+board[loop_row+i+2][loop_col+i+2]+board[loop_row+i+3][loop_col+i+3])==4*current_piece)
                if(current_piece==X)
                    return X_won;
                else if(current_piece==O)
                    return O_won;    
        }      

        return 0;
    }
    
};




int main()
{
    GameEngine gameEngine = GameEngine();
    gameEngine.printBoard();
    cout<<endl<<endl;

    int playingCol;
    int filled_cells=0;
    int winner=0;
   
    while(1)
    {
        cout<<"Player 1 turn: \n"<<"Please enter a column \n";
        cin>>playingCol;
        gameEngine.place(playingCol,X);
        filled_cells++;
        if(gameEngine.getWinner()!=0)
        {
            winner=gameEngine.getWinner();
            break;
        }
        cout<<endl<<endl;
        gameEngine.printBoard();
        cout<<endl<<endl;

        cout<<"Player 2 turn: \n"<<"Please enter a column \n";
        cin>>playingCol;
        gameEngine.place(playingCol,O);
        filled_cells++;
        if(gameEngine.getWinner()!=0)
        {
            winner=gameEngine.getWinner();
            break;
        }
        cout<<endl<<endl;
        gameEngine.printBoard();
        cout<<endl<<endl;

        if(filled_cells==42)
            break;
    }

     gameEngine.printBoard();
    cout<<endl<<endl;

    if (winner==X_won)
        cout<<"!!! Player 1 won !!!! \n";
    else if(winner==O_won)
        cout<<"!!! Player 2 won !!!! \n";
        else
            cout<<"!!! DRAW !!! \n";
    
}
