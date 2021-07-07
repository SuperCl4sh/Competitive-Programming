//https://dmoj.ca/problem/ccc20s2
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> ar(1000010);
bool bfs (int m,int n) {
bool visited[1010][1010];
queue<pair<int,int>>q;
q.push(make_pair(m,n));
pair<int,int>b;
pair<int,int>x;
int g;
while (!q.empty()) {
    b=q.front();
    q.pop();
    visited[b.first][b.second]=1;
    for (auto x: ar[b.first*b.second]) {
        if (x.first==1 && x.second==1) {
            return true;
        }
        else if (!visited[x.first][x.second]) {
            q.push(make_pair(x.first,x.second));
        }
    }
}
return false;
}
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,val,x,y;
cin >> m >> n;
for (int i=1;i<=m;i++) {
    for (int j=1;j<=n;j++) {
        cin >> val;
        ar[val].push_back(make_pair(i,j));
    }
}
if (bfs(m,n)) {
    cout << "yes" << endl;
}
else {
    cout << "no" << endl;
}
return 0;
}

