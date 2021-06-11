#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> tower[3];
    int rings;
    cout << "Enter The Number of Rings: ";
    cin >> rings;
    cout << endl;

    int close = (rings % 2 == 0 ? 2 : 1);
    int far = (rings % 2 == 0 ? 1 : 2);
    int from = 0, to = close, candidate = 1, move = 0;

    for(int i = rings + 1; i >= 1; --i)
    tower[0].push_back(i);
    tower[1].push_back(rings+1);
    tower[2].push_back(rings+1);

    while (tower[1].size() < rings+1) {
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

        tower[to].push_back(tower[from].back());
        tower[from].pop_back();

        if (tower[(to+1) % 3].back() < tower[(to+2) % 3].back())
            from = (to+1) % 3;
        else
            from = (to+2) % 3;
        candidate = tower[from].back();                      

        if (tower[(from+close) % 3].back() > candidate) 
            to = (from+close) % 3;                
        else
            to = (from+far) % 3;
    }
    return 0;
}