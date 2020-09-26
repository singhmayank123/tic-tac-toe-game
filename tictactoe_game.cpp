#include<iostream>

#include<iomanip>

//#include

using namespace std;

enum status {

WIN, DRAW, CONTINUE

};

// creating class TicTacToe

class TicTacToe {

private: // private data members

// a 9*9 two-dimensional array of char as a private data member

char board[9][9];

int noOfMoves;

public: // public member functions

// Default constructor to initialise board with ' ' spaces

TicTacToe() {

// initializes board with ' ' spaces

for (int i = 0; i < 9; i++) {

for (int j = 0; j < 9; j++) {

  board[i][j] = ' ';
}

}

noOfMoves = 0;

};

void displayBoard() {
			
			cout << endl;
			cout<<"    BOARD1  |   BOARD2  |   BOARD3   "<<endl;
			cout<<" ___________|___________|____________"<<endl;
			     
			for (int row = 0; row < 9; row++) {
			//crearing a 9x9 board
		 		cout<<"|";
					for (int col = 0; col < 9; col++) {

						cout<< setw(3) << board[row][col] << "|";
				
		         	}
			
		    	cout << endl;
			
				if (row < 9) {
						
						if(row == 2 || row == 5){
						cout << "|___|___|___|___|___|___|___|___|___|_____" <<endl;
						}
						else
						cout << "|___|___|___|___|___|___|___|___|___|" <<endl;
						
				}
				
	   }
			
			cout << "            |           |               " <<endl;
			cout << "   BOARD7   |   BOARD8  |    BOARD9     " <<endl;
			cout<<endl;

}

bool isValidMove(int row, int col) {

//Add conditions in the "if statement" to check if row and col are in the range between 0-2 and the cell is blank.

//Note that array index starts from 0
			
			if ((row>=0 && row<=2) && (col>=0 && col<=2))
			
			return true;
			
			else
			
			return false;

}

status gameStatus(int r , int c) {

//Write your code here to check if the game has been in a win status or a draw status

//Check rows for a win
					
					for(int row = 0; row<9; row++) {
					
					if(r <3 && c < 3){
					
					// checking rows of board 1
							
							if (board[row][0] == board[row][1] &&
							
							board[row][1] == board[row][2] &&
							
							board[row][0] != ' ')
							
							{
							
							return WIN;
							
							}
					
					
					}
					
					else if(r <3 && (c >= 3 && c < 6)){
					
					// checking rows of board 2
							
							if (board[row][3] == board[row][4] &&
							
							board[row][4] == board[row][5] &&
							
							board[row][3] != ' ')
							
							{
							
							return WIN;
							
							}
							
					
					}
					
					else if(r <3 && (c >= 6 && c < 9)){
					// checking rows of board 3
					// cout<<1234;
							
							if (board[row][6] == board[row][7] &&
							
							board[row][7] == board[row][8] &&
							
							board[row][6] != ' ')
							
							{
							
							return WIN;
							
							}
							
					
					}
					
					else if( (r >=3 && r <6) && c < 3) {
					// checking rows of board 4
					
							if (board[row][0] == board[row][1] &&
							
							board[row][1] == board[row][2] &&
							
							board[row][0] != ' ')
							
							{
							
							return WIN;
							
							}
							
					
					}
					
					else if( (r >=3 && r <6) && (c >= 3 && c < 6)) {
					// checking rows of board 5
							
							if (board[row][3] == board[row][4] &&
							
							board[row][4] == board[row][5] &&
							
							board[row][3] != ' ')
							
							{
							
							return WIN;
							
							}
					
					
					}
					
					else if( (r >=3 && r <6) && (c >=6 && c<9)) {
					// checking rows of board 6
							
							if (board[row][6] == board[row][7] &&
							
							board[row][7] == board[row][8] &&
							
							board[row][6] != ' ')
							
							{
							
							return WIN;
							
							}
					
					
					}
					
					else if( (r >=6 && r < 9) && c < 3) {
					// checking rows of board 7
					
							if (board[row][0] == board[row][1] &&
							
							board[row][1] == board[row][2] &&
							
							board[row][0] != ' ')
							
							{
							
							return WIN;
							
							}
							
					
					}
					
					else if( (r >=3 && r <6) && (c >=3 && c<6)) {
					// checking rows of board 8
					
							if (board[row][3] == board[row][4] &&
							
							board[row][4] == board[row][5] &&
							
							board[row][3] != ' ')
							
							{
							
							return WIN;
							
							}
					
					
					}
					
					else if( (r >=3 && r <6) && (c >= 6 && c<9)) {
					// checking rows of board 9
								
								if (board[row][6] == board[row][7] &&
								
								board[row][7] == board[row][8] &&
								
								board[row][6] != ' ')
								
								{
								
								return WIN;
								
								}
								
					
					}
			}
					
					//check for columns
					
					for(int col = 0; col < 3; col++) {
					
					if (board[0][col] == board[1][col] &&
					
					board[1][col] == board[2][col] &&
					
					board[0][col] != ' ')
					
					{
					
					return WIN;
					
					}
					
					}
					
					//check downward diagonal
					
					if (board[0][0] == board[1][1] &&
					
					board[1][1] == board[2][2] &&
					
					board[0][0] != ' ')
					
					{
					
							return WIN;
					
					}
					
					//check upward diagonal
					
					if (board[2][0] == board[1][1] &&
					
					board[1][1] == board[0][2] &&
					
					board[2][0] != ' ')
					
					{
					
							return WIN;
					
					}
					
					//CHeck if any emtpy cell exists, If yes, return CONTINUE
					
					for(int i = 0; i<3 ; i++) {
					
							for(int j=0; j<3; j++) {
							
						   			if(board[i][j] == ' ')
							
										return CONTINUE;
							
							}

				}

return DRAW; //return DRAW

}

		bool addMove(char playerSymbol, int row,int col) {
			
				
				board[row][col] = playerSymbol;
				
				noOfMoves++;
				
				displayBoard();
				
				
				status gStatus = gameStatus(row , col);
				
				if (gStatus == WIN) {
				
						cout << "Player " << playerSymbol << " wins!" << endl;
				
						return true;
				
				} else if (gStatus == DRAW) {
				
						cout << "This game is a draw!" << endl;
				
						return true;
				
				} else if (noOfMoves >= 81) {
							
						return true;
				
				} else
				
						return false;

}

};

class Game{
		
		public:
		
		TicTacToe board;  //creating array of objects
		
		void play() { // function to play the game since these lines of code were in the main
		
				bool done = false;
				
				char player = 'X';
				
				board.displayBoard();
				
				
				while (!done) {
						
						int row, col;
						
						if (player == 'X'){
						
						getXMove(player, row, col);
						
						done = board.addMove(player, row, col);
						
						player = 'O';
				
				}
				
				else{
						
						getOMove(player, row, col);
						
						done = board.addMove(player, row, col);
						
						player = 'X';
				
			     	}
				
				}
				
		}
		
		
		
		void getXMove(char playr, int& row, int& col) {
			
				int box , boardNo;
				bool moves = false;
		
		do{
		
				cout << "Player " << playr << " Enter Board Number for your move: ";	
				
				cin>> boardNo;
				
				cout << "Player " << playr << " Enter box number in board"<<boardNo<<" for your move: ";
		
				cin >> box;
				if(boardNo == 1){
				
				if(box == 1){
				row = 0 ; col = 0;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 0 ; col = 1;
				moves = false;
				}
				else if(box == 3){
				row = 0 ; col = 2;
				moves = false;
				}
				else if(box == 4){
				row = 1 ; col = 0;
				moves = false;
				}
				else if(box == 5){
				row = 1 ; col = 1;
				moves = false;
				}
				else if(box == 6){
				row = 1 ; col = 2;
				moves = false;
				}
				else if(box == 7){
				row = 2 ; col = 0;
				moves = false;
				}
				else if(box == 8){
				row = 2 ; col = 1;
				moves = false;
				}
				else if(box == 9){
				row = 2 ; col = 2;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				
				}
				
				else if(boardNo == 2){
				
				if(box == 1){
				row = 0 ; col = 3;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 0 ; col = 4;
				moves = false;
				}
				else if(box == 3){
				row = 0 ; col = 5;
				moves = false;
				}
				else if(box == 4){
				row = 1 ; col = 3;
				moves = false;
				}
				else if(box == 5){
				row = 1 ; col = 4;
				moves = false;
				}
				else if(box == 6){
				row = 1 ; col = 5;
				moves = false;
				}
				else if(box == 7){
				row = 2 ; col = 3;
				moves = false;
				}
				else if(box == 8){
				row = 2 ; col = 4;
				moves = false;
				}
				else if(box == 9){
				row = 2 ; col = 5;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				
				}
				
				else if(boardNo == 3){
				
				if(box == 1){
				row = 0 ; col = 6;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 0 ; col = 7;
				moves = false;
				}
				else if(box == 3){
				row = 0 ; col = 8;
				moves = false;
				}
				else if(box == 4){
				row = 1 ; col = 6;
				moves = false;
				}
				else if(box == 5){
				row = 1 ; col = 7;
				moves = false;
				}
				else if(box == 6){
				row = 1 ; col = 8;
				moves = false;
				}
				else if(box == 7){
				row = 2 ; col = 6;
				moves = false;
				}
				else if(box == 8){
				row = 2 ; col = 7;
				moves = false;
				}
				else if(box == 9){
				row = 2 ; col = 8;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 4){
				
				if(box == 1){
				row = 3 ; col = 0;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 3 ; col = 1;
				moves = false;
				}
				else if(box == 3){
				row = 3 ; col = 2;
				moves = false;
				}
				else if(box == 4){
				row = 4 ; col = 0;
				moves = false;
				}
				else if(box == 5){
				row = 4 ; col = 1;
				moves = false;
				}
				else if(box == 6){
				row = 4 ; col = 2;
				moves = false;
				}
				else if(box == 7){
				row = 5 ; col = 0;
				moves = false;
				}
				else if(box == 8){
				row = 5 ; col = 1;
				moves = false;
				}
				else if(box == 9){
				row = 5 ; col = 2;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 5){
				
				if(box == 1){
				row = 3 ; col = 3;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 3 ; col = 4;
				moves = false;
				}
				else if(box == 3){
				row = 3 ; col = 5;
				moves = false;
				}
				else if(box == 4){
				row = 4 ; col = 3;
				moves = false;
				}
				else if(box == 5){
				row = 4 ; col = 4;
				moves = false;
				}
				else if(box == 6){
				row = 4 ; col = 5;
				moves = false;
				}
				else if(box == 7){
				row = 5 ; col = 3;
				moves = false;
				}
				else if(box == 8){
				row = 5 ; col = 4;
				moves = false;
				}
				else if(box == 9){
				row = 5 ; col = 5;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 6){
				
				if(box == 1){
				row = 3 ; col = 6;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 3 ; col = 7;
				moves = false;
				}
				else if(box == 3){
				row = 3 ; col = 8;
				moves = false;
				}
				else if(box == 4){
				row = 4 ; col = 6;
				moves = false;
				}
				else if(box == 5){
				row = 4 ; col = 7;
				moves = false;
				}
				else if(box == 6){
				row = 4 ; col = 8;
				moves = false;
				}
				else if(box == 7){
				row = 5 ; col = 6;
				moves = false;
				}
				else if(box == 8){
				row = 5 ; col = 7;
				moves = false;
				}
				else if(box == 9){
				row = 5 ; col = 8;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 7){
				
				if(box == 1){
				row = 6 ; col = 0;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 6 ; col = 1;
				moves = false;
				}
				else if(box == 3){
				row = 6 ; col = 2;
				moves = false;
				}
				else if(box == 4){
				row = 7 ; col = 0;
				moves = false;
				}
				else if(box == 5){
				row = 7 ; col = 1;
				moves = false;
				}
				else if(box == 6){
				row = 7 ; col = 2;
				moves = false;
				}
				else if(box == 7){
				row = 8 ; col = 0;
				moves = false;
				}
				else if(box == 8){
				row = 8 ; col = 1;
				moves = false;
				}
				else if(box == 9){
				row = 8 ; col = 2;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 8){
				
				if(box == 1){
				row = 6 ; col = 3;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 6 ; col = 4;
				moves = false;
				}
				else if(box == 3){
				row = 6 ; col = 5;
				moves = false;
				}
				else if(box == 4){
				row = 7 ; col = 3;
				moves = false;
				}
				else if(box == 5){
				row = 7 ; col = 4;
				moves = false;
				}
				else if(box == 6){
				row = 7 ; col = 5;
				moves = false;
				}
				else if(box == 7){
				row = 8 ; col = 3;
				moves = false;
				}
				else if(box == 8){
				row = 8 ; col = 4;
				moves = false;
				}
				else if(box == 9){
				row = 8 ; col = 5;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 9){
				
				if(box == 1){
				row = 6 ; col = 6;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 6 ; col = 7;
				moves = false;
				}
				else if(box == 3){
				row = 6 ; col = 8;
				moves = false;
				}
				else if(box == 4){
				row = 7 ; col = 6;
				moves = false;
				}
				else if(box == 5){
				row = 7 ; col = 7;
				moves = false;
				}
				else if(box == 6){
				row = 7 ; col = 8;
				moves = false;
				}
				else if(box == 7){
				row = 8 ; col = 6;
				moves = false;
				}
				else if(box == 8){
				row = 8 ; col = 7;
				moves = false;
				}
				else if(box == 9){
				row = 8 ; col = 8;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
									
		} while(moves);
		
	       	cout << endl;
		
		//   row--;
		//
		//   col--;
		
		}
		
		void getOMove(char playr, int& row, int& col) {
			
				int box , boardNo;
				bool moves = false;
		
		
		do{
		
				cout << "Player " << playr << " Enter Board Number for your move: ";	
				
				cin>> boardNo;
				
				cout << "Player " << playr << " Enter box number in board"<<boardNo<<" for your move: ";
				
				cin >> box;
				if(boardNo == 1){
				
				if(box == 1){
				row = 0 ; col = 0;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 0 ; col = 1;
				moves = false;
				}
				else if(box == 3){
				row = 0 ; col = 2;
				moves = false;
				}
				else if(box == 4){
				row = 1 ; col = 0;
				moves = false;
				}
				else if(box == 5){
				row = 1 ; col = 1;
				moves = false;
				}
				else if(box == 6){
				row = 1 ; col = 2;
				moves = false;
				}
				else if(box == 7){
				row = 2 ; col = 0;
				moves = false;
				}
				else if(box == 8){
				row = 2 ; col = 1;
				moves = false;
				}
				else if(box == 9){
				row = 2 ; col = 2;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				
				}
				
				else if(boardNo == 2){
				
				if(box == 1){
				row = 0 ; col = 3;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 0 ; col = 4;
				moves = false;
				}
				else if(box == 3){
				row = 0 ; col = 5;
				moves = false;
				}
				else if(box == 4){
				row = 1 ; col = 3;
				moves = false;
				}
				else if(box == 5){
				row = 1 ; col = 4;
				moves = false;
				}
				else if(box == 6){
				row = 1 ; col = 5;
				moves = false;
				}
				else if(box == 7){
				row = 2 ; col = 3;
				moves = false;
				}
				else if(box == 8){
				row = 2 ; col = 4;
				moves = false;
				}
				else if(box == 9){
				row = 2 ; col = 5;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				
				}
				
				else if(boardNo == 3){
				
				if(box == 1){
				row = 0 ; col = 6;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 0 ; col = 7;
				moves = false;
				}
				else if(box == 3){
				row = 0 ; col = 8;
				moves = false;
				}
				else if(box == 4){
				row = 1 ; col = 6;
				moves = false;
				}
				else if(box == 5){
				row = 1 ; col = 7;
				moves = false;
				}
				else if(box == 6){
				row = 1 ; col = 8;
				moves = false;
				}
				else if(box == 7){
				row = 2 ; col = 6;
				moves = false;
				}
				else if(box == 8){
				row = 2 ; col = 7;
				moves = false;
				}
				else if(box == 9){
				row = 2 ; col = 8;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 4){
				
				if(box == 1){
				row = 3 ; col = 0;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 3 ; col = 1;
				moves = false;
				}
				else if(box == 3){
				row = 3 ; col = 2;
				moves = false;
				}
				else if(box == 4){
				row = 4 ; col = 0;
				moves = false;
				}
				else if(box == 5){
				row = 4 ; col = 1;
				moves = false;
				}
				else if(box == 6){
				row = 4 ; col = 2;
				moves = false;
				}
				else if(box == 7){
				row = 5 ; col = 0;
				moves = false;
				}
				else if(box == 8){
				row = 5 ; col = 1;
				moves = false;
				}
				else if(box == 9){
				row = 5 ; col = 2;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 5){
				
				if(box == 1){
				row = 3 ; col = 3;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 3 ; col = 4;
				moves = false;
				}
				else if(box == 3){
				row = 3 ; col = 5;
				moves = false;
				}
				else if(box == 4){
				row = 4 ; col = 3;
				moves = false;
				}
				else if(box == 5){
				row = 4 ; col = 4;
				moves = false;
				}
				else if(box == 6){
				row = 4 ; col = 5;
				moves = false;
				}
				else if(box == 7){
				row = 5 ; col = 3;
				moves = false;
				}
				else if(box == 8){
				row = 5 ; col = 4;
				moves = false;
				}
				else if(box == 9){
				row = 5 ; col = 5;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 6){
				
				if(box == 1){
				row = 3 ; col = 6;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 3 ; col = 7;
				moves = false;
				}
				else if(box == 3){
				row = 3 ; col = 8;
				moves = false;
				}
				else if(box == 4){
				row = 4 ; col = 6;
				moves = false;
				}
				else if(box == 5){
				row = 4 ; col = 7;
				moves = false;
				}
				else if(box == 6){
				row = 4 ; col = 8;
				moves = false;
				}
				else if(box == 7){
				row = 5 ; col = 6;
				moves = false;
				}
				else if(box == 8){
				row = 5 ; col = 7;
				moves = false;
				}
				else if(box == 9){
				row = 5 ; col = 8;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 7){
				
				if(box == 1){
				row = 6 ; col = 0;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 6 ; col = 1;
				moves = false;
				}
				else if(box == 3){
				row = 6 ; col = 2;
				moves = false;
				}
				else if(box == 4){
				row = 7 ; col = 0;
				moves = false;
				}
				else if(box == 5){
				row = 7 ; col = 1;
				moves = false;
				}
				else if(box == 6){
				row = 7 ; col = 2;
				moves = false;
				}
				else if(box == 7){
				row = 8 ; col = 0;
				moves = false;
				}
				else if(box == 8){
				row = 8 ; col = 1;
				moves = false;
				}
				else if(box == 9){
				row = 8 ; col = 2;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 8){
				
				if(box == 1){
				row = 6 ; col = 3;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 6 ; col = 4;
				moves = false;
				}
				else if(box == 3){
				row = 6 ; col = 5;
				moves = false;
				}
				else if(box == 4){
				row = 7 ; col = 3;
				moves = false;
				}
				else if(box == 5){
				row = 7 ; col = 4;
				moves = false;
				}
				else if(box == 6){
				row = 7 ; col = 5;
				moves = false;
				}
				else if(box == 7){
				row = 8 ; col = 3;
				moves = false;
				}
				else if(box == 8){
				row = 8 ; col = 4;
				moves = false;
				}
				else if(box == 9){
				row = 8 ; col = 5;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
				}
				
				
				else if(boardNo == 9){
				
				if(box == 1){
				row = 6 ; col = 6;
				moves = false;
				//cout<<"f";
				}
				
				else if(box == 2){
				row = 6 ; col = 7;
				moves = false;
				}
				else if(box == 3){
				row = 6 ; col = 8;
				moves = false;
				}
				else if(box == 4){
				row = 7 ; col = 6;
				moves = false;
				}
				else if(box == 5){
				row = 7 ; col = 7;
				moves = false;
				}
				else if(box == 6){
				row = 7 ; col = 8;
				moves = false;
				}
				else if(box == 7){
				row = 8 ; col = 6;
				moves = false;
				}
				else if(box == 8){
				row = 8 ; col = 7;
				moves = false;
				}
				else if(box == 9){
				row = 8 ; col = 8;
				moves = false;
				}
				else {
				cout<<endl<<"INVALID MOVE !!!! TRY AGAIN...\n\n";
				moves = true;
				}
					}
		}
		while(moves);
		
		cout << endl;
			
		} 

};

int main() {

// creating game of type TicTacToe

		Game game; // object
		
		game.play();
		
		return 0;

}
