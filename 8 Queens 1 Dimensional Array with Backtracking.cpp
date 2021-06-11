#include<iostream>
using namespace std;

int main(){

    int q[8], c = 0, counter=1;
        q[0] = 0;

NC:
    c++;
    if(c == 8)
        goto Print;
    q[c] = -1;

NR:
    q[c]++;
    if (q[c] == 8) goto BackTrack;
    for(int i = 0; i < c; i++){
        if(q[c] == q[i] || (c - i) == abs(q[c] - q[i]))
            goto NR;
    }
    goto NC;

BackTrack:
    c--;
    if(c == -1) return 0;
    goto NR;

Print:

    int Board[8][8]={0};
    for(int i = 0; i <= 7; i++){
            q[i];
            int a=q[i];
            Board[a][i]=1;
    }
    cout<< "Solution #"<< counter++ <<endl<<endl;

    for(int j=0;j<=7;j+=1){
       for(int k=0;k<=7;k++){
          cout<<Board[j][k] << " ";
      }
       cout<<endl;
    }
    cout << endl;

    goto BackTrack;

    return 0;
}

