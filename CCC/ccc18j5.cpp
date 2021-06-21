#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
bool visited[100050];
vector<vector<int>>adj(10050);
void bfs (int n) {
priority_queue<pii,vector<pii>,greater<pii>>pq;
pq.push(make_pair(1,1));
int page,dist,smallest=INT_MAX;
while (!pq.empty()) {
    dist=pq.top().first;
    page=pq.top().second;
    if (adj[page].empty()) {
        smallest=min(smallest,dist);
    }
    pq.pop();
    if (visited[page]) continue;
    visited[page]=1;
    for (int i=0;i<adj[page].size();i++) {
        pq.push(make_pair(dist+1,adj[page][i]));
    }
}
for (int i=1;i<=n;i++) {
    if (!visited[i]) {
        cout << "N" << endl;
        break;
    }
    else if (i==n) {
        cout << "Y" <<endl;
    }
}
cout << smallest << endl;
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,n;
    cin >> n;

    for (int i=0;i<n;i++) {
        cin >> a;
        for (int j=0;j<a;j++) {
            cin >> b;
            adj[i+1].push_back(b);
        }
    }
    bfs(n);
    return 0;
 }