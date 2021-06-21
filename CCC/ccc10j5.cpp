#include <bits/stdc++.h>
using namespace std;
bool visited[100][100];
int moves[8]={-1,-1,-2,-2,1,1,2,2},moves2[8]={2,-2,1,-1,2,-2,1,-1};
void bfs (int a,int b,int c,int d) {
queue<pair<pair<int,int>,int>>q;
q.push(make_pair(make_pair(a,b),0));
int x,y,dist;

while (!q.empty()) {
    x=q.front().first.first;
    y=q.front().first.second;
    dist=q.front().second;
    q.pop();
    if (x==c && y==d) {
        cout << dist << endl;
        return;
    }
    if (visited[x][y] || x>8 || y>8 || x<=0 || y<=0) {
        continue;
    }
    visited[x][y]=1;
    for (int i=0;i<8;i++) {
        q.push(make_pair(make_pair(x+moves[i],y+moves2[i]),dist+1));

    }
}
return;



}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c,d;
    cin >> a >> b>>c>>d;
    bfs(a,b,c,d);
    return 0;
 }