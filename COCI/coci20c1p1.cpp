#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
vector<str>grid;
str ans=":(",g;int k=0;
vector<int>finalans(4);
void solve (int x, int y,int dist) {
if (x>=grid.size()||y>=g.length()||y<0||x<0||grid[x][y]=='.'||grid[x][y]=='o') {
    return;
}
if (grid[x][y]=='x') {
    ans=":)";
    finalans[k]=dist;
    return;
}

if (grid[x][y]=='>') {
    solve(x,y+1,dist+1);
}
else if (grid[x][y]=='v') {
    solve(x+1,y,dist+1);
}
else if (grid[x][y]=='<') {
    solve(x,y-1,dist+1);
}
else if (grid[x][y]=='^') {
    solve(x-1,y,dist+1);
}
else {
    return;
}

return;
}

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int r,s,x,y;

    cin >> r >> s;
    for (int i=0;i<r;i++) {
        cin >> g;
        grid.push_back(g);
        for (int j=0;j<g.length();j++) {
            if (g[j]=='o') {
                x=i;y=j;
            }
        }
    }
    for (int i=0;i<4;i++) {
        finalans[i]=INT_MAX ;
    }
    solve(x,y+1,0);
    k++;
    solve(x-1,y,0);
    k++;
    solve(x+1,y,0);
    k++;
    solve(x,y-1,0);

    if (ans==":(") {
        cout << ans << endl;
    }
    else {
        cout << ans << endl;
        int index=0;
        for (int j=0;j<4;j++) {
            if (finalans[j]<finalans[index]) {
                index=j;
            }
        }
        if (index==0) {
            cout << 'E' << endl;
        }
        else if (index==1) {
            cout << 'N' << endl;
        }
        else if (index==2) {
            cout << 'S' << endl;
        }
        else if (index==3) {
            cout << 'W' << endl;
        }
        }

    return 0;
 }