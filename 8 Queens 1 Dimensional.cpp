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
    if(column==-1) exit(1);
}

void Print(int q[]){

    static int counter = 0;
    counter++;

    int board[8][8]={0};
    cout<<"Solution #"<<counter<<endl;

    for(int i=0; i<8; i++){
         board[q[i]][i]=1;
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            cout<<board[i][j]<<" ";
            cout<<endl;
    }
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

     Print(q);

     Backtrack(c);
     _backtrack=true;
    }
}