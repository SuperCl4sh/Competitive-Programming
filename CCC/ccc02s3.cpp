#include <bits/stdc++.h>
using namespace std;
vector<vector<char>>ar;
vector<char>moves;
vector<vector<char>>field;
vector<pair<int,int>>ans;
void solve (int direction,int r, int c) {
for (int q=0;q<moves.size();q++) {

    if (moves[q]=='L') {
        direction-=90;
        if (direction<0) {
            direction=270;
        }
    }
    else if (moves[q]=='R') {
        direction+=90;
        direction%=360;
    }
    else {
        if (direction==0) {
            r--;
        }
        else if (direction==90) {
            c++;
        }
        else if (direction==180) {
            r++;
        }
        else if (direction==270) {
            c--;
        }
    }
    if (c<ar[0].size() && r<ar.size()) {
        if (ar[r][c]=='X') {
            return;
        }
    }
    else {
        return;
    }
}
field[r][c]='*';

return;


}

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b;char s,g;
    vector<char>rows;
    cin >> a >> b;
    for (int i=0;i<a;i++) {
        for (int j=0;j<b;j++) {
            cin >> s;
            rows.push_back(s);
    }
        field.push_back(rows);
        ar.push_back(rows);
        rows.clear();
    }
    int t;
    cin >>t;
    for (int i=0;i<t;i++) {
        cin >> g;
        moves.push_back(g);
    }
    for (int v=0;v<a;v++) {
        for (int r=0;r<b;r++) {
            if (ar[v][r]!='X') {
            solve(0,v,r);
            solve(90,v,r);
            solve(180,v,r);
            solve(270,v,r);
            }
        }
    }
    for (int w=0;w<a;w++) {
        for (int p=0;p<b;p++) {
            cout << field[w][p];
        }
        cout << endl;
    }

    return 0;
 }