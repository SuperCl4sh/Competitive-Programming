//https://dmoj.ca/problem/coci06c1p4
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int sx,sy,r,c;str s;
vector<vector<char>>grid;
bool visited[5000][5000];
void bfs () {
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
pq.push(make_pair(0,make_pair(sx,sy)));
ll x,y,dist,carryDist=0;
while (!pq.empty()) {
x=pq.top().second.first;
y=pq.top().second.second;
dist=pq.top().first;
pq.pop();
if (carryDist!=dist) {
    for (int f=0;f<r;f++) {
        for (int g=0;g<c;g++) {
            if (grid[f][g]!='X'&&grid[f][g]!='D'&&grid[f][g]!='S'&&grid[f][g]!='*'&&grid[f][g]!='1') {
            if (f>0) {
                if (grid[f-1][g]=='*') {
                    grid[f][g]='1';
                }
            }
            if (f+1<r) {
                if (grid[f+1][g]=='*') {
                    grid[f][g]='1';
                }
            }
            if (g>0) {
                if (grid[f][g-1]=='*') {
                    grid[f][g]='1';
                }
            }
            if (g+1<c) {
                if (grid[f][g+1]=='*') {
                    grid[f][g]='1';
                }
            }
            }
        }

    }
    for (int v=0;v<grid.size();v++) {
        for (int d=0;d<grid[v].size();d++) {
            if (grid[v][d]=='1') {
                grid[v][d]='*';
            }
        }
    }
    carryDist=dist;

}
if (x>=r||y>=c||x<0||y<0||grid[x][y]=='X'||grid[x][y]=='*'||visited[x][y]) {
    continue;
}
if (grid[x][y]=='D') {
    cout << dist << endl;
    return;
}
visited[x][y]=1;
pq.push(make_pair(dist+1,make_pair(x-1,y)));
pq.push(make_pair(dist+1,make_pair(x+1,y)));
pq.push(make_pair(dist+1,make_pair(x,y-1)));
pq.push(make_pair(dist+1,make_pair(x,y+1)));
}
cout << "KAKTUS" << endl;
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    char d;
    cin >> r >> c;
    vector<char>ar;
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cin >> d;
            if (d=='S') {
                sx=i;sy=j;
            }
            ar.push_back(d);
        }
        grid.push_back(ar);
        ar.clear();
    }
    bfs();

    return 0;
 }
