#include <iostream>
using namespace std;

bool ok(int q[], int c) {

   int board[8][5] = { // helper Array
   {-1},
   {0, -1},
   {0, 1, -1},
   {0, 2, -1},
   {1, 2, -1},
   {1, 2, 3, 4, -1},
   {2, 3, 5, -1},
   {4, 5, 6, -1}
   };

   for(int i = 0; i < c; i++){
        if(q[c] == q[i])
            return false;
   }

   for(int i = 0; board[c][i]!=-1; i++){
        if(q[board[c][i]]+1 == q[c] || q[board[c][i]]-1 == q[c])
            return false;
   }
   return true;
}

void print(int q[]) {

   static int solution = 1;

   cout << "Solution #" << solution << ":" << endl;
   cout << "  " << q[1] <<"  " << q[4] << endl;
   cout << q[0] << " " << q[2] << "  "<< q[5] << " " << q[7] << endl;
   cout << "  " << q[3] << "  " << q[6] << endl;

   cout << endl;
   solution++;
}

void next(int q[], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 1; q[c] < 9; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() {

   int q[8];
   
   next(q, 0);
   
   return 0;
}