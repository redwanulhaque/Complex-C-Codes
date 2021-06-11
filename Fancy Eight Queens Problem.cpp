#include<iostream>
using namespace std;

bool ok(int q[], int column){

    for(int i=0; i<column; i++){
        if((q[i] == q[column]) || (abs(q[column] - q[i]) == (column - i)))
            return false;
    }
    return true;
}

void Backtrack(int &column){
    column--;
    if(column == -1) exit(1);
}

void print(int q[]) {

    static int counter =1;
    cout<< endl << "Solution #" << counter++ << endl;

    int i, j, k, l;
    typedef char box[5][7];
    box bb,wb,*board[8][8];
    char ws = char(219);  // char 219 is black box

    box bq = {  // Crown for black boxes
        ws, ws, ws, ws, ws, ws, ws,
        ws, ' ', ws, ' ', ws, ' ', ws,
        ws, ' ', ' ', ' ', ' ', ' ', ws,
        ws, ' ', ' ', ' ', ' ', ' ', ws,
        ws, ws, ws, ws, ws, ws, ws
    };

    box wq = {  // Crown for white boxes
        ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ws, ' ', ws, ' ', ws, ' ',
        ' ', ws, ws, ws, ws, ws, ' ',
        ' ', ws, ws, ws, ws, ws, ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };

    for(i=0; i<5; i++)  //create the black boxes
        for(j=0; j<7; j++){
            wb[i][j] = ' ';
            bb[i][j] = char(219);
    }

    for(i=0; i<8 ;i++)
        for(j=0; j<8; j++)
            if((i+j) % 2 == 0) {
                if(q[i] == j) {
                    board[i][j] = &wq;
                        } else { board[i][j] = &wb;}}

                    else {
                        if(q[i] == j){
                            board[i][j] = &bq;}
                        else {
                            board[i][j] = &bb;}
    }

    cout << " ";
    for(i=0; i<7*8; i++)  // Upper Border
        cout << '_';
        cout << endl;

    for(i=0; i<8; i++) // Printing board
        for(k=0; k<5; k++){
            cout << " " << char(179); //Left border

                for(j=0; j<8; j++)
                    for(l=0; l<7; l++)
                        cout << (*board[i][j])[k][l];
                            cout << char(179) << endl;
    }

    cout << " ";
    for(i=0; i<7*8; i++)  // Lower Border
        cout << char(196);
        cout << endl;
}

int main(){

    int q[8]; q[0]=0;
    int c=1;

    bool _backtrack=false;

    while(1){

        while(c<8){
            if(!_backtrack)
                q[c]=-1;
                _backtrack=false;

                while(q[c]<8){
                    q[c]++;

                while(q[c]==8){
                    Backtrack(c);
                    q[c]++;}

                if(ok(q, c))
                    break;
        }
        c++;
     }

     print(q);
     Backtrack(c);
     _backtrack=true;

    }

    return 0;
}