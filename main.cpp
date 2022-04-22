#include <iostream>
using namespace std;
class GameEngine
{
    char board[6][7];
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
                cout <<board[i][j] << "   ";
            }
            cout << "| " << endl;
        }
        cout<<"   ____________________________"<<endl;
    }
void enterPlayer1turn(int column){

    }

//    GameEngine(){
//        for(int i=0;i<7;i++) {
//            for (int j = 0; j < 6; i++) { board[i][j] = '-'; }
//        }
//    };
};



class test
{

};



int main()
{
    GameEngine gameEngine = GameEngine();
    gameEngine.printBoard();
}
