//https://dmoj.ca/problem/ccc16j2
#include <bits/stdc++.h>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int ar[4][4],tot=0,row;
    for (int i=0;i<4;i++) {
        tot=0;
        for (int j=0;j<4;j++) {
            cin >> ar[i][j];
            tot+=ar[i][j];
        }
        if (i==0) {
            row=tot;
        }
        else {
            if (row!=tot) {
                cout << "not magic" << endl;
                return 0;
            }
        }
    }
    tot=0;
    for (int i=0;i<4;i++) {
        tot=0;
        for (int j=0;j<4;j++) {
            tot+=ar[j][i];
        }
        if (tot!=row) {
            cout << "not magic" << endl;
            return 0;
        }
    }
    cout << "magic" << endl;

    return 0;
 }
