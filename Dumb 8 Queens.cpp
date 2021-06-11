#include <iostream>
using namespace std;

bool ok(int board[8]){

	for(int c=7; c>0; c--){ //Get the values for Rows
		int r=0;
		r=board[c];

		for(int i=1; i<=c; i++){ //Row test
			if(board[c-i] == r)
				return false;

			else if(board[c-i] == r-i) //Up diagonal test
				return false;

			else if(board[c-i] == r+i) //Down diagonal test
				return false;								
		}		        
	}
	return true;
}

void print(int board[8], int counter){

	cout <<"Solution #"<< counter << endl;

	int b[8][8]={0};

	for(int i=0; i<8; i++){
		b[board[i]][i]=1;
	}

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<b[i][j]<< " ";
		}
		cout<<endl;
	}

	cout << endl;
}

int main (){

	int board[8]={0};
	int counter = 0;

	for(int i0 = 0; i0 < 8; i0++)

		for(int i1=0; i1 < 8; i1++)

			for(int i2 = 0; i2 < 8; i2++)

				for(int i3 = 0; i3 < 8; i3++)

				for(int i4 = 0; i4 < 8; i4++)

			for(int i5 = 0; i5 < 8; i5++)

		for(int i6 = 0; i6 < 8; i6++)
					
	for(int i7 = 0; i7 < 8; i7++){
		board[0]=i0;
		board[1]=i1;
		board[2]=i2;
		board[3]=i3;
		board[4]=i4;																
		board[5]=i5;																
		board[6]=i6;																
		board[7]=i7;
		
		if(ok(board))print(board, ++counter);
		
		board[0]=-1;			
		board[1]=-1;																
		board[2]=-1;															        
		board[3]=-1;																
		board[4]=-1;																
		board[5]=-1;																
		board[6]=-1;
		board[7]=-1;	
		
		}
	return 0;
}
