#include<iostream>
using namespace std;

int main(){

    int board[8][8]={0}, row, column=0; //Setting up the chess board
    int counter=0; // Set up counter for different moves for 8*8 queen

    board[0][0]=1;  // Setting (0,0) to 1 to represent the queen

    NC: column++;  //Enter Next Column
        if(column == 8)
            goto print;
            row = -1;

    NR: row++;
        if(row == 8)
            goto backTrack;

        for(int i=0; i<column; i++)  //Row test
            if(board[row][i] == 1)
            goto NR;

        for(int i=1; (row-i)>-1 && (column-i)>-1; i++) //Up Diagonal Test
            if(board[row-i][column-i] == 1)
            goto NR;

        for(int i=1; (row+i)<8 && (column-i)>-1; i++)  //Down Diagonal Test
            if(board[row+i][column-i] == 1)
            goto NR;

        board[row][column]=1;
            goto NC;

    backTrack: column--;
        if(column == -1)
            return 0;

        row=0;
        while(board[row][column] != 1)
        row++;

        board[row][column]=0;
        goto NR;

    print:
        counter++;
        cout<<"Solution #"<<counter << endl;

        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
            cout<<board[i][j] << " ";
            }
            cout<<endl;
        }
        cout << endl;
        goto backTrack;

	return 0;
}
