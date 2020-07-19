/*
Design and develop the Tic-Tac-Toe game using C++
Tic Tac Toe : 2 player and 1 player ( using Minimax )

Authors : Anish Dhage : RollNo - 21105
          Apoorv Dixit : RollNo - 21106
          Ashwin Sapre : RollNo - 21107
          Dhruv Inamdar : RollNo - 21117

Batch : E1
*/


#include <iostream>
#include<math.h>
using namespace std;

//Structure to store the row and column of a move.
struct Move
{
    int row, col;
};

char player = 'o', opponent = 'x';

//Board class to make a board, set value of X or O and to display the board.
class Board{

	public:
	  char board[3][3] = {
		{'_','_','_'},
		{'_','_','_'},
		{'_','_','_'}};

	Board setX(int row, int col){
		board[row-1][col-1] = 'x';
	}

	Board setO(int row, int col){
		board[row-1][col-1] = 'o';
	}

	void displayBoard(){
		cout<<"      |     |	\n   "<<board[0][0] <<"  |  "<<board[0][1] <<"  |	"<<board[0][2] <<"\n _____|_____|______      \n      |     |	\n   "<<board[1][0] <<"  |  "<<board[1][1] <<"  |	"<<board[1][2] <<"\n _____|_____|______ \n      |     |	\n   "<<board[2][0] <<"  |  "<<board[2][1] <<"  |	"<<board[2][2] <<"\n      |     |"<<endl;
	}

};

//Function to evaluate winning conditions.
//Returns +10 for win and -10 for loss
int evaluate(char board[3][3])
	{

	    for (int row = 0; row<3; row++)
	    {
	        if (board[row][0]==board[row][1] &&
	            board[row][1]==board[row][2])
	        {
	            if (board[row][0]==player)
	                return +10;
	            else if (board[row][0]==opponent)
	                return -10;
	        }
	    }

	    for (int col = 0; col<3; col++)
	    {
	        if (board[0][col]==board[1][col] &&
	            board[1][col]==board[2][col])
	        {
	            if (board[0][col]==player)
	                return +10;

	            else if (board[0][col]==opponent)
	                return -10;
	        }
	    }


	    if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
	    {
	        if (board[0][0]==player)
	            return +10;
	        else if (board[0][0]==opponent)
	            return -10;
	    }

	    if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
	    {
	        if (board[0][2]==player)
	            return +10;
	        else if (board[0][2]==opponent)
	            return -10;
	    }

	    return 0;
	}

//Minimax to calculate best score for a given move.
int minimax(char boardm[3][3], int depth, bool isMax)
{
    int score = evaluate(boardm);

//cout<<"      |     |	\n   "<<boardm[0][0] <<"  |  "<<boardm[0][1] <<"  |	"<<boardm[0][2] <<"\n _____|_____|______      \n      |     |	\n   "<<boardm[1][0] <<"  |  "<<boardm[1][1] <<"  |	"<<boardm[1][2] <<"\n _____|_____|______ \n      |     |	\n   "<<boardm[2][0] <<"  |  "<<boardm[2][1] <<"  |	"<<boardm[2][2] <<"\n      |     |"<<endl;

    if (score == 10)
        return score - depth;

    if (score == -10)
        return -score + depth;

    if (isMax)
    {
        int best = -1000;

        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (boardm[i][j]=='_')
                {
                    boardm[i][j] = player;

                    best = max( best, minimax(boardm, depth+1, !isMax) );

                    boardm[i][j] = '_';
                }
            }
        }
        return best;
    }

    else
    {
        int best = 1000;

        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (boardm[i][j]=='_')
                {
                    boardm[i][j] = opponent;

                    best = min(best, minimax(boardm, depth+1, !isMax));

                    boardm[i][j] = '_';
                }
            }
        }
        return best;
    }
}

//Function to find best possible move for the given board.
Move findBestMove(Board board2)
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board2.board[i][j]=='_')
            {
                board2.board[i][j] = player;

                int moveVal = minimax(board2.board, 0, true);
               // cout<<"MoveVal "<<moveVal<<endl;
                board2.board[i][j] = '_';

                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
               // cout<<"BestVal "<<bestVal<<endl;
            }
        }
    }

    return bestMove;
}





int main(){
	int opt;
	cout<<"WELCOME TO TICTACTOE! SELECT YOUR GAME MODE::\n  1. SINGLE PLAYER\n  2. PLAY WITH A FRIEND\n";
	cin>>opt;

	Board board1;

	if(opt == 1){

		int opt2;
		cout<<"WHO PLAYS FIRST, (0)YOU OR THE (1)COMPUTER?\n";
		cin>>opt2;
		int x;
		for(x = 0; x<9;x++){

			if((x+opt2)%2 == 0){
				int i;

					int row;
					int col;

						INPUTX:cout<<"Enter row and col for X move:  ";
						cin>>row>>col;
						//Exception Handling to avoid Errors
						try{
							if(isalpha(row) != 0 || isalpha(col) != 0){
								throw 'a';
								break;
							}
							if(row > 3 || row < 1){
								throw 'a';
							}
							if(col > 3 || col < 1){
								throw 'a';
							}
							if(board1.board[row-1][col-1] != '_'){
								throw 2;
							}
						}
						catch(int x){
							cout<<"\n---THIS POSITION IS ALREADY TAKEN. TRY ANOTHER POSITION.\n";
							goto INPUTX;
						}
						catch(char a){
							cout<<"\n---INVALID INPUT. PLEASE TRY AGAIN. \n";
							a = '\0';
							goto INPUTX;
						}

						board1.setX(row, col);
						board1.displayBoard();
						cout<<endl;


			}
			else if((x+opt2)%2 == 1){

                //cout<<"in O\n";
				Move move1 = findBestMove(board1);
				//cout<<move1.row+1<<move1.col+1<<endl;
				board1.setO(move1.row+1, move1.col+1);
				cout<<"Computer plays : \n";
				board1.displayBoard();

			}

			//Evaluating winning conditions for board
			int win = evaluate(board1.board);
					if(win == -10){
						cout<<"\n\n---GAME OVER! X HAS WON---\n\n";
						break;
					}
					else if(win == 10){
						cout<<"\n\n---GAME OVER! O HAS WON---\n\n";
						break;
					}
				}
					cout<<"\n\nFINAL BOARD \n\n";
					board1.displayBoard();

		}


	/* ========================================================================*/
	else if(opt == 2){

		Board board1;
		int flag = 0;
		for(int i = 0 ; i < 9 ; i++){
			int row;
			int col;
			if (flag == 0){
                //Exception Handling to avoid Errors
				INPUTX1:cout<<"Enter row and col for X move:  ";
				cin>>row>>col;
				try{
					if(isalpha(row) != 0 || isalpha(col) != 0){
						throw 'a';
						break;
					}
					if(row > 3 || row < 1){
						throw 'a';
					}
					if(col > 3 || col < 1){
						throw 'a';
					}
					if(board1.board[row-1][col-1] != '_'){
						throw 2;
					}
				}
				catch(int x){
					cout<<"\n---THIS POSITION IS ALREADY TAKEN. TRY ANOTHER POSITION.\n";
					goto INPUTX1;
				}
				catch(char a){
					cout<<"\n---INVALID INPUT. PLEASE TRY AGAIN. \n";
					a = '\0';
					goto INPUTX1;
				}
				board1.setX(row, col);
				board1.displayBoard();
				flag = 1;
			}
			else if (flag == 1){
			    //Exception Handling to avoid Errors
				INPUTO:cout<<"Enter row and col for O move:  ";
				cin>>row>>col;
				try{
					if(row > 3 || row < 1){
						throw 'a';
					}
					if(col > 3 || col < 1){
						throw 'a';
					}
					if(board1.board[row-1][col-1] != '_'){
						throw 2;
					}
				}
				catch(int x){
					cout<<"\n---THIS POSITION IS ALREADY TAKEN. TRY ANOTHER POSITION.\n";
					goto INPUTO;
				}
				catch(char a){
					cout<<"\n---INVALID INPUT. PLEASE TRY AGAIN. \n";
					goto INPUTO;
				}
				board1.setO(row, col);
				board1.displayBoard();
				flag = 0;
			}

			//Evaluating winning conditions for board
			int win = evaluate(board1.board);
			if(win == -10){
				cout<<"\n\n---GAME OVER! X HAS WON---\n\n";
				break;
			}
			else if(win == 10){
				cout<<"\n\n---GAME OVER! O HAS WON---\n\n";
				break;
			}
		}
		cout<<"\n\nFINAL BOARD \n\n";
		board1.displayBoard();
	}
}

/*
OUTPUT:
WELCOME TO TICTACTOE! SELECT YOUR GAME MODE::
  1. SINGLE PLAYER
  2. PLAY WITH A FRIEND
1
WHO PLAYS FIRST, (0)YOU OR THE (1)COMPUTER?
1
Computer plays :
      |     |
   o  |  _  |   _
 _____|_____|______
      |     |
   _  |  _  |   _
 _____|_____|______
      |     |
   _  |  _  |   _
      |     |
Enter row and col for X move:  1 2
      |     |
   o  |  x  |   _
 _____|_____|______
      |     |
   _  |  _  |   _
 _____|_____|______
      |     |
   _  |  _  |   _
      |     |

Computer plays :
      |     |
   o  |  x  |   _
 _____|_____|______
      |     |
   o  |  _  |   _
 _____|_____|______
      |     |
   _  |  _  |   _
      |     |
Enter row and col for X move:  3 1
      |     |
   o  |  x  |   _
 _____|_____|______
      |     |
   o  |  _  |   _
 _____|_____|______
      |     |
   x  |  _  |   _
      |     |

Computer plays :
      |     |
   o  |  x  |   _
 _____|_____|______
      |     |
   o  |  o  |   _
 _____|_____|______
      |     |
   x  |  _  |   _
      |     |
Enter row and col for X move:  2 3
      |     |
   o  |  x  |   _
 _____|_____|______
      |     |
   o  |  o  |   x
 _____|_____|______
      |     |
   x  |  _  |   _
      |     |

Computer plays :
      |     |
   o  |  x  |   _
 _____|_____|______
      |     |
   o  |  o  |   x
 _____|_____|______
      |     |
   x  |  _  |   o
      |     |


---GAME OVER! O HAS WON---



FINAL BOARD

      |     |
   o  |  x  |   _
 _____|_____|______
      |     |
   o  |  o  |   x
 _____|_____|______
      |     |
   x  |  _  |   o
      |     |

*/
